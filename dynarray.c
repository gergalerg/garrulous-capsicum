#include <stdio.h>
#include <stdlib.h>

typedef struct { int len; float array[]; } DynArray_t;

int main()
{
    DynArray_t *daPtr = malloc( sizeof(DynArray_t) + 10 * sizeof(float));
    daPtr->len = 10;
    for (int i = 0; i < daPtr->len; ++i) {
        daPtr->array[i] = 1.0F/(i+1);
    }
    for (int i = 0; i < daPtr->len; ++i)
        printf("%.2f\t", daPtr->array[i]);
}