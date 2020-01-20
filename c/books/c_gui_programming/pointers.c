#include <stdio.h>

int main() {

    int a;
    int *pointer_to_a;

    pointer_to_a = &a;

    a = 5;

    printf("a = %d, *a = %d\n", a, *pointer_to_a);

    *pointer_to_a = 7;

    printf("a = %d, *a = %d\n", a, *pointer_to_a);

    return 0;
}