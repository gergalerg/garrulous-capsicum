#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    /*
    size_t SIZE = 100;
    char* message = malloc(SIZE);

    puts("Enter a message:\n");
    getline(&message, &SIZE, stdin);
    printf("Message: %s size: %i", message, (int) sizeof(message));
    */
    char c;
    while (c != 't') {
        c = getchar();
    }
    printf("C = %c", (char)c);
}
