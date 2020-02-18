#include <stdio.h>

/*calculate the distance between two points*/

int main() {
    double x1, x2, y1, y2;
    scanf("%lf %lf\n%lf %lf", &x1, &y1, &x2, &y2);
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("%.4lf\n", distance);
    return 0;
}