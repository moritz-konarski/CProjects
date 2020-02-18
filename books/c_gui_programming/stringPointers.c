#include <stdio.h>

int main() {

    char s1[10] = "first";
    char s2[10] = "second";
    char s3[20];

    char *src, *dst;

    src = s1;
    dst = s3;

    while (0 != *src) {
        *dst = * src;
        src++;
        dst++;
    }

    src = s2;

    while (0 != *src) {
        *dst = * src;
        src++;
        dst++;
    }

    *dst = 0;

    printf("%s + %s = %s\n", s1, s2, s3);

    return 0;
}
