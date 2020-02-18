#include <stdio.h>
#include <string.h>

int main() {
    char s1[10] = "first";
    char s2[10] = "first";

    if (strcmp(s1, s2) == 0) {
        printf("The two strings are identical\n");
    } else {
        printf("The two strings are not identical\n");
    }

    return 0;
}