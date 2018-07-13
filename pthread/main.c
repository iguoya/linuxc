#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static int sum = 0;
typedef struct arg {
    int count;
    char *name;
} arg;

void task(arg* a) {
    while(a->count < 10) {
        printf("%s task count :%d, sum: %d\n", a->name, a->count, sum);
        ++a->count;
        ++sum;
//        sleep(1);
    }
    if(strcmp(a->name, "task1") == 0) {
        pthread_exit((void *)101);
    }
}



int main() {

    pthread_t  pthread_1, pthread_2;
    int ret;
    void *return_val;


    arg *a1 = (arg *)malloc(sizeof(arg));
    a1->count = 1;
    a1->name = "task1";
    arg *a2 = (arg *)malloc(sizeof(arg));
    a2->count = 1;
    a2->name = "task2";

//    int g2 = 0;

    printf("I am in main function\n");
    ret = pthread_create(&pthread_1, NULL, (void*)task, (void*) a1);
    printf("now two task 's sum is %d\n", a1->count+a2->count);
    ret = pthread_create(&pthread_2, NULL, (void*)task, (void*) a2);
    printf("now two task 's sum is %d\n", a1->count+a2->count);

    int tmp = pthread_join(pthread_1, &return_val);
    switch(tmp) {
        case EINVAL:
            printf("EINVAL:%d\n", tmp);
            break;
        case ESRCH:
            printf("ESRCH:%d\n", tmp);
            break;
        default:
            printf("others :%d\n", tmp);
    }

    printf("return val of task1 is %d\n", (int)return_val);

    printf("now two task 's sum is %d\n", a1->count+a2->count);

    getchar();
//



    printf("Hello, World!\n");
    return 0;
}