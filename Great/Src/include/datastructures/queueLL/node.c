#include <memory\allocs.h>
#include <datastructures\queueLL\node.h>

Node *node_create(void *data)
{
    Node *node = allocate(sizeof(Node));
    node->data = data;
    return node;
}

Node *node_add(void *data, Node *prev)
{
    Node *node = allocate(sizeof(Node));
    prev->next = node;
    node->data = data;
    return node;
}

void *node_delete(Node *this)
{
    void *data = this->data;
    deallocate(this);
    return data;
}
