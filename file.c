#include <stdio.h>

int main() {
    char buff[50];
    int SIZE = 1;
    int NUMELEN = 50;
    FILE *alice = fopen("alice.txt", "r");
    FILE *alice_copy = alice;
    fread(buff,SIZE, NUMELEN, alice);
    printf("\n%s\n*******END*********", buff);
    fseek(alice,0,SEEK_CUR);
    fread(buff,SIZE, NUMELEN, alice);
    printf("\n%s\n", buff);
    int *iPtr = malloc(1000 * sizeof(int));
    int td = sizeof(int);
    printf("Iptr = %d\n", *iPtr);
    printf("Sizeof int = %d\n", td);

}