#include <stdio.h>

/*return the number of chess pieces required to make a full set*/

int main() {
    
    int piece_count[6];
    int pieces[] = {1, 1, 2, 2, 2, 8};

    for (int n = 0; n < 6; n++) {
        scanf("%d", &piece_count[n]);
    }

    for (int n = 0; n < 6; n++) {
        printf("%d ", pieces[n] - piece_count[n]);
    }

    putchar('\n');

    return 0;
}