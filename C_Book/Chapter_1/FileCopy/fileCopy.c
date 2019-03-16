#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF) 
        putchar(c);

    // prints -1, the value of EOF
    printf("%d", EOF);
}