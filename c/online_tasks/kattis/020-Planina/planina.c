#include <stdio.h>
#include <math.h>

/*determine the number of intersections of lines if you divide a square into 4 squares with each iteration*/

int main() {
    int iterations;

    scanf("%d", &iterations);

    printf("%d\n", (int) (pow(pow(2, iterations) + 1, 2)));

    return 0;
}