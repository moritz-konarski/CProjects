#include <stdio.h>

/*return the smaller number flipped around*/

int main() {
    int x1, x2;

    scanf("%d %d", &x1, &x2);

    x1 = x1 - 99 * (x1 / 100 - x1 % 10);

    x2 = x2 - 99 * (x2 / 100 - x2 % 10);

    printf("%d", (x1 > x2) ? x1 : x2);

    return 0;
}