#include <stdio.h>

/*calculate amount to be paid like a POS-System*/

int main() {
    int code, quantity;
    double price, result;
    scanf("%d %d %lf", &code, &quantity, &price);
    result = quantity * price;
    scanf("%d %d %lf", &code, &quantity, &price);
    result += quantity * price;
    printf("VALOR A PAGAR: R$ %.2lf\n", result);
    return 0;
}