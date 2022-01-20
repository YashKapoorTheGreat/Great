#include <datastructures\queueLL\queuell.h>
#include <memory\allocs.h>

Queue *queue_create()
{
    Queue *queue = allocate(sizeof(Queue));
    queue->frt = queue->rear = NULL;
    queue->len = 0;
    queue->push = queue_push;
    queue->pop = queue_pop;
}

void queue_push(Queue *this, void *data)
{
    this->len += 1;
    if (this->frt == NULL)
    {
        this->frt = this->rear = node_create(data);
        return;
    }
    this->rear = node_add(data, this->rear);
}

void *queue_pop(Queue *this)
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