#include "parser.h"

typedef struct String
{
    char *str;
    int len;
} String;

typedef struct Token
{
    String *type;
    String *value;
    Position position;
} Token;

typedef struct ParseResult
{
    Node *result;
    Node *error;
} ParseResult;

typedef struct Parser
{
    Queue *codeToParse;
    Token *currentToken;
} Parser;

Parser *parser_create(Queue *tokens)
{
    Parser *parser = allocate(sizeof(Parser));
    parser->codeToParse = tokens;
    parser_advance(parser);
    return parser;
}

void parser_advance(Parser *this)
{
    if (this->currentToken != NULL && str_equals(this->currentToken->type, string("EOF")))
        return;

    this->currentToken = queue_dequeue(this->codeToParse);
}

ParseResult *parser_parse(Parser *this)
{
    ParseResult *result = parser_sub(this);
    if (!str_equals(this->currentToken->type, string("EOF")) && result->error == NULL)
        parse_result_error(result, error_node_create(string("Invalid Syntax"), this->currentToken->position));
    return result;
}
ParseResult *parser_atom(Parser *this)
{
    ParseResult *result = parse_result_create();
    if (str_equals(this->currentToken->type, string("NUMBER")))
    {
        Node *node = number_node_create(this->currentToken);
        parse_result_success(result, node);
        parser_advance(this);
    }
    else
    {
        parse_result_error(result, error_node_create(string("Invalid Syntax"), this->currentToken->position));
    }
    return result;
}
ParseResult *parser_factor(Parser *this)
{
    String *operators[] = {string("^"), string("~")};
    return parser_binaryOperationDiff(this, parser_atom, parser_factor, operators, 2);
}
ParseResult *parser_divide(Parser *this)
{
    String *operators[] = {string("/")};
    return parser_binaryOperation(this, parser_factor, operators, 1);
}
ParseResult *parser_mul(Parser *this)
{
    String *operators[] = {string("*")};
    return parser_binaryOperation(this, parser_divide, operators, 1);
}
ParseResult *parser_add(Parser *this)
{
    String *operators[] = {string("+")};
    return parser_binaryOperation(this, parser_mul, operators, 1);
}
ParseResult *parser_sub(Parser *this)
{
    String *operators[] = {string("-")};
    return parser_binaryOperation(this, parser_add, operators, 1);
}
ParseResult *parser_binaryOperation(Parser *this,
                                    ParseResult *(*function1)(Parser *this),
                                    String *operators[],
                                    int operatorsLen)
{
    return parser_binaryOperationDiff(this, function1, function1, operators, operatorsLen);
}
ParseResult *parser_binaryOperationDiff(Parser *this,
                                        ParseResult *(*function1)(Parser *this),
                                        ParseResult *(*function2)(Parser *this),
                                        String *operators[],
                                        int operatorsLen)
{
    ParseResult *result = parse_result_create();
    Node *left = parse_result_register(result, function1(this));
    if (result->error)
        return result;
    while (string_in_array(this->currentToken->value, operators, operatorsLen))
    {
        Token *operator= this->currentToken;
        parser_advance(this);
        Node *right = parse_result_register(result, function2(this));
        if (result->error)
            return result;
        left = binary_operation_node_create(left, right, operator);
    }
    parse_result_success(result, left);
    return result;
}
