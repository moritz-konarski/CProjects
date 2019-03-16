#include <stdio.h>

main ()
{
    int c, spaceCount = 0;

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ')
        {
            spaceCount++;
            if (spaceCount < 2)            
                putchar(c);
        }
        else
        {
            spaceCount = 0;
            putchar(c);
        }        
    }
}