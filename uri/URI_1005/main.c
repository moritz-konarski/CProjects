#include <stdio.h>

/*Find the weghted  average of two doubles*/

int main() {
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    double result = (3.5 * a + 7.5 * b) / 11.0;
    printf("MEDIA = %.5lf\n", result);
    return 0;
}