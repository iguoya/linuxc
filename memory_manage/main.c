#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define GIGABYTE (1024*1024*1024) //2058973
//#define PHY_MEM_MEGS 16

int main() {
    char *some_memory = (char *)malloc(GIGABYTE);
    sprintf(some_memory,  "你好，我是中国人！, 我申请了1G空间存储这句话");
    printf("%s\n", some_memory);
//    free(some_memory);
    char *scan_ptr = some_memory;
    printf("%s\n", scan_ptr);
    int times = 0;
    while(1) {
        some_memory = (char *)malloc(GIGABYTE);
        if(some_memory != NULL) {
            sprintf(some_memory, "Hello, 分配给我的空间好大！");
            printf("%s--第%d次成功申请分配空间!\n", some_memory, ++times);
        } else {
            printf("终于分配失败！");
            exit(EXIT_FAILURE);
        }
    }


//    while(1) {
//        ++scan_ptr;
//        *scan_ptr = '\0';
//
//    }



    return 0;
}