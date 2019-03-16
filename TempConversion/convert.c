#include <stdio.h>

main ()
{
    for (int temp = 0; temp <= 300; temp += 20)
        printf("%d\t%6.2f\n", temp, (5.0 / 9) * (temp - 32)); 
}