#ifndef POSITION_H
#define POSITION_H

#include <strings/string.h>
#include <memory/allocs.h>

typedef struct Position
{
    int col_start, col_end;
    int line_num;
    String *file_name;
    String *line;
} Position;

Position position_create(int col_start, int col_end, int line_num, String *file_name, String *line);

#endif
