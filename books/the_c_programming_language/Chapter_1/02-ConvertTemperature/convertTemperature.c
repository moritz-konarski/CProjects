#include <stdio.h>

/*Convert Fahrenheit to Celsius and vice versa*/

#define START   0       // start of the loop
#define END     300     // end of the loop
#define STEP    20      // step of the loop

int main () {

    printf("Rough Conversion Tables:\nFahrenheit <-> Celsius\n");

    printf("F\tC\n");
    for (int fahr = START; fahr <= END; fahr += STEP) {
        printf("%3d\t%5.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    printf("F\tC\n");
    for (int cels = START; cels <= END; cels += STEP) {
        printf("%3d\t%3d\n", 9 * cels / 5 + 32, cels);
    }
    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}