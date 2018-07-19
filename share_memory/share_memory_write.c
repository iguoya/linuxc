#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>

int main() {
    printf("BUFSIZ: %d\n", BUFSIZ);
    int shmid = shmget(9999, BUFSIZ, 0666);
    printf("shmid: %d \n", shmid);

    char *shmbuf = shmat(shmid, 0, 0);
    char s[BUFSIZ];
    strcpy(s, shmbuf);
//    printf("shmbuf size:%ld\n", sizeof(shmbuf));
    write(STDOUT_FILENO, s, strlen(s));
    sleep(100);
    return 0;
}