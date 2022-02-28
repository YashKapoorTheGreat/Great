#include "token.h"

typedef struct Token
{
    String *type;
    String *value;
    Position position;
} Token;

Token *token_create(String *type, String *value, Position pos)
{
    Token *token = allocate(sizeof(Token));
    token->type = type;
    token->value = value;
    token->position = pos;
    return token;
}