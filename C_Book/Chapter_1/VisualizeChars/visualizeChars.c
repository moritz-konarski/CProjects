#include <stdio.h>

/*Replace tabs, backspaces and slashes by their representations*/

int main () {

    printf("Replace tabs, slashes and backspaces by simple representation\n");

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
    return 0;
}