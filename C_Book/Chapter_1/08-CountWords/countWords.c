#include <stdio.h>

/*Count the words, lines and chars in the input*/

#define IN      0   // in the word
#define OUT     1   // out of the word

int main () {

    printf("Count the words, lines and chars in the input\nTo stop, enter EOF\n");

    int c, wc, cc, lc, word;
    cc = wc = lc = 0;
    word = OUT;

    while (EOF != (c = getchar())) {
        cc++;
        if ((' ' == c || '\n' == c || '\t' == c) && IN == word) {
            word = OUT;
            wc++;
        }
        if (c == '\n') {
            lc++;
        }
        if (!(' ' == c || '\n' == c || '\t' == c)) {
            word = IN;
        }
    }        

    printf("\nWords: %d\n", wc);
    printf("Chars: %d\n", cc);
    printf("Lines: %d\n", lc);
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}