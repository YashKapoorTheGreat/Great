#include "parseResult.h"

typedef struct ParseResult
{
    Node *result;
    Node *error;
} ParseResult;

ParseResult *parse_result_create()
{
    ParseResult *this = allocate(sizeof(ParseResult));
    this->result = NULL;
    this->error = NULL;
    return this;
}

Node *parse_result_register(ParseResult *this, ParseResult *result)
{
    if (result->error != NULL)
        this->error = result->error;

    return result->result;
}

void parse_result_success(ParseResult *this, Node *node)
{
    this->result = node;
}

void parse_result_error(ParseResult *this, Node *error)
{
    this->error = error;
}
