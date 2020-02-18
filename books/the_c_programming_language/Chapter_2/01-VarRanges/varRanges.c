#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("The Ranges of different types:\n");
    printf("\nSigned Int:\t%d to %d\n", INT_MIN, INT_MAX);
    printf("\nUnsigned Int:\t%d to %x\n", 0, UINT_MAX);
    printf("\nSigned Short:\t%d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("\nUnsigned Short:\t%d to %d\n", 0, USHRT_MAX);
    printf("\nSigned Long:\t%ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("\nUnsigned Long:\t%ld to %x\n", 0, ULONG_MAX);
    printf("\nFloat:\t\t%f to %f\n", FLT_MIN, FLT_MAX);
    printf("\nLong:\t\t%f to %f\n", DBL_MIN, DBL_MAX);

    printf("\nPress ENTER to exit\n");
    getchar();
    return 0;
}