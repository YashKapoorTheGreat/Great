#ifndef STRING_H
#define STRING_H

typedef struct string
{
    char *str;
    int len;
    struct string (*add)(struct string string1, struct string string2);
    _Bool (*equals)(struct string string1, struct string string2);
} String;

String str(char *string);
String strl(int length);

String str_concatinate(String string1, String string2);
_Bool str_equals(String string1, String string2);

#endif
