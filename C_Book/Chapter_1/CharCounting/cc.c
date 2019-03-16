#include <stdio.h>

main ()
{
    long count = 0;

    while (getchar() != EOF)
        count++;
    /*
    for (count = 0; getchar() != EOF; count++)
        ;
    */
    printf("\nThe count is: %ld\n", count);
}