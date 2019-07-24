#include <stdio.h>

#define DAYS_IN_MON     30
#define DAYS_IN_YEAR    365

//compute the age from number of days

int main() {

    int days;
    scanf("%d", &days);
    int years = days / DAYS_IN_YEAR;
    int months = (days - years * DAYS_IN_YEAR) / DAYS_IN_MON;
    days = days - (years * DAYS_IN_YEAR + months * DAYS_IN_MON);
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", years, months, days);

    getchar();
    getchar();
    return 0;
}