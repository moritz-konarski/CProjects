#include <stdio.h>

/* Repeat all the input and print it out like given*/

int main() {

    printf("Repeat all the input back\n");

    int c;
    while (EOF != (c = getchar())) { 
        putchar(c);
    }
    return 0;
}