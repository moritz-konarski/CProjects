#include <stdio.h>
#define PI  3.14159

/*Compute the Area of a circle and print it out*/

int main() {
    double radius;
    scanf("%lf", &radius);
    printf("A=%.4lf\n", radius * radius * PI);
    return 0;
}