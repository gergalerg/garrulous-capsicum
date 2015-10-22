#include <stdlib.h>
#include <stdio.h>

int int_sorter(const void *first_arg, const void *second_arg)
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;

    if (first < second)
    {
        return -1;
    }
    else if (first == second)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int (*int_sorter_pointer)(const void*, const void*);
    int_sorter_pointer = &int_sorter;
    int array[10];
    int i;
    for (i = 0; i < 10; ++i)
    {
        array[i] = 10 -i;
    }
    for (i = 0; i < 10; ++i)
    {
        printf("%d\n", array[i]);
    }
    qsort(array, 10, sizeof(int), int_sorter_pointer);
    for (i = 0; i < 10; ++i)
    {
        printf("%d\n", array[i]);
    }

}