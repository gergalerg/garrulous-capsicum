#include <stdio.h>
int c = 0;

int main()
{
printf("\nEnter a number: ");
while (1) {
    c = getchar();
    if (c != EOF && c > 0 && c < 6) {
        printf("you entered %d\n", c);
    } else {
        printf("Goodbye!");
       };
};
};