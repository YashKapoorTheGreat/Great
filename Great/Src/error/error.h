#ifndef ERROR_H
#define ERROR_H

#include "../position/position.h"
#include <strings/string.h>
#include <memory/allocs.h>

typedef struct Error Error;

Error *error_create(Position position, String *error_name, String *error_details);
String *error_as_string(Error *this);

#endif
