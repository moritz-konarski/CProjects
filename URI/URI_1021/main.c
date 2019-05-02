#include <stdio.h>

/*split a quantity of money into bill and coins and print their counts*/

int main() {

    int rial, cents, count;
    int bills[] = {100, 50, 20, 10, 5, 2}, coins[] = {50, 25, 10, 5, 1};

    scanf("%d.%d", &rial, &cents);

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        count = rial / bills[i];
        rial -= count * bills[i];
        printf("%d nota(s) de R$ %d.00\n", count, bills[i]);
    }

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", rial);

    for (int i = 0; i < 5; i++) {
        count = cents / coins[i];
        cents -= count * coins[i];
        printf("%d moeda(s) de R$ 0.%02d\n", count, coins[i]);
    }

    return 0;
}