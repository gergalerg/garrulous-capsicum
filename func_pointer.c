#include <stdio.h>
#include <math.h>

void my_int_func(int x) 
{
    printf("%d\n", x);
}
int main()
{
    void (*foo)(int);
    foo = &my_int_func;
    int x = 3;
    foo(x);
}