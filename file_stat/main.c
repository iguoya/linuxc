#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
//    printf("Hello, World!\n");
    struct stat buf;
    int status = lstat(argv[1], &buf);
    printf("status :%d\n", status);
    printf("i-node :%ld\n", buf.st_ino);
    printf("link :%ld\n", buf.st_nlink);
    printf("UID :%d\n", buf.st_uid);
    printf("GID :%d\n", buf.st_gid);
    printf("Size :%ld\n", buf.st_size);

//    switch(buf.st_mode) {
//        case S_ISREG(buf.st_mode）:
//            break;
//    }
    char *file_type;
    if (S_ISREG(buf.st_mode)) {
        file_type = "regular";
    } else if (S_ISDIR(buf.st_mode)) {
        file_type = "directory";
    } else if (S_ISCHR(buf.st_mode)) {
        file_type = "character device";
    } else if (S_ISBLK(buf.st_mode)) {
        file_type = "block device";
    } else if (S_ISFIFO(buf.st_mode)) {
        file_type = "fifo";
    } else if (S_ISLNK(buf.st_mode)) {
        file_type = "symbolic link";
    } else if (S_ISSOCK(buf.st_mode)) {
        file_type = "socket";
    }
    printf("file type: %s\n", file_type);

    return 0;
}