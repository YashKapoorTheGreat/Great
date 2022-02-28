#include "./position.h"

Position position_create(int col_start, int col_end, int line_num, String *file_name, String *line)
{
    Position this;
    this.col_end = col_end;
    this.col_start = col_start;
    this.line_num = line_num;
    this.file_name = file_name;
    this.line = line;
    return this;
}
