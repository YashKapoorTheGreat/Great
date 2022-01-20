#ifndef QUEUELL_H
#define QUEUELL_H

#include <datastructures\queueLL\node.h>

typedef struct queue
{
    Node *frt;
    Node *rear;
    int len;
    void (*enqueue)(struct queue *this, void *data);
    void *(*dequeue)(struct queue *this);
} Queue;

Queue *queue_create();
void queue_enqueue(Queue *this, void *data);
void *queue_dequeue(Queue *this);

#endif
