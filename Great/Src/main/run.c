#include "run.h"

#include <io/io.h>

#include "../error/error.h"

#include "../tokenizer/tokenizer.h"
#include "../parser/parser.h"
#include "../visitor/visitor.h"

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *frt;
    Node *rear;
    int len;
} Queue;

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

void runfromstring(String *code)
{
    Tokenizer *tokenizer = t_create(code);
    Queue *tokens = t_split(tokenizer);

    // TODO CONSTANT STRINGS
    Node *c = tokens->frt;
    while (c != NULL)
    {
        Token *token = (Token *)c->data;
        if (str_equals(token->type, string("ERROR")))
        {
            Error *err = error_create(token->position, string("Illegal Character Error"), token->value);
            puts(error_as_string(err)->str);
            printf("\n");
            return;
        }
        printf("[%s: '%s']\n", token->type->str, token->value->str);
        c = c->next;
    }

    Parser *parser = parser_create(tokens);
    ParseResult *parseResult = parser_parse(parser);
    if (parseResult->error != NULL)
    {
        puts(node_as_string(parseResult->error)->str);
        printf("\n");
        return;
    }
    puts(node_as_string(parseResult->result)->str);
    printf("\n");
}

void runfromshell()
{
    printf("Great version %s\n", VERSION);
    while (true)
    {
        printf(">>> ");
        String *code = input_string();
        if (str_equals(code, string("exit")))
            break;
        runfromstring(code);
    }
}

void runfromfile()
{
}
