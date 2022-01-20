#include <defines.h>
#include <io\io.h>
#include <strings\string.h>
#include <memory\allocs.h>

Queue *input_string_as_queue()
{
    Queue *q = queue_create();
    int len = 23;
    String data = strl(23);
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < 22)
        {
            data.str[i] = ch;
            i++;
        }
        else
        {
            data.str[i] = ch;
            i = 0;
            q->enqueue(q, data.str);
            data.str = allocate((data.len + 1) * sizeof(char));
            data.str[data.len] = '\0';
        }
    }
    if (i != 0)
    {
        data.str[i + 1] = '\0';
        q->enqueue(q, data.str);
    }
    return q;
}
