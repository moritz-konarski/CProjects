#include <stdio.h>

/*calculate the impact factor: total citations / total number of articles; round up*/
/*Find the number of citations needed to reach some impact factor*/

int main() {
    int n_articles, impact_factor;

    scanf("%d %d", &n_articles, &impact_factor);

    printf("%d", (impact_factor - 1) * n_articles + 1);

    return 0;
}