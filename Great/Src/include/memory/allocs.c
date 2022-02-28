#include <datastructures/LL/ll.h>
#include <memory/allocs.h>
#include <stdio.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Linkedlist
{
    Node *head;
    Node *tail;
    int len;
} Linkedlist;

Linkedlist *ll;

void initAllocs()
{
    ll = malloc(sizeof(Linkedlist));
    ll->head = ll->tail = NULL;
    ll->len = 0;
}

void *allocate(size_t num_bytes)
{
    void *allocatedMemoryPtr = malloc(num_bytes);
    memset(allocatedMemoryPtr, 0, num_bytes);
    if (allocatedMemoryPtr == NULL)
    {
        printf("\nFailed to allocate!! Not enough memory.");
        exit(-1);
    }
    ll_push_back(ll, allocatedMemoryPtr);
    return allocatedMemoryPtr;
}

void deallocate(void *ptr)
{
    ll_remove(ll, ptr);
    free(ptr);
}

void closeAllocs()
{
    Node *c = ll->head;
    while (c != NULL)
    {
        Node *next = c->next;
        free(node_delete(c));
        c = next;
    }
}
