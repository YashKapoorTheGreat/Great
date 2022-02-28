#ifndef TOKEN_H
#define TOKEN_H

#include "../position/position.h"

typedef struct Token Token;

Token *token_create(String *type, String *value, Position pos);

#endif