#include <stdio.h>

int main()
{
    _Static_assert( sizeof(int) > 6, "16-bit code not supported");
}