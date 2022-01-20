#include <stdio.h>
#include <memory\allocs.h>
#include <defines.h>
#include <datastructures\queueLL\queuell.h>

int main(int argc, char const *argv[])
{
    int *data1 = allocate(10 * sizeof(int));
    int *data2 = allocate(10 * sizeof(int));
    data2[5] = 5;
    Queue *q = queue_create();
    q->push(q, data1);
    q->push(q, data2);
    int *data11 = q->pop(q);
    int *data22 = q->pop(q);
    int *data3 = q->pop(q);
    return EXIT_SUCCESS;
}
