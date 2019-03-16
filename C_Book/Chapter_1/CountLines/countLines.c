#include <stdio.h>

/*Counts all new lines, tabs and spaces in the input*/

int main () {

    printf("Count all new lines, spaces and tabs\n");

    int c, newlines, tabs, spaces;
    newlines = tabs = spaces = 0;
    
    while (EOF != (c = getchar())) {
        if ('\n' == c) {
            newlines++;
        } else if ('\t' == c) {
            tabs++;
        } else if (' ' == c) {
            spaces++;
        }
    }

    printf("\nLine count:\t%d\n", newlines);
    printf("Tab count:\t%d\n", tabs);
    printf("Space count:\t%d\n", spaces);

    return 0;
}