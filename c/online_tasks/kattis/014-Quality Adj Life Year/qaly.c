#include <stdio.h>

/*sum up the products of quality of life and duration to find lifetime stats*/

int main() {
    int iteration;
    double quality, duration, sum = 0;

    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%lf %lf", &quality, &duration);
        sum += quality * duration;
    }

    printf("%.3lf\n", sum);

    return 0;
}