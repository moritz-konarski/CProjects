#include <stdio.h>
#define OFFSET  45

/*take a time given to you and return one 45 min earlier, in 24h notation*/

int main() {
    int hours, minutes;

    scanf("%d %d", &hours, &minutes);

    if (minutes - OFFSET < 0) {
        minutes = minutes + 60 - OFFSET;
        hours = hours - 1;
        if (hours < 0) {
            hours = hours + 24;
        }
    } else {
        minutes = minutes - OFFSET;
    }

    printf("%d %d\n", hours, minutes);

    return 0;
}