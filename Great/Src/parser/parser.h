#ifndef PARSER_H
#define PARSER_H

#include <datastructures/queueLL/queuell.h>
#include "parseResult/parseResult.h"
#include "node/node.h"

typedef struct Parser Parser;

Parser *parser_create(Queue *tokens);
void parser_advance(Parser *this);
ParseResult *parser_parse(Parser *this);
ParseResult *parser_atom(Parser *this);
ParseResult *parser_factor(Parser *this);
ParseResult *parser_divide(Parser *this);
ParseResult *parser_mul(Parser *this);
ParseResult *parser_add(Parser *this);
ParseResult *parser_sub(Parser *this);
ParseResult *parser_binaryOperation(Parser *this,
                                    ParseResult *(*function1)(Parser *this),
                                    String *operators[],
                                    int operatorsLen);
ParseResult *parser_binaryOperationDiff(Parser *this,
                                        ParseResult *(*function1)(Parser *this),
                                        ParseResult *(*function2)(Parser *this),
                                        String *operators[],
                                        int operatorsLen);

#endif
