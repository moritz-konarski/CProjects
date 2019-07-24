#include <stdio.h>
#define MAXLINE 1000

/*A program that reads input lines and prints out the longest of them*/

int getLine(char line[], int limit);
void copy(char from[], char to[]);

int main() {

    printf("Print the longest line of input\nEnter EOF to exit\n");

    int max_length = 0, length = 0;
    char line[MAXLINE];
    char max_line[MAXLINE];

    while ((length = getLine(line, MAXLINE)) > 0) {
        if (MAXLINE == length) {
            
        }
        if (length > max_length) {
            max_length = length;
            copy(line, max_line);
        }
    }

    if (max_length > 0) {
        printf("\nLongest Line: \n%s", max_line);
    }

    printf("\nPress ENTER to exit\n");
    getchar();

    return 0;
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

/*  Copies one array to the other until '\0' is found, the end of the input*/
void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}