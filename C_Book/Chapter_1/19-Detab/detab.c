#include <stdio.h>

/*A prgram that replaces all tabs with the appropriate amount of spaces*/

#define COLSPERTAB  8   // number of columns per tab in windows cmd.exe
#define MAXLINE     1000    // max chars per line

void replaceTabs(char line[], int length);
int getLine(char line[], int limit);

int main() {

    int length = 0;
    char line[MAXLINE];

    while ((length = getLine(line, MAXLINE)) > 0) {
        replaceTabs(line, length);
        printf("%s", line);
    }

    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}

/*  Replace each tab by spaces*/
void replaceTabs(char line[], int length) {
    int i = 0, offset;
    while ('\0' != line[i]) {
        if ('\t' == line[i]) {
            line[i] = ' ';
            i++;
            offset = COLSPERTAB - (i % COLSPERTAB) - 2;
            for (int j = length; j >= i; j--) {
                line[j + offset] = line[j];
            }
            while (i % COLSPERTAB != 0) {
                line[i] = ' ';
                i++;
            }
        } else {
            i++;
        }
    }
}

/*  Reads a line of input until '\n' or EOF and returns its length
    Input is written to the supplied array; writes '\0' as last character*/
int getLine(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if ('\n' == c) {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}