#include <stdio.h>

/*A rewrite of 02, now with functions*/

#define START   0
#define END     300
#define STEP    20

double fahrToCels(double fahr);
double celsToFahr(double cels);

int main() {

    printf("Fahr\tCels\n");
    for (int fahr = START; fahr <= END; fahr += STEP) {
        printf("%3d\t%5.1f\n", fahr, fahrToCels(fahr));
    }
    putchar('\n');
    printf("Fahr\tCels\n");
    for (int cels = START; cels <= END; cels += STEP) {
        printf("%3.0f\t%3d\n", celsToFahr(cels), cels);
    }

    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}

double fahrToCels(double fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}

double celsToFahr(double cels) {
    return (9.0 / 5.0) * cels + 32;
}