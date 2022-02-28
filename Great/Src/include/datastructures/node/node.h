#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

Node *node_create(void *data);
Node *node_add(void *data, Node *prev);
void *node_delete(Node *this);

#endif
