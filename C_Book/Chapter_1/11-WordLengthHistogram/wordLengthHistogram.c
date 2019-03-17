#include <stdio.h>

/*Measure the length of words and print a histogram*/
/*Lengths considered: 1, 2, 3, 4, 5, 6, 7, 8, 9, >9*/

#define IN  1
#define OUT 0

int main() {

    printf("Print Histogram of word length\n");

    int c, current_length = 0, in_word = OUT;

    // initialize array
    int word_length[10];
    for (int i = 0; i < 10; i++) {
        word_length[i] = 0;
    }

    // keep track of length of entered words
    while (EOF != (c = getchar())) {
        if ((' ' == c || '\t' == c || '\n' == c) && in_word == IN) {
            in_word = OUT;
            if (9 >= current_length) {
                word_length[current_length - 1]++;
            } else {
                word_length[9]++;
            }
            current_length = 0;
        }
        if (!(' ' == c || '\t' == c || '\n' == c)) {
            in_word = IN;
            current_length++;
        }
    }

    // print horizontal histogram
    printf("\nHistogram:\n");
    printf("length\tcount:\n");
    for (int j = 0; j < 9; j++) {
        printf("%d\t", j + 1);
        for (int k = 0; k < word_length[j]; k++) {
            putchar('|');
        }
        putchar('\n');
    }
    printf(">9\t");
    for (int k = 0; k < word_length[9]; k++) {
        putchar('|');
    }
    putchar('\n');

    return 0;
}