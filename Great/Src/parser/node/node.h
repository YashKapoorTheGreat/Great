#ifndef PARSERNODE_H
#define PARSERNODE_H

#include "../tokenizer/token/token.h"
#include "nodeType/nodeType.h"
#include <stdio.h>

typedef struct Node Node;
typedef struct ErrorNode ErrorNode;
typedef struct NumberNode NumberNode;
typedef struct MonoOperationNode MonoOperationNode;
typedef struct BinaryOperationNode BinaryOperationNode;

String *node_as_string(Node *node);

Node *error_node_create(String *description, Position position);

Node *number_node_create(Token *number);
Node *mono_operation_node_create(Node *oprand, Token *operator);
Node *binary_operation_node_create(Node *leftOprand, Node *rightOprand, Token *operator);

#endif
