#include <stdio.h>
#define MAXLINE 1000
int max_length = 0;
char line[MAXLINE];
char max_line[MAXLINE];

/*A program that reads input lines and prints out the longest of them*/
/*This not uses external variables now*/

int getLine(void);
void copy(void);

int main() {

    printf("Print the longest line of input\nEnter EOF to exit\n");

    int length = 0;
    extern int max_length;
    extern char max_line[];
    max_length = 0;

    while ((length = getLine()) > 0) {
        if (length > max_length) {
            max_length = length;
            copy();
        }
    }

    if (max_length > 0) {
        printf("\nLongest Line: \n%s", max_line);
    }

    printf("\nPress ENTER to exit");
    getchar();

    return 0;
}

/*  Reads a line of input until '\n' or EOF and returns its length
    Input is written to the supplied array; writes '\0' as last character*/
int getLine(void) {
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
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
void copy(void) {
    int i = 0;
    extern char line[], max_line[];
    while ((max_line[i] = line[i]) != '\0') {
        i++;
    }
}
