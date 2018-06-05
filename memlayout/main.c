#include <stdio.h>
#include <stdlib.h>


int global_init_val = 10000;
int global_uninit_val;
extern char **environ;

struct address_info {
    void *address;
    char *name;
};



int main(int argc, char *argv[], char *envp[]) {
//    for (int i = 0; envp[i] != NULL; ++i) {
//        printf("%d : %s\n", i, envp[i]);
//    }

    printf("int size:%ld, char size: %ld\n", sizeof(int), sizeof(char));


    printf("example: path :%s \n", getenv("PATH"));
    printf("example: home :%s \n", getenv("HOME"));


    char local_int_val[1024*1024*7];
    char *local_string_point = "abc";
    static int local_static_val = 1000;
    char * local_malloc_point;
    local_malloc_point = malloc(1*1024*4);


    struct address_info memory_type[13];

    memory_type[0].name = "text code (main address  low ??)";
    memory_type[0].address = main;

    memory_type[1].name = "Initialized data (data)";
    memory_type[1].address = &global_init_val;

    memory_type[2].name = "Uninitialized data (bss)";
    memory_type[2].address = &global_uninit_val;

    memory_type[3].name = "local int data (stack)";
    memory_type[3].address = &local_int_val;

    memory_type[4].name = "local string point (stack)";
    memory_type[4].address = &local_string_point;

    memory_type[5].name = "local string data (data ???)";
    memory_type[5].address = local_string_point;

    memory_type[6].name = "local static data (data)";
    memory_type[6].address = &local_static_val;

    memory_type[7].name = "local malloc point (stack ??)";
    memory_type[7].address = &local_malloc_point;

    memory_type[8].name = "malloc data (heap)";
    memory_type[8].address = local_malloc_point;

    memory_type[9].name = "argv point(local self)";
    memory_type[9].address = &argv;

    memory_type[10].name = "argv data (high ?)";
    memory_type[10].address = argv;

    memory_type[11].name = "env point (local self) ";
    memory_type[11].address = &envp;

    memory_type[12].name = "env data (high ?)";
    memory_type[12].address = envp;



    int address_rank[13];
    for(int index = 0; index < 13; ++index) {
        int low_than_me = 0;
        for(int behind_me_index = 0; behind_me_index < 13; ++behind_me_index) {
            if (memory_type[index].address > memory_type[behind_me_index].address) {
                ++low_than_me;
            }
        }
        address_rank[low_than_me] = index;
    }

    printf("show info from low to high address \n");
    for(int i = 0; i < 13; ++i) {
        printf("rank :%d , address: %p, name : %s\n", i, memory_type[address_rank[i]].address, memory_type[address_rank[i]].name);
    }

    printf("stack space between low to high is about (栈空间默认最大8M--ulimit): %dM", ((void *)envp-(void *)&envp)/1024/1024);


    free(local_malloc_point);

    return 0;
}



