#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create (char *n, int a, int h, int w) 
{
    struct Person *who = malloc(sizeof(struct Person));
    assert( who != NULL);

    who->name = strdup(n);
    who->age = a;
    who->height = h;
    who->weight = w;

    return who;
}

void Person_destroy(struct Person* who)
{
    assert (who != NULL);
    printf("%s destroyed\n", who->name);
    free(who->name);
    free(who);
}
void Person_print(struct Person *second)
{
    printf("Name: %s, age: %d, \nheight: %d, weight: %d\n",
        second->name, second->age, second->height, second->weight);
}
int main()
{
    struct Person *second = Person_create("Second", 43, 200, 150);
    struct Person *third= Person_create("Second", 43, 200, 150);
    Person_print(second);
    Person_print(third);
    printf("Address of second: %p\n", second);
    printf("Sizeof Person: %d\n", (int)sizeof(struct Person));
    printf("Address of third: %p\n", third);

}