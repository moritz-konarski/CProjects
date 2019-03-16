#include <stdio.h>

/*Print each of the words in the input on a separate line*/

#define IN  1   //in the word
#define OUT 0   //out of the word

int main () {

    printf("Prints out one word of input per line\n");

    int c, inWord = OUT;

    while (EOF != (c = getchar())) {
        if (IN == inWord && (' ' == c || '\n' == c || '\t' == c)) {
            putchar('\n');
            inWord = OUT;
        }
        if (!(' ' == c || '\n' == c || '\t' == c)) {
            putchar(c);
            inWord = IN;
        }
    }
    return 0;
}