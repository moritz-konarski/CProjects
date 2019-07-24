#include <stdio.h>
#define MAXLINE 1000

/*A program that reads input lines and trims unnecessary spaces*/

int getLine(char line[], int limit);
void copy(char from[], char to[]);
void trim(char line[], int length); 

int main() {

    printf("Trim the input lines before output\nEnter EOF to exit\n");

    int length = 0;; 
    char line[MAXLINE];

    while ((length = getLine(line, MAXLINE)) > 0) {
        trim(line, length);
        printf("%s", line);
    }

    printf("\nPress ENTER to exit");
    getchar();

    return 0;
}

/*  Removes leading and trailing spaces and deletes blank lines*/
void trim(char line[], int length) {
    // trim leading spaces
    int i = 0, index = 0;
    while ('\0' != line[i] && (' ' == line[i] || '\t' == line[i])) {
        i++;
    }
    while ('\0' != line[index]) {
        line[index] = line[index + i];
        index++;
    }
    // trim trailing spaces
    i = length - 1;
    while (' ' == line[i] || '\t' == line[i] || '\n' == line[i]) {
        i--;
    }
    line[i + 1] = '\n';
    line[i + 2] = '\0';
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