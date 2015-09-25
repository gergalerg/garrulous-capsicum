#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 100000

sem_t sem_b;

int cnt = 0;

void * Count(void *a) {
    int i, tmp;
    int value;
    sem_wait(&sem_b);
    sem_getvalue(&sem_b, &value);
    printf("The internal value of semaphors is %d\n", value);
    for (i = 0; i < NITER; i++) {
        tmp = cnt;      // copy the global cnt locally
        tmp = tmp+1;    // increment the local copy
        cnt = tmp;      // store the local value into the global cnt
    }
    sem_post(&sem_b);
}

int main(int argc, char *argv[]) 
{
    int value;
    pthread_t tid1, tid2;

    sem_init(&sem_b, 0, 0);
    sem_getvalue(&sem_b, &value);
    printf("before initial of semaphors is %d\n", value);
    sem_post(&sem_b);

    sem_getvalue(&sem_b, &value);
    printf("The value of semaphors is %d\n", value);

    if (pthread_create(&tid1, NULL, Count, NULL))
    {
        printf("\nError creating thread 1");
        exit(1);
    }
    if (pthread_create(&tid2, NULL, Count, NULL))
    {
        printf("\nError creating thread 2");
        exit(1);
    }
    if (pthread_join(tid1, NULL)) {
        printf("\nError joining thread");
        exit(1);
    }
    if (pthread_join(tid2, NULL)) {
        printf("\nError joining thread");
        exit(1);
    }
    if (cnt < 2 * NITER)
        printf("\nBoom! cnt is [%d], should be %d\n", cnt, 2 * NITER);
    else
        printf("\nOk! cnt is [%d]\n", cnt);
    sem_getvalue(&sem_b, &value);
    printf("The value of semaphors is %d\n", value);
    pthread_exit(NULL);
    sem_destroy(&sem_b);
}