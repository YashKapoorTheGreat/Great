#include "./tokenizer.h"

typedef struct Tokenizer
{
    int current_line;
    int current_col;
    int current_idx;
    char current_char;
    String *code;

} Tokenizer;

Tokenizer *t_create(String *code)
{
    Tokenizer *tokenizer = allocate(sizeof(Tokenizer));
    tokenizer->code = code;
    tokenizer->current_char = 0;
    tokenizer->current_col = -1;
    tokenizer->current_idx = -1;
    tokenizer->current_line = 0;
    t_advance(tokenizer);
    return tokenizer;
}

void t_advance(Tokenizer *this)
{
    if (string_get_len(this->code) <= this->current_idx)
    {
        this->current_char = 0;
        return;
    }
    this->current_idx++;
    this->current_col++;
    this->current_char = string_get_char_from_idx(this->code, this->current_idx);
}
// TODO CURRENT LINE POSITION, FILENAME
Queue *t_split(Tokenizer *this)
{
    Queue *tokens = queue_create();
    while (this->current_char != 0)
    {
        if (charinarray(this->current_char, OPERATORS, 8))
        {
            Token *token = token_create(
                string("OPERATOR"),
                string_from_char(this->current_char),
                position_create(this->current_col,
                                this->current_col + 1,
                                this->current_line,
                                string("<stdin>"),
                                this->code));
            queue_enqueue(tokens, token);
            t_advance(this);
        }
        else if (charinarray(this->current_char, NUMBERS, 11) && this->current_char != '.')
        {
            String *num = string_from_char(this->current_char);
            t_advance(this);
            int col_start = this->current_col;
            _Bool decimal = 0;
            while (charinarray(this->current_char, NUMBERS, 11))
            {
                if (decimal && this->current_char == '.')
                {
                    break;
                }
                else if (this->current_char == '.')
                {
                    decimal = 1;
                    num = str_concatinate(num, string_from_char(this->current_char));
                }
                else
                {
                    num = str_concatinate(num, string_from_char(this->current_char));
                }
                t_advance(this);
            }
            Token *token = token_create(
                string("NUMBER"),
                num,
                position_create(col_start,
                                this->current_col,
                                this->current_line,
                                string("<stdin>"),
                                this->code));
            queue_enqueue(tokens, token);
        }
        else if (this->current_char == '\n')
        {
            this->current_col = 0;
            this->current_line++;
            t_advance(this);
        }
        else if (this->current_char == '\t' || this->current_char == ' ')
        {
            t_advance(this);
        }
        else
        {
            Token *token = token_create(
                string("ERROR"),
                str_concatinate(
                    str_concatinate(
                        string("Unknown character - '"),
                        string_from_char(this->current_char)),
                    string("'")),
                position_create(this->current_col,
                                this->current_col + 1,
                                this->current_line,
                                string("<stdin>"),
                                this->code));
            queue_enqueue(tokens, token);
            t_advance(this);
        }
    }
    Token *token = token_create(
        string("EOF"),
        string("EOF"),
        position_create(this->current_col,
                        this->current_col + 1,
                        this->current_line,
                        string("<stdin>"),
                        this->code));
    queue_enqueue(tokens, token);
    return tokens;
}

_Bool charinarray(char chr, char array[], int arrlen)
{
    for (int i = 0; i < arrlen; i++)
    {
        if (chr == array[i])
            return 1;
    }
    return 0;
}
