#include <stdio.h>
#define PI 3.14159
/*Compute the area of various geometric shapes*/

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    // right triangle
    printf("TRIANGULO: %.3lf\n", a * c / 2);
    // cirlce
    printf("CIRCULO: %.3lf\n", PI * c * c);
    // trapezium
    printf("TRAPEZIO: %.3lf\n", (a + b) / 2 * c);
    // square
    printf("QUADRADO: %.3lf\n", b * b);
    // rectangle
    printf("RETANGULO: %.3lf\n", a * b);
    return 0;
}