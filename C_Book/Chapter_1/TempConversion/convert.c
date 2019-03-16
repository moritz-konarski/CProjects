#include <stdio.h>

#define START   0
#define END     300
#define STEP    20

main ()
{
    printf("deg F\tdeg C\n");
    for (int temp = START; temp <= END; temp += STEP)
        printf("%3d\t%5.1f\n", temp, (5.0 / 9.0) * (temp - 32)); 

    printf("\ndeg F\tdeg C\n");
    for (int temp = START; temp <= END; temp += STEP)
        printf("%3d\t%3d\n", 9 * temp / 5 + 32, temp); 
}