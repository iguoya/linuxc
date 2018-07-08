#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>

int main( )
{
    system("lsb_release -a");
    printf("Done\n");
//
//
//    execlp("ps", "ps", "-ax", 0);
//    printf("Done  Again\n");
    char *message;
    int n = 10;

    pid_t pid = fork();

    switch(pid) {
        case 0:
            message = "This is Child";
            break;
        default:
            message = "This is Parent";
    }

    int status;
    if(wait(&status) == pid) {
        if(WIFEXITED(status)) {
            printf("子进程退出，退出码：%d, 开始父进程的执行--->:\n\n", WEXITSTATUS(status));
        }
    }
    while(n > 0) {
        printf("the %dst times， ", n);
        puts(message);
        --n;
//        sleep(1);
    }

    return 0;
}
