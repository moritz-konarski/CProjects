#include <stdio.h>

/*calculate the amount of data in the next months given the history and monthly given if it rolls over to the next month*/

int main() {
    int data_per_month, data_spent, data_next_month = 0, n_months;

    scanf("%d\n%d", &data_per_month, &n_months);

    while (n_months--) {
        scanf("%d", &data_spent);
        data_next_month += data_per_month - data_spent;
    }

    printf("%d\n", data_next_month + data_per_month);

    return 0;
}