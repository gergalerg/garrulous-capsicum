#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>

pthread_mutex_t work_mutex;

int main() {
    int res;
    res = pthread_mutex_init(&work_mutex, NULL);
    printf("Value is %d", res);
    res = pthread_mutex_lock(&work_mutex);
    printf("Value is %d", res);
    res = pthread_mutex_unlock(&work_mutex);
    printf("Value is %d", res);
}