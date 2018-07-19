#include <stdio.h>

static int c = 1000;

int sum() {
    int a = -1;

    static int b = 100;
    extern int i;


    for(int index = 0; index < 10; ++index) {
        ++a;
        b += 100;
        c += 1000;
        i += 10000;
        printf("%d times:  local a: %d , static b:%d, global static c: %d, global i:%d \n", index, a, b, c, i);
    }

}

int main() {
    extern int i;

    sum();
    printf("In test function: %d\n", test());


    printf("the second call function:\n");
    sum();
    printf("In test function: %d\n", test());

    printf("Hello, World!, c:%d, i:%d\n",  c, i);
    return 0;
}

