#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct arg {

    char *name;
} arg;

void task(arg *a) {
    if (strcmp(a->name, "task1") == 0) {
        pthread_mutex_lock(&mutex);
        for (int i = 1; i <= 10; ++i) {
            sum += i;
            sleep(1);
            printf("now task1 sum is: %d\n", sum);
        }
        printf("task1 result should be 55, in reality : %d\n", sum);
        pthread_mutex_unlock(&mutex);

        pthread_exit((void *) 101);
    } else if (strcmp(a->name, "task2") == 0) {
        pthread_mutex_lock(&mutex);
        for (int i = 1; i <= 10; ++i) {
            sum += i;
            sleep(1);
            printf("now task2 sum is: %d\n", sum);
        }
        printf("task1 result should be 55, in reality : %d\n", sum);
        pthread_mutex_unlock(&mutex);
        pthread_exit((void *) 301);
    }
}


int main() {

    arg *a1 = (arg *) malloc(sizeof(arg));

    a1->name = "task1";
    arg *a2 = (arg *) malloc(sizeof(arg));

    a2->name = "task2";

    pthread_t pthread_1, pthread_2;

    pthread_create(&pthread_1, NULL, (void *) task, (void*) a1);
    pthread_create(&pthread_2, NULL, (void *) task, (void*) a2);

    pthread_join(pthread_1, NULL);
    pthread_join(pthread_2, NULL);

    printf("in conclusion, sum is: %d\n", sum);

    getchar();
    printf("Hello, World!\n");
    return 0;
}