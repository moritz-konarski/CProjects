#include <stdio.h>
#include <math.h>

/*say whether a number is even or odd*/

int main() {
    int input, iterations;

    scanf("%d", &iterations);
    
    for (int i = 0; i < iterations; i++) {
        scanf("%d", &input);
        if (abs(input) % 2 == 0) {
            printf("%d is even\n", input);
        } else {
            printf("%d is odd\n", input);
        }
    }

    return 0;
}