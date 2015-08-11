#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 100000

sem_t sem_b;

int cnt = 0;

void * Count(void *a) {
    int i, tmp;
    for (i = 0; i < NITER; i++) {
        tmp = cnt;      // copy the global cnt locally
        tmp = tmp+1;    // increment the local copy
        cnt = tmp;      // store the local value into the global cnt
    }
}

int main(int argc, char *argv[]) 
{
    pthread_t tid1, tid2;

    sem_init(&sem_b, 0, 1);

    if (pthread_create(&tid1, NULL, Count, NULL))
    {
        printf("\nError creating thread 1");
        exit(1);
    }
    sem_post(&sem_b);
    if (pthread_create(&tid2, NULL, Count, NULL))
    {
        printf("\nError creating thread 2");
        exit(1);
    }
    sem_wait(&sem_b);
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

    pthread_exit(NULL);
}