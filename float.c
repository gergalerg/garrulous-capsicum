#include <stdio.h>
#include <float.h>


int main()
{
    printf("Storage size: %d bytes\n"
        "Smallest pos value: %E\n"
        "Greatest pos value: %E\n"
        "Precision %d decimal digits:\n",
        (int)sizeof(float), FLT_MIN, FLT_MAX, (int)FLT_DIG);
}
