#ifndef STRING_H
#define STRING_H

typedef struct String String;

String *string(char *string);
String *string_from_len(int length);
String *string_from_char(char chr);
String *to_string(int num);

int string_get_len(String *string);
int string_get_char_from_idx(String *string, int idx);
_Bool string_in_array(String *string, String *operators[], int operatorsLen);

String *str_concatinate(String *string1, String *string2);
_Bool str_equals(String *string1, String *string2);

#endif
