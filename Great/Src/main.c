#include <stdio.h>
#include <defines.h>
#include <io\io.h>

int main(int argc, char const *argv[])
{
    Queue *q = input_string_as_queue();
    Node *c = q->frt;
    while (c != NULL)
    {
        printf(c->data);
        c = c->next;
    }

    return EXIT_SUCCESS;
}
