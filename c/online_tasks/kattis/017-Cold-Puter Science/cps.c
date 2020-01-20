#include <stdio.h>

/*return the number of inputs that are less than 0*/

int main() {
    int input, count = 0, iterations;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; i++) {
        scanf("%d", &input);
        count = (input < 0) ? ++count : count;
    }

    printf("%d\n", count);

    return 0;
}