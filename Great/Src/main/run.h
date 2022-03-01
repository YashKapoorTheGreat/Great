#ifndef RUN_H
#define RUN_H

#include <memory/allocs.h>
#include <defines.h>
#include <strings/string.h>

void runfromstring(String *str);

void runfromshell();
void runfromfile();

#endif