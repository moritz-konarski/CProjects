#include <stdio.h>

/*find the winner of a culinary show m sum of all points and return # and score*/

int main() {
    int n_participants = 5, scores[5], max_score, input;

    for (int m = 0; m < n_participants; m++) {
        scores[m] = 0;
    }

    for (int i = 0; i < n_participants; i++) {
        for (int j = 0; j < n_participants - 1; j++) {
            scanf("%d", &input);
            scores[i] += input;
        }
    }
    for (int k = 0; k < n_participants; k++) {
        max_score = (max_score < scores[k]) ? scores[k] : max_score;
    }

    for (int m = 0; m < n_participants; m++) {
        if (scores[m] == max_score) {
            input = m + 1;
        }
    }

    printf("%d %d\n", input, max_score);

    return 0;
}