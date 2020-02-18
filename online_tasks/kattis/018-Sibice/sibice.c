#include <stdio.h>
#include <math.h>

/*determine of x matches with length h fit into some matchbox*/

int main() {
    int box_width, box_height, match_length, n_matches, box_diagonal;

    scanf("%d %d %d", &n_matches, &box_width, &box_height);

    box_diagonal = sqrt(pow(box_width, 2) + pow(box_height, 2));

    for (int i = 0; i < n_matches; i++) {
        scanf("%d", &match_length);
        printf("%s\n", (match_length <= box_diagonal) ? "DA" : "NE");
    }

    return 0;
}