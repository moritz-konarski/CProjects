#include <stdio.h>
#include <stdint.h>

int main(void) {

    char test = 'a';

    printf("%c\n", test);

    printf("%c\n", test + 1);

    test += 1;

    printf("%c\n", test);

    printf("%d\n", '~' - ' ');

    return 0;
}
