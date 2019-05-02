#include <stdio.h>

/*Replace tabs, backspaces and slashes by their representations*/

int main () {

    printf("Replace tabs, slashes and backspaces by simple representation\nTo stop, enter EOF\n");

    int c;

    while (EOF != (c = getchar())) {
        if ('\t' == c) {
            printf("\\t");
        } else if ('\b' == c) {
            printf("\\b");
        } else if ('\\' == c) {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}