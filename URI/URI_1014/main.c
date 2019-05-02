#include <stdio.h>

/*calculate the average fuel consumption*/

int main() {
    int distance;
    double fuel_spent;
    scanf("%d\n%lf", &distance, &fuel_spent);
    printf("%.3lf km/l\n", distance / fuel_spent);
    return 0;
}