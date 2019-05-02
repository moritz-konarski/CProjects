#include <stdio.h>

/*count to n and say Abracadabra each time*/

int main() {
    int number, index = 0;
    char text[] = "Abracadabra";

    scanf("%d", &number);

    while (index++ < number) {
        printf("%d %s\n", index, text);
    }

    return 0;
}