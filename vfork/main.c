#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int global_num = 0;
int main() {
    printf("Hello, World!\n");
    int local_num = 0;

    pid_t pid;

    if((pid = fork()) == 0) {
//        for(int i = local_num; i< 10; ++i)
        while(local_num < 10) {
            printf("process: %d, num:%d\n", getpid(), local_num);
            ++local_num;
        }
        printf("这是子进程\n");
        printf("没有换行符，显示");

        exit(0);
    } else {
        sleep(1);
        printf("这是父进程\n");
        printf("没有换行符，不显示");
//        ++global_num;
//        ++local_num;
        _exit(0);
    }
    printf("pid:%d, global num:%d, local num:%d\n", getpid(), global_num, local_num);
    return 0;
}