#include <stdio.h>

#define MINUTES_PER_KM  2

/*how long it takes one car to move some distance in relation to another one*/

int main() {

    int distance;
    scanf("%d", &distance);
    printf("%d minutos\n", distance * MINUTES_PER_KM);

    return 0;
}