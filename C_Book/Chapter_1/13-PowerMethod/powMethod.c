#include <stdio.h>

/*A program that uses a function to compute integer powers*/

int power(int base, int exponent);

int main() {

    int a, b;
    printf("Enter the base\t\t: ");
    a = getchar() - '0';
    getchar();
    printf("Enter the exponent\t: ");
    b = getchar() - '0';
    getchar();
    printf("Result\t\t\t: %d\n", power(a, b));

    printf("\nPress ENTER to exit\n");
    getchar();

    return 0;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}