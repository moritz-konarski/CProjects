#include <stdio.h>

/*Measure the length of words and print a horizontal histogram*/
/*Lengths considered: 1, 2, 3, 4, 5, 6, 7, 8, 9, >9*/

#define IN      1       // in a word
#define OUT     0       // not in a word
#define FACTOR  20      // max height for most words

int main() {

    printf("Print Histogram of word length\nTo stop enter EOF\n");

    int c, max_length = 0, current_length = 0, in_word = OUT;

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

    // find the highest char count
    for (int m = 0; m < 10; m++) {
        max_length = (word_length[m] > max_length) ? word_length[m] : max_length;
    }

    // print vertical histogram
    printf("\nHistogram:\n");

    for (int j = 0; j < 10; j++) {
        printf("%-3d", word_length[j]);
    }
    putchar('\n');

    // for each line
    for (int i = FACTOR; i >= 0; i--) {
        // for each count
        for (int j = 0; j < 10; j++) {
            if (FACTOR * word_length[j] / max_length >= i) {
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
    
    for (int j = 0; j < 9; j++) {
        printf("%d  ", j + 1);
    }

    printf(">9\n");
    
    // final exit
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}