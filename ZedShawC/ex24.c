#include <stdio.h>
#include "debug.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE, GREEN, BROWN, BLACK, OTHER
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char const *argv[])
{
    Person you = {.age = 0 };
    int i = 0;
    char *in = NULL;

    printf("What's your first name? ");
    in = fgets(you.first_name, MAX_DATA -1, stdin);
    check(in != NULL, "Failed to read last name");

    printf("What's your last name? ");
    in  = fgets(you.last_name, MAX_DATA -1, stdin);
    check (in != NULL, "Failed to read last name");

    printf("How old are you? ");
    int rc = fscanf(stdin, "%d", &you.age);

    printf("What color are your eyes:\n");
    for (i = 0; i <= OTHER; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }

    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    you .eyes = eyes -1;
    check(you.eyes <= OTHER && you.eyes >= 0, "Do it right!");

    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number.");

    printf("______RESULTS______\n");

    printf("First name: %s", you.first_name);
    printf("Last name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %.2f\n", you.income * 2000);
    return 0;
    error:
        return -1;
}