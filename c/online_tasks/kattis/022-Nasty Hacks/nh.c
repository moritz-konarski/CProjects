#include <stdio.h>

/*determine if advertisement is worth it, given predicted revenue and ad cost*/

int main() {
    int n, re_no_ad, re_ad, ad_cost, diff;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &re_no_ad, &re_ad, &ad_cost);
        diff = re_no_ad - re_ad;

    }

    return 0;
}