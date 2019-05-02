#include <stdio.h>

/*Count whitespace, all digits individually (array) and other chars*/

int main () {
   
    printf("Count whitespace, numbers and other chars\nTo stop enter EOF\n");

    int c, n_white, n_other;
    n_other = n_white = 0;
    
    int n_digits[10];
    for (int i = 0; i < 10; i++) {
        n_digits[i] = 0;
    }

    while (EOF != (c = getchar())) {
        if (' ' == c || '\n' == c || '\t' == c) {
            n_white++;
        } else if ('0' <= c && '9' >= c) {
            n_digits[c - '0']++;
        } else {
            n_other++;
        }
    }

    printf("\nWhite space: %d\n", n_white);
    printf("Digit\tCount\n");
    for (int j = 0; j < 10; j++) {
        printf("%3d\t%3d\n", j + 1, n_digits[j]);
    }
    printf("Other:\t%d\n", n_other);
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}