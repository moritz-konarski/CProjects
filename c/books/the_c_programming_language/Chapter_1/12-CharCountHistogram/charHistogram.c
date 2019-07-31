#include <stdio.h>

/*This program creates a Histogram of characters from a - z*/

#define LEN     27
#define FACTOR  20

int main () {

    printf("Create a histogram of characters in the input\nTo stop enter EOF\n");

    int c, max_length = 0;
    int char_count[LEN];

    for (int i = 0; i < LEN; i++) {
        char_count[i] = 0;
    }

    while (EOF != (c = getchar())) {
        if (' ' == c) {
            char_count[0]++;
        } else if (c >= 'a' && c <= 'z') {
            char_count[c - 'a' + 1]++;
        } else if (c >= 'A' && c <= 'Z') {
            char_count[c - 'A' + 1]++;
        }
    }

    for (int j = 0; j < LEN; j++) {
        max_length = (char_count[j] > max_length) ? char_count[j] : max_length;
    }

    // print vertical histogram
    printf("\nHistogram:\n\n");

    // for each line
    for (int i = FACTOR + 1; i > 0; i--) {
        // for each count
        for (int j = 0; j < LEN; j++) {
            putchar(' ');
            if (FACTOR * char_count[j] / max_length >= i) {
                putchar('-');
            } else {
                putchar(' ');
            }
            putchar(' ');
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');

    printf("\' \'  ");
    for (int j = 0; j < LEN - 1; j++) {
        printf("%c   ", j + 'a');
    }
    putchar('\n');
    for (int j = 0; j < LEN; j++) {
        printf("%-4d", char_count[j]);
    }

    printf("\n\nPress ENTER to exit\n");
    getchar();
    return 0;
}