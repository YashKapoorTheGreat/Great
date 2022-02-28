#ifndef QUEUELL_H
#define QUEUELL_H

#include <datastructures/node/node.h>

typedef struct Queue Queue;

Queue *queue_create();
void queue_enqueue(Queue *this, void *data);
void *queue_dequeue(Queue *this);

#endif
