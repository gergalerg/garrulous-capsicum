#include <stdio.h>

int main()
{
    int i = 10;
    int arr[2] = {1,2};

    // alias i to arr[2]
    arr[2] = 20;
    printf("el 0: %d \n", arr[0]);
    printf("el 1: %d \n", arr[1]);
    printf("el 2: %d \n", arr[2]);
    printf("i: %d \n", i);
    printf("arr size: %d \n", (int)(sizeof(arr) / sizeof(int)));
}