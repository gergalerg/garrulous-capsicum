#include <stdlib.h>
#include <stdio.h>

void f(void)
{
    int *x = malloc(5 * sizeof(int)); 
    x[4] = 0;
    free(x);
}

int main(int argc, char const *argv[])
{
    f();
    return (0);
}

