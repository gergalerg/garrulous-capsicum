#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

_Bool isReadable(const char *filename)
{
    FILE *fp = fopen(filename, "r"); //open a file to read/write

    if (fp != NULL)
    {
        fclose(fp);
        return true;
    }
    else
        return false;
}

int main(int argc, char **argv)
{


    int result  = isReadable(argv[1]);
    printf("%d\n", (int)result );
}