#include <stdio.h>

/*Replace multiple spaces by one space*/

int main () {

    printf("Replace multiple spaces with a single space\n");

    int c, spaceCount = 0;

    while (EOF != (c = getchar())) {
        if (' ' == c) {
            spaceCount++;
            if (2 > spaceCount) {
                putchar(c);
            }
        } else {
            spaceCount = 0;
            putchar(c);
        }        
    }
    return 0;
}