#include <defines.h>
#include <io/io.h>
#include <memory/allocs.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct String
{
    char *str;
    int len;
} String;

typedef struct Queue
{
    Node *frt;
    Node *rear;
    int len;
} Queue;

Queue *input_string_as_queue()
{
    Queue *q = queue_create();
    int len = 23;
    String *data = string_from_len(len);
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < 22)
        {
            data->str[i] = ch;
            i++;
        }
        else
        {
            data->str[i] = ch;
            i = 0;
            queue_enqueue(q, data->str);
            data->str = allocate((data->len + 1) * sizeof(char));
            data->str[data->len] = '\0';
        }
    }
    if (i != 0)
    {
        data->str[i + 1] = '\0';
        queue_enqueue(q, data->str);
    }
    return q;
}

String *input_string()
{
    Queue *q = input_string_as_queue();
    String *str = string_from_len(((q->len - 1) * 23) + strlen(q->rear->data));
    Node *c = q->frt;
    int j = 0;
    while (c != NULL)
    {
        char *data = ((char *)(c->data));
        for (int i = 0; i < 23; i++)
        {
            if (data[i] == '\0')
                break;
            str->str[(j * 23) + i] = data[i];
        }
        c = c->next;
        j++;
    }
    return str;
}
