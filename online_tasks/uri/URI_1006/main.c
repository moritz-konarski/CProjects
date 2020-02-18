#include <stdio.h>

/*find the weighted average of three grades*/

int main() {
    double a, b ,c;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    double result = (2.0 * a + 3.0 * b + 5.0 * c) / 10.0;
    printf("MEDIA = %.1lf\n", result);
    return 0;
}