#ifndef PARSERESULT_H
#define PARSERESULT_H

#include "../node/node.h"

typedef struct ParseResult ParseResult;

ParseResult *parse_result_create();
Node *parse_result_register(ParseResult *this, ParseResult *result);
void parse_result_success(ParseResult *this, Node *node);
void parse_result_error(ParseResult *this, Node *error);

#endif
