// #include <datastructures/queue/queue.h>
#include <memory/allocs.h>

void end();

// Queue queue;

void initAllocs()
{
}

void *allocate(size_t num_bytes)
{
    void *allocatedMemoryPtr = malloc(num_bytes);
    memset(allocatedMemoryPtr, 0, num_bytes);
    if (allocatedMemoryPtr == NULL)
    {
        // TODO : RT Error Here
        end();
    }
    // TODO : free automatically
    return allocatedMemoryPtr;
}

void deallocate(void *ptr)
{
    free(ptr);
}

void closeAllocs()
{
    // q_clear(&queue);
}
