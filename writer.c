#include <unistd.h>
#include <stdlib.h>

int main()
{
    if ((write(3, "Here is some data\n", 18)) != 18)
        write(2, "A write error has occured on file desc 3\n", 46);
    exit(0);
}