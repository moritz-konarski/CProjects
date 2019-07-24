#include <stdio.h>
#define RATIO   0.15

/*calculate a salry with 15% bonus on sales*/

int main() {
    double salary, sales;
    char name[100];
    scanf("%s", &name);
    scanf("%lf", &salary);
    scanf("%lf", &sales);
    printf("TOTAL = R$ %.2lf\n", salary + RATIO * sales);
    return 0;
}