#ifndef QUEUELL_H
#define QUEUELL_H

#include <datastructures\queueLL\node.h>

typedef struct queue
{
    Node *frt;
    Node *rear;
    int len;
    void (*push)(struct queue *this, void *data);
    void *(*pop)(struct queue *this);
} Queue;

Queue *queue_create();
void queue_push(Queue *this, void *data);
void *queue_pop(Queue *this);

#endif
