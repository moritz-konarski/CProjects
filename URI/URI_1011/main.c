#include <stdio.h>
#define PI 3.14159

/*calculate the volume of sphere*/

int main() {
    double radius, volume;
    scanf("%lf", &radius);
    volume = pow(radius, 3) * 4.0 / 3.0 * PI;
    printf("VOLUME = %.3lf\n", volume);
    return 0;
}