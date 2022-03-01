#include "value.h"

typedef struct Value
{
    void *data;
    ValueType type;
} Value;
