#include <stdio.h>
//#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
//    printf("Hello, World!\n");
    printf("app name : %s, argv num :%d\n", argv[0], argc);
    for (int i = 1; argv[i] != NULL; ++i) {
        printf("arg %d is %s\n", i, argv[i]);
    }

    int read_length, write_length;
    char buf[256];

    int src_fd = open(argv[1], O_RDONLY);
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT, 0777);

    printf("%s file description num:%d, %s file description num:%d\n",
           argv[1], src_fd, argv[2], dest_fd);
    read_length = read(src_fd, buf, 256);
    for (int i = 0; read_length > 0; ++i) {
        write_length = write(dest_fd, buf, read_length);
        printf("%d times, read file length :%d, write file length : %d\n", i, read_length, write_length);

        read_length = read(src_fd, buf, 256);


    }
    printf("over now : read length:%d, write length:%d\n", read_length, write_length);

    close(src_fd);
    close(dest_fd);


    return 0;
}