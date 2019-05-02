#include <stdio.h>

#define S_P_H   3600
#define S_P_M   60

//convert seconds to h:m:s

int main() {

    int given_seconds, sec, min, h;

    scanf("%d", &given_seconds);

    sec = given_seconds % S_P_M;
    h = given_seconds / S_P_H;
    min = (given_seconds - h * S_P_H) / S_P_M;

    printf("%d:%d:%d\n", h, min, sec);

    return 0;
}