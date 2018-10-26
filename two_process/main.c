#include <stdio.h>
#include <unistd.h>
int global_num = 10;

int main() {

    printf("Hello, World!\n");
    int local_num = 10;
    pid_t pid;


    if((pid=fork()) == 0) {
        ++global_num;
        local_num += 10;
        printf("global num :%d, local num :%d\n", global_num, local_num);
//        execl("/bin/ls", "ls", "-al", "/etc/passwd", 0);
//        exit(0);
    } else {
        ++global_num;
        local_num+=100;

//        execl("/bin/ls", "ls", "-al", ".", 0);
    }
    printf("global num :%d, local num :%d\n", global_num, local_num);
    return 0;
}