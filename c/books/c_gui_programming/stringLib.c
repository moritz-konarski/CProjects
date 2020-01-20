#include <stdio.h>
#include <string.h>

int main() {
    char s1[10] = "first";
    char s2[10] = "second";
    char s3[20];

    strcpy(s3, s1);
    strcat(s3, s2);

    printf("%s + %s = %s\n", s1, s2, s3);
    return 0;
}