#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b);
}

#define SIZE 100
struct node {
    char *string;
    int length;
};

struct node *table[SIZE];

int values[] = {5,20, 29, 32,63};

int main()
{
    int *item;
    int key = 32;

    item = (int*) bsearch(&key, values, 5, sizeof(int), cmpfunc);

    printf("Found item %d\n", *item);

}