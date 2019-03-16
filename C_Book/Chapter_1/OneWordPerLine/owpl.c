#include <stdio.h>

#define IN  1
#define OUT 0

int main ()
{
    int c, inWord = OUT;

    while ((c = getchar()) != EOF)
    {
        if (inWord == IN && (c == ' ' || c == '\n' || c == '\t'))
        {
            putchar('\n');
            inWord = OUT;
        }
        if (!(c == ' ' || c == '\n' || c == '\t'))
        {
            putchar(c);
            inWord = IN;
        }
    }
    return 0;
}