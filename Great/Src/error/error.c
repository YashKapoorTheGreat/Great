#include "./error.h"

typedef struct Error
{
    Position position;
    String *error_name, *error_details;
} Error;

Error *error_create(Position position, String *error_name, String *error_details)
{
    Error *this = allocate(sizeof(Error));
    this->position = position;
    this->error_name = error_name;
    this->error_details = error_details;
    return this;
}

String *error_as_string(Error *this)
{
    String *result = string("File ");
    result = str_concatinate(result, this->position.file_name);
    result = str_concatinate(result, string(", line "));
    result = str_concatinate(result, to_string(this->position.line_num + 1));
    result = str_concatinate(result, string("\n"));
    result = str_concatinate(result, this->position.line);
    result = str_concatinate(result, string("\n"));
    for (int i = 0; i < this->position.col_start; i++)
    {
        result = str_concatinate(result, string(" "));
    }
    for (int i = 0; i < this->position.col_end - this->position.col_start; i++)
    {
        result = str_concatinate(result, string("^"));
    }
    result = str_concatinate(result, string("\n"));
    result = str_concatinate(result, string("\n"));
    result = str_concatinate(result, str_concatinate(this->error_name, string(": ")));
    result = str_concatinate(result, this->error_details);
    return result;
}
