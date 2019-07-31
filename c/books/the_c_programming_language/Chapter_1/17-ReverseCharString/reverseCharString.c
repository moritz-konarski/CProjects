#include <stdio.h>
#define MAXLINE 1000

/*A program that reads input lines and prints their reverse*/

int getLine(char line[], int limit);
void copy(char from[], char to[]);
void reverse(char line[], int length);

int main() {

    printf("Print the reverse of the input\nEnter EOF to exit\n");

    int length = 0;; 
    char line[MAXLINE];

    while ((length = getLine(line, MAXLINE)) > 0) {
        reverse(line, length);
        printf("%s", line);
    }

    printf("\nPress ENTER to exit");
    getchar();

    return 0;
}

/*  Reverses the given char string*/
void reverse(char line[], int length) {
    int temp;
    for (int i = 0; i < length / 2; i++) {
        temp = line[i];
        line[i] = line[length - i - 2];
        line[length - i - 2] = temp;
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

/*  Copies one array to the other until '\0' is found, the end of the input*/
void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}