#include <datastructures/queueLL/queuell.h>
#include <memory/allocs.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *frt;
    Node *rear;
    int len;
} Queue;

Queue *queue_create()
{
    Queue *queue = allocate(sizeof(Queue));
    queue->frt = queue->rear = NULL;
    queue->len = 0;
    return queue;
}

void queue_enqueue(Queue *this, void *data)
{
    this->len += 1;
    if (this->frt == NULL)
    {
        this->frt = this->rear = node_create(data);
        return;
    }
    this->rear = node_add(data, this->rear);
}

void *queue_dequeue(Queue *this)
{
    if (this->frt == NULL)
        return NULL;
    this->len -= 1;
    void *frt;
    if (this->frt == this->rear)
    {
        frt = node_delete(this->frt);
        this->frt = this->rear = NULL;
    }
    else
    {
        Node *next = this->frt->next;
        frt = node_delete(this->frt);
        this->frt = next;
    }
    return frt;
}