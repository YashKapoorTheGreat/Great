#include <strings/string.h>
#include <memory/allocs.h>
#include <stdio.h>
#include <string.h>

typedef struct String
{
    char *str;
    int len;
} String;

/*
░██████╗████████╗██████╗░██╗███╗░░██╗░██████╗░  ░█████╗░██████╗░███████╗░█████╗░████████╗██╗░█████╗░███╗░░██╗
██╔════╝╚══██╔══╝██╔══██╗██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║
╚█████╗░░░░██║░░░██████╔╝██║██╔██╗██║██║░░██╗░  ██║░░╚═╝██████╔╝█████╗░░███████║░░░██║░░░██║██║░░██║██╔██╗██║
░╚═══██╗░░░██║░░░██╔══██╗██║██║╚████║██║░░╚██╗  ██║░░██╗██╔══██╗██╔══╝░░██╔══██║░░░██║░░░██║██║░░██║██║╚████║
██████╔╝░░░██║░░░██║░░██║██║██║░╚███║╚██████╔╝  ╚█████╔╝██║░░██║███████╗██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║
╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚═════╝░  ░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝
*/

String *string(char *string)
{
    int length = 0;
    for (int i = 0; string[i] != '\0'; i++, length++)
        ;
    String *str = allocate(sizeof(String));
    str->len = length;
    str->str = string;
    return str;
}
String *string_from_len(int length)
{
    String *str = allocate(sizeof(String));
    str->len = length;
    str->str = allocate((str->len + 1) * sizeof(char));
    str->str[str->len] = '\0';
    return str;
}
String *string_from_char(char chr)
{
    String *str = allocate(sizeof(String));
    str->len = 1;
    str->str = allocate((str->len + 1) * sizeof(char));
    str->str[0] = chr;
    str->str[1] = 0;
    return str;
}
String *to_string(int num)
{
    int len = 1;
    for (int number = num; !(number / 10 < 1); len += 1)
    {
        number /= 10;
    }
    String *str = string_from_len(len);
    sprintf(str->str, "%d", num);
    return str;
}

int string_get_len(String *string)
{
    return string->len;
}
int string_get_char_from_idx(String *string, int idx)
{
    if (idx >= string->len)
        return 0;
    return string->str[idx];
}
_Bool string_in_array(String *string, String *operators[], int operatorsLen)
{
    for (int i = 0; i < operatorsLen; i++)
        if (str_equals(string, operators[i]))
            return 1;
    return 0;
}

/*
░██████╗████████╗██████╗░██╗███╗░░██╗░██████╗░  ░█████╗░██████╗░███████╗██████╗░░█████╗░████████╗██╗░█████╗░███╗░░██╗░██████╗
██╔════╝╚══██╔══╝██╔══██╗██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██║██╔══██╗████╗░██║██╔════╝
╚█████╗░░░░██║░░░██████╔╝██║██╔██╗██║██║░░██╗░  ██║░░██║██████╔╝█████╗░░██████╔╝███████║░░░██║░░░██║██║░░██║██╔██╗██║╚█████╗░
░╚═══██╗░░░██║░░░██╔══██╗██║██║╚████║██║░░╚██╗  ██║░░██║██╔═══╝░██╔══╝░░██╔══██╗██╔══██║░░░██║░░░██║██║░░██║██║╚████║░╚═══██╗
██████╔╝░░░██║░░░██║░░██║██║██║░╚███║╚██████╔╝  ╚█████╔╝██║░░░░░███████╗██║░░██║██║░░██║░░░██║░░░██║╚█████╔╝██║░╚███║██████╔╝
╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚═════╝░   ╚════╝░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░╚════╝░╚═╝░░╚══╝╚═════╝░░

*/

String *str_concatinate(String *string1, String *string2)
{
    String *string = string_from_len(string1->len + string2->len);

    for (int i = 0; i < string1->len; i++)
        string->str[i] = string1->str[i];
    for (int i = 0; i < string2->len; i++)
        string->str[i + string1->len] = string2->str[i];

    return string;
}
_Bool str_equals(String *string1, String *string2)
{
    if (string1->len != string2->len)
        return 0;

    for (int i = 0; i < string1->len; i++)
        if (string1->str[i] != string2->str[i])
            return 0;

    return 1;
}
