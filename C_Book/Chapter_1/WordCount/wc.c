#include <stdio.h>

#define IN      0
#define OUT     1

int main ()
{
    int c, wc = 0, cc = 0, lc = 0, word = OUT;

    while ((c = getchar()) != EOF)
    {
        cc++;
        if ((c == '\t' || c == ' ' || c == '\n') && word == IN)
        {
            word = OUT;
            wc++;
        }
        if (c == '\n')
            lc++;
        if (!(c == '\t' || c == ' ' || c == '\n'))
            word = IN;
    }        

    printf("\nWords: %d\n", wc);
    printf("Chars: %d\n", cc);
    printf("Lines: %d\n", lc);

    return 0;
}