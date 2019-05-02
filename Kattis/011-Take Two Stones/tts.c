#include <stdio.h>

/*determine who wins a stupid game, if the number is odd, Alice wins*/

int main() {
    int n_stones;

    scanf("%d", &n_stones);

    printf("%s\n", (n_stones % 2 == 0) ? "Bob" : "Alice");

    return 0;
}