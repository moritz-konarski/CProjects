#include <stdio.h>

int main() {
    int intval = 255958283;
    void *ptr = &intval;

    printf("ptr as int = %d\n", *((int *) ptr));

    printf("ptr as char = %d\n", *((char *) ptr));

    return 0;
}