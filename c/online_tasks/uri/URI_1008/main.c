#include <stdio.h>

/*calculate the salary of an emplayee*/

int main() {
    int number, hours;
    double wage;
    scanf("%d", &number);
    scanf("%d", &hours);
    scanf("%lf", &wage);
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", number, wage * hours);
    return 0;
}