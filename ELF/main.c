#include <stdio.h>

int main() {
    char *p = "Hello, World!";
    printf("%s \n", p);
    return 0;
}
//

//[tiger@asus cmake-build-debug]$ size ELF
//        text    data     bss     dec     hex filename
//1452     584       8    2044     7fc ELF
//[tiger@asus cmake-build-debug]$ size ELF
//        text    data     bss     dec     hex filename
//1466     584       8    2058     80a ELF
