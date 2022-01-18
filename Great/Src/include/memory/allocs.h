#ifndef ALLOCS_H
#define ALLOCS_H
#include <stdlib.h>

void initAllocs();
void *allocate(size_t bytes);
void deallocate(void *ptr);
void closeAllocs();

#endif
