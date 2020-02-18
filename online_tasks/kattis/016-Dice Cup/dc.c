#include <stdio.h>

/*given the number of faces of two dice, return the most likely face-values*/

int main() {
    int n, m, max = 0;

    scanf("%d %d", &n, &m);

    //intialize the arrays
    int value_count[n + m];
    
    for (int i = 0; i < n + m; i++) {
        value_count[i] = 0;
    }

    //count face sums
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            value_count[i + j - 1]++;
        }
    }
    //find max sum
    for (int k = 0; k < n + m; k++) {
        max = (max < value_count[k]) ? value_count[k] : max;
    }
    //print all max sums
    for (int v = 0; v < n + m; v++) {
        if (value_count[v] == max) {
            printf("%d\n", (v + 1));
        }
    }

    return 0;
}