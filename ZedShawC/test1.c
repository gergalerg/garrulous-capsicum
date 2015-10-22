#include <stdio.h>
#include <stdlib.h>

#define min(X, Y) ( (X) < (Y) ? (X) : (Y) )

#define WARN_IF(M)\
    do { if (M)\
        fprintf(stderr, "Warning: #M " #M "\n");}\
        while (0)

#define eprintf(format, ...) fprintf (stderr, format, ##__VA_ARGS__)

int main()
{
    //eprintf(__FILE__);
    printf("Uint max max %lu\n", __UINTMAX_MAX__);

    return(0);

}