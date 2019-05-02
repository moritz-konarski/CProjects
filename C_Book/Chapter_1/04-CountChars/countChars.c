#include <stdio.h>

/* Counting all the chars in the input*/

int main () {

    printf("Count all chars\nTo stop, enter EOF\n");

    long count = 0;

    while (EOF != getchar()) {
        count++;
    }
    /*
    for (count = 0; EOF != getchar(); count++)
        ;
    */
    printf("\nThe count is: %ld\n", count);
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}