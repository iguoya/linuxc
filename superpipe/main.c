#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define BUFFSIZE 5

int get_prime_number(int n) {

    int flag = 0;
    int is_prime_number = n;
    while (1) {
        ++is_prime_number;
        int flag = 1;
        for (int i = 2; i <= sqrt(is_prime_number); ++i) {
            if (is_prime_number % i == 0) {
                flag = 0;
                break;
            } else {
                continue;
            }
        } else {
            return 0;
        }
    }
}

int main() {
    int pid, fd[2];
    char buf[BUFFSIZE];

    pipe(fd);
    int n = 0;

    if ((pid = fork()) > 0) {
        //parent
        char *msg = "Let's do a little games: I say prime number;， son , you say Composite integer , Now Begin ...\n";
//        int n = 1;
//        while(n < 100) {
//            ++n;
//            int prime_number = get_prime_number(n);
//            if(prime_number == 0) {
//                continue;
//            }
//            sprintf(buf, "%d", prime_number);
//            printf("I write num ：%d\n", prime_number);
//
////            printf("convert integer:%d to str(%s) \n", prime_number, buf);
//            write(fd[1], buf, BUFFSIZE);
//        }

        close(fd[0]);
//        memset(buf, 0, BUFFSIZE);
        while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
            write(fd[1], buf, n);
        }

    } else {
        //Child
        close(fd[1]);
        while ((n = read(fd[0], buf, BUFFSIZE)) > 0) {
            write(STDOUT_FILENO, "receive from parent: ", 21);
            write(STDOUT_FILENO, buf, n);
//            printf("I(PID:%d) received My Parent's number: %s\n", getpid(), buf);
//            int prime_number = atoi(buf);
//            sprintf(buf, "%d", prime_number * 2);
//            write(fd[1], buf, BUFFSIZE);
//            printf("I(PID:%d) write %d \n", prime_number*2);
//            sleep(1);
        }
        exit(0);
    }
    return 0;
}