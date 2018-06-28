#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

void judge_exit_status(int status) {
    if (WIFEXITED(status)) {
        printf("正常退出，未处理退出码：%d", status);
        printf("-->处理后退出码：%d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("异常退出，未处理信号码：%d", status);
        printf("-->处理后信号码：%d\n", WTERMSIG(status));
    }
}

int main() {

    pid_t pid;
    int status = 100;

    printf("正常退出的三种状态:\n");

    if ((pid = fork()) == 0) {

        printf("子进程先等待5秒， 看谁敢先执行！！！\n");
        sleep(5);
        printf("我是子进程: %d， 我的父进程:%d, 正常执行\n", getpid(), getppid());

    } else {
//        printf("我是父进程:%d ,我在等待我的子进程结束，他的pid是：%d\n",getpid(), pid);
        if (wait(&status) == pid) {
            printf("我是父进程:%d ,我等到了子进程：%d结束，子进程退出状态：--->", getpid(), pid, status);
            judge_exit_status(status);

            printf("---------------新希望 -----1------------\n");

            if ((pid = fork()) == 0) {
                printf("我是子进程: %d， 我的父进程:%d , return 退出\n", getpid(), getppid());
                return 101;
            } else {
//        printf("我是父进程:%d ,我在等待我的子进程结束，他的pid是：%d\n",getpid(), pid);
                if (wait(&status) == pid) {
                    printf("我是父进程:%d ,我等到了子进程：%d结束，return 子进程退出状态：--->", getpid(), pid, status);
                    judge_exit_status(status);
                }

                printf("---------------新希望-----2------------\n");

                if ((pid = fork()) == 0) {
                    printf("我是子进程: %d， 我的父进程:%d , 正常退出， exit \n", getpid(), getppid());
                    exit(36);
                    exit(23);
                } else {
//        printf("我是父进程:%d ,我在等待我的子进程结束，他的pid是：%d\n",getpid(), pid);
                    if (wait(&status) == pid) {

                        printf("我是父进程:%d ,我等到了子进程：%d结束，exit 子进程退出状态：：--->", getpid(), pid, status);
                        judge_exit_status(status);
                    }

                    printf("---------------新希望-----3------------\n");

                    if ((pid = fork()) == 0) {

                        printf("我是子进程: %d， 我的父进程:%d , 中断异常退出， abort()\n", getpid(), getppid());

                    } else {
                        printf("我是父进程:%d ,我在等待我的子进程结束，他的pid是：%d\n", getpid(), pid);
                        if (wait(&status) == pid) {

                            printf("我是父进程:%d ,我等到了子进程：%d结束，abort() 子进程退出状态：--->", getpid(), pid, status);
                            judge_exit_status(status);


                            printf("---------------新希望--------4---------\n");


                            if ((pid = fork()) == 0) {

                                printf("我是子进程: %d， 我的父进程:%d , 中断除0退出\n", getpid(), getppid());
                                int m = 5 / 0;
                            } else {
                                printf("我是父进程:%d ,我在等待我的子进程结束，他的pid是：%d\n", getpid(), pid);
                                if (wait(&status) == pid) {

                                    printf("我是父进程:%d ,我等到了子进程：%d结束， 中断除0 子进程退出状态：--->", getpid(), pid, status);
                                    judge_exit_status(status);
                                }

                            }


                        }

                    }

                }
            }


        }

    }






    return 0;
}

