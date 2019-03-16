#include <stdio.h>

main ()
{
    int c;
    int newlines, tabs, spaces;
    newlines = tabs = spaces = 0;
    
    while ((c = getchar()) != EOF)
        if (c == '\n')
            newlines++;
        else if (c == '\t')
            tabs++;
        else if (c == ' ')
            spaces++;

    printf("\nLine count:\t%d\n", newlines);
    printf("Tab count:\t%d\n", tabs);
    printf("Space count:\t%d\n", spaces);
}