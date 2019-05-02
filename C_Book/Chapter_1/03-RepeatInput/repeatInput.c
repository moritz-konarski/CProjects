#include <stdio.h>

/* Repeat all the input and print it out like given*/

int main() {

    printf("Repeat all the input back\nTo stop, enter EOF\n");

    int c;
    while (EOF != (c = getchar())) { 
        putchar(c);
    }
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}