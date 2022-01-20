#include <stdio.h>
#include <defines.h>
#include <io\io.h>
#include <strings\string.h>

int main(int argc, char const *argv[])
{
    String q = input_string();
    printf(q.str);

    return EXIT_SUCCESS;
}
