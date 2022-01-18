#include <strings/string.h>
#include <memory/allocs.h>

String str(char *string)
{
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++, length++)
        ;
    String str;
    str.len = length;
    str.str = string;
    str.add = str_concatinate;
    str.equals = str_equals;
    return str;
}
String strl(int length)
{
    // TODO my malloc
    String str;
    str.len = length;
    str.str = allocate((str.len + 1) * sizeof(char));
    str.str[str.len] = '\0';
    str.add = str_concatinate;
    str.equals = str_equals;
    return str;
}

String str_concatinate(String string1, String string2)
{
    String string = strl(string1.len + string2.len);

    for (int i = 0; i < string1.len; i++)
        string.str[i] = string1.str[i];
    for (int i = 0; i < string2.len; i++)
        string.str[i + string1.len] = string2.str[i];

    return string;
}
_Bool str_equals(String string1, String string2)
{
    if (string1.len != string2.len)
        return 0;

    for (int i = 0; i < string1.len; i++)
        if (string1.str[i] != string2.str[i])
            return 0;

    return 1;
}
