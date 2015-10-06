#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *func1(int *x) {

    return x;
}
void *func2(const int x) {

    return &x;
}


const int X = 4;
int main()
{
    /*
    size_t SIZE = 100;
    char* message = malloc(SIZE);

    puts("Enter a message:\n");
    getline(&message, &SIZE, stdin);
    printf("Message: %s size: %i", message, (int) sizeof(message));
    */
    int *px = malloc(sizeof(int));
    *px = 3;
    int *py = malloc(sizeof(int));
    py = func2(X);
    int *ci = func2(X);
    ++*ci;
    printf("ci= %d", *ci);
}
