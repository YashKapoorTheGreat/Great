#include <datastructures/LL/ll.h>
#include <memory/allocs.h>

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

Linkedlist *ll_create()
{
    Linkedlist *ll = allocate(sizeof(Linkedlist));
    ll->head = ll->tail = NULL;
    ll->len = 0;
    return ll;
}

void ll_push_back(Linkedlist *this, void *data)
{
    this->len += 1;
    if (this->head == NULL)
    {
        this->head = this->tail = node_create(data);
        return;
    }
    this->tail = node_add(data, this->tail);
}

void ll_remove(Linkedlist *this, void *data)
{
    Node *c = this->head;
    Node *p = NULL;
    while (c != NULL)
    {
        if (c->data == data)
        {
            this->len -= 1;
            if (p != NULL)
            {
                if (c == this->tail)
                {
                    this->tail = p;
                }
                p->next = c->next;
                node_delete(c);
            }
            else if (this->head == this->tail)
            {
                node_delete(this->head);
                this->head = this->tail = NULL;
            }
            else
            {
                Node *next = this->head->next;
                node_delete(this->head);
                this->head = next;
            }
            break;
        }
        p = c;
        c = c->next;
    }
}