#include <memory/allocs.h>
#include <datastructures/node/node.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

Node *node_create(void *data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *node_add(void *data, Node *prev)
{
    Node *node = node_create(data);
    prev->next = node;
    return node;
}

void *node_delete(Node *this)
{
    if (this == NULL)
    {
        return NULL;
    }

    void *data = this->data;
    free(this);
    return data;
}
