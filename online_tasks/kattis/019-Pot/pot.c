#include <stdio.h>
#include <math.h>

/*take input number, turn them in to (n / 10) ^ (n % 10) and sum them up*/

int main() {
    int n, input, base, power;
    long int sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        base = input / 10;
        power = input % 10;
        sum += pow(base, power);
    }

    printf("%d\n", sum);

    return 0;
}