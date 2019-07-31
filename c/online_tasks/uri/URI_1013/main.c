#include <stdio.h>
int major(int a, int b);

/*print the largest integer value*/

int main() {

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d eh o maior\n", major(a, major(b , c)));
    return 0;
}

int major(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}