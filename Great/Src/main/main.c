#include "run.h"

int main(int argc, char const *argv[])
{
    initAllocs();
    runfromshell();
    closeAllocs();
    return EXIT_SUCCESS;
}
