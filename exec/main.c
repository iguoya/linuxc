#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

char *env[] = {"USER=snow", "PATH=/tmp", NULL};

int main() {
    pid_t pid;

    if((pid = fork()) == 0) {

        printf("a-->我的进程名称：%d, 父进程:%d\n", getpid(), getppid());
        int status = execle("./app", "app", "abc", "6666", "99a", "k98", NULL, env);//可执行的话，进程空间内容被替换，下句不在执行
        printf("b-->我的进程名称：%d, 父进程:%d, 返回状态%d\n", getpid(), getppid(), status);
    }

    int wait_status = waitpid(pid, NULL, 0);


    printf("父进程输出 各类型变量长度：\n\n");
    printf("%d\t%d\t\n", sizeof(int), sizeof(unsigned int));
    printf("%d\t%d\t\n", sizeof(long int), sizeof(unsigned long int));
    printf("%d\t%d\t\n", sizeof(long long int), sizeof(unsigned long long int));
    printf("%d\t%d\t\n", sizeof(double), sizeof(double));

    //默认环境变量
    if((pid = fork()) == 0) {
        printf("a-->我的进程名称：%d, 父进程:%d\n", getpid(), getppid());
        int status = execlp("./app", "app", "abc", "6666", "99a", "k98", NULL);//可执行的话，进程空间内容被替换，下句不在执行
        printf("b-->我的进程名称：%d, 父进程:%d, 返回状态%d\n", getpid(), getppid(), status);
    }








    return 0;
}