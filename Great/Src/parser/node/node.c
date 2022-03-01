#include "node.h"
#include "../error/error.h"

typedef struct Token
{
    String *type;
    String *value;
    Position position;
} Token;

typedef struct Node
{
    Position position;
    void *data;
    NodeType type;
} Node;

typedef struct NumberNode
{
    Token *number;
} NumberNode;

typedef struct ErrorNode
{
    String *description;
} ErrorNode;

typedef struct MonoOperationNode
{
    Node *oprand;
    Token *operator;
} MonoOperationNode;

typedef struct BinaryOperationNode
{
    Node *leftOprand, *rightOprand;
    Token *operator;
} BinaryOperationNode;

Node *base_node_create(void *data, Position position, NodeType type)
{
    Node *node = allocate(sizeof(Node));
    node->position = position;
    node->data = data;
    node->type = type;
    return node;
}

Node *error_node_create(String *description, Position position)
{
    ErrorNode *node = allocate(sizeof(ErrorNode));
    node->description = description;
    return base_node_create(node, position, TYPE_ErrorNode);
}

Node *number_node_create(Token *number)
{
    Position position = number->position;
    NumberNode *node = allocate(sizeof(NumberNode));
    node->number = number;
    return base_node_create(node, position, TYPE_NumberNode);
}

Node *mono_operation_node_create(Node *oprand, Token *operator)
{
    Position position = position_create(operator->position.col_start,
                                        oprand->position.col_end,
                                        operator->position.line_num,
                                        operator->position.file_name,
                                        operator->position.line);
    MonoOperationNode *node = allocate(sizeof(MonoOperationNode));
    node->oprand = oprand;
    node->operator= operator;
    return base_node_create(node, position, TYPE_MonoOperationNode);
}

Node *binary_operation_node_create(Node *leftOprand, Node *rightOprand, Token *operator)
{
    Position position = position_create(leftOprand->position.col_start,
                                        rightOprand->position.col_end,
                                        operator->position.line_num,
                                        operator->position.file_name,
                                        operator->position.line);
    BinaryOperationNode *node = allocate(sizeof(BinaryOperationNode));
    node->leftOprand = leftOprand;
    node->rightOprand = rightOprand;
    node->operator= operator;
    return base_node_create(node, position, TYPE_BinaryOperationNode);
}

String *error_node_as_string(Node *node)
{
    ErrorNode *errorNode = (ErrorNode *)node->data;
    return error_as_string(error_create(node->position, string("Syntax Error"), errorNode->description));
}

String *number_node_as_string(Node *node)
{
    NumberNode *numberNode = (NumberNode *)node->data;
    String *str = string("<Number ");
    str = str_concatinate(str, numberNode->number->value);
    str = str_concatinate(str, string(">"));
    return str;
}

String *binary_operation_node_as_string(Node *node)
{
    BinaryOperationNode *binaryOperationNode = (BinaryOperationNode *)node->data;
    String *str = string("<Binary Operation [");
    str = str_concatinate(str, node_as_string(binaryOperationNode->leftOprand));
    str = str_concatinate(str, string(" "));
    str = str_concatinate(str, binaryOperationNode->operator->value);
    str = str_concatinate(str, string(" "));
    str = str_concatinate(str, node_as_string(binaryOperationNode->rightOprand));
    str = str_concatinate(str, string("]>"));
    return str;
}

String *mono_operation_node_as_string(Node *node)
{
    MonoOperationNode *monoOperationNode = (MonoOperationNode *)node->data;
    String *str = string("<Mono Operation [");
    str = str_concatinate(str, monoOperationNode->operator->value);
    str = str_concatinate(str, string(" "));
    str = str_concatinate(str, node_as_string(monoOperationNode->oprand));
    str = str_concatinate(str, string("]>"));
    return str;
}

String *node_as_string(Node *node)
{
    String *str;
    switch (node->type)
    {
    case TYPE_ErrorNode:
        str = error_node_as_string(node);
        break;
    case TYPE_NumberNode:
        str = number_node_as_string(node);
        break;
    case TYPE_BinaryOperationNode:
        str = binary_operation_node_as_string(node);
        break;
    case TYPE_MonoOperationNode:
        str = mono_operation_node_as_string(node);
        break;
    }
    return str;
}
