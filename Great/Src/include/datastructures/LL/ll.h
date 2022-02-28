#ifndef LL_H
#define LL_H

#include <datastructures/node/node.h>

typedef struct Linkedlist Linkedlist;

Linkedlist *ll_create();
void ll_push_back(Linkedlist *this, void *data);
void ll_remove(Linkedlist *this, void *data);

#endif