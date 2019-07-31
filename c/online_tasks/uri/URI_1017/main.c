#include <stdio.h>

#define KM_L    12.0

//how much fuel is spent given usage, time and average speed

int main() {

    int duration, average_speed;
    scanf("%d\n%d", &duration, &average_speed);
    printf("%.3lf\n", duration * average_speed / KM_L);

    return 0;
}