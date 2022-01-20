#ifndef QUEUELL_NODE_H
#define QUEUELL_NODE_H

typedef struct node
{
    void *data;
    struct node *next;
} Node;

Node *node_create(void *data);
Node *node_add(void *data, Node *prev);
void *node_delete(Node *this);

#endif
