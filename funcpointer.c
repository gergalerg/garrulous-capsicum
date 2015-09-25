#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

sem_t bin_sem;

int value;

int main() 
{
    sem_init(&bin_sem, 0, 0);
    sem_wait(&bin_sem);

    sem_getvalue(&bin_sem, &value);
    printf("Value is %d\n", value);

}