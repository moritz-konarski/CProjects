#include <stdio.h>

/*compute the last digit of some factorial*/

int main() {
    int test_cases, test_number, result;

    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        scanf("%d", &test_number);
        result = 1;

        while (test_number - 1) {
            result = (result * test_number--) % 10;
        }
        printf("%d\n", result);
    }

    return 0;
}