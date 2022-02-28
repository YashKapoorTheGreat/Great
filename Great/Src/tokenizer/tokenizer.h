#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <datastructures/queueLL/queuell.h>
#include "../position/position.h"
#include <constants/constants.h>
#include "token/token.h"

typedef struct Tokenizer Tokenizer;

Tokenizer *t_create(String *code);
void t_advance(Tokenizer *this);
Queue *t_split(Tokenizer *this);
_Bool charinarray(char chr, char array[], int arrlen);

#endif