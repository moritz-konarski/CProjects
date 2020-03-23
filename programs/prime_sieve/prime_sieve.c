#include <stdio.h>
#include <stdbool.h>

#define END 1000000

int main(int argc, char *argv[]) {

    bool is_crossed[END] = {false};
    unsigned long count = 1;

    printf("%8ld ", 2);

    for (unsigned long i = 3; i < END; i += 2) {
        if (!is_crossed[i]) {
            printf("%8ld ", i);
            ++count;
            if (count % 10 == 0) {
                printf("\n");
            }
            for (unsigned long j = 2 * i; j < END;) {
                is_crossed[j] = true;
                j += i;
            }
        }
    }

    printf("\n\nNumber of primes smaller than %ld: %ld\n", END, count);

    return 0;
}
