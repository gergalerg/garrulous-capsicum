#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (rename("sample.txt", "newsample.txt") != 0)
        fprintf(stderr, "Error renaming \"sample.txt\".\n");
}