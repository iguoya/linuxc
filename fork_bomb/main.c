#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    int n = 1;
    while(1) {
        if((pid = fork()) == 0) {
            ++n;
            printf("I am : %d, n: %d\n", getpid(), n);
        } else if(pid > 0) {
            ++n;
            sleep(5);
            printf("I'm parent: %d , My child: %d, n: %d-->", getpid(), pid, n);
        }
        if(n >= 2) {
            break;
        }

    }

    return 0;
}