#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("b-->我的进程名称：%d, 父进程:%d\n", getpid(), getppid());
    extern char **environ;
    for(int i = 0; i < argc; ++i) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    printf("环境变量：\n");
    for (char **ptr = environ; *ptr != 0; ++ptr) {
        printf("%s\n", *ptr);
    }
    return 0;
}