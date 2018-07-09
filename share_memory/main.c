#include <unistd.h>
#include <sys/types.h>
//#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>

int main() {
    printf("BUFSIZ: %d\n", BUFSIZ);
    int shmid = shmget(9999, BUFSIZ, 0666 | IPC_CREAT);
    printf("shmid: %d \n", shmid);

    char *shmbuf = shmat(shmid, 0, 0);


    strcpy(shmbuf, "Hello World!, 你好，我是中国人！好长好长。。。。。。。");
//    sprintf(shm, "", s);


    return 0;
}