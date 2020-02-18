#include <stdio.h>

//split a given amount of money into their respective units of currency

int main() {

    int input, bill_count;
    int values[7] = {100, 50, 20, 10, 5, 2, 1};

    scanf("%d", &input);

    printf("%d\n", input);

    for (int i = 0; i < 7; i++) {
        bill_count = input / values[i];
        input = input - bill_count * values[i];
        printf("%d nota(s) de R$ %d,00\n", bill_count, values[i]);
    }

    return 0;
}