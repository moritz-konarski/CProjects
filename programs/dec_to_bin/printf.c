#include <stdio.h>
#include <stdint.h>

/*This program takes integer input and outputs the corresponding binary string
 * using printf and a switch statement*/

int main(uint8_t argc, char *argv[]) {

    if (argc == 2) {
        char result[12];
        char *pntr = result;
        uint32_t number = 0;
        sscanf(argv[1], "%d", &number);
        sprintf(result, "%08x", number);
        //for each hex digit
        while (*pntr != 0) {
            switch (*pntr) {
                case '0':
                    printf("0000 ");
                    break;
                case '1':
                    printf("0001 ");
                    break;
                case '2':
                    printf("0010 ");
                    break;
                case '3':
                    printf("0011 ");
                    break;
                case '4':
                    printf("0100 ");
                    break;
                case '5':
                    printf("0101 ");
                    break;
                case '6':
                    printf("0110 ");
                    break;
                case '7':
                    printf("0111 ");
                    break;
                case '8':
                    printf("1000 ");
                    break;
                case '9':
                    printf("1001 ");
                    break;
                case 'a':
                    printf("1010 ");
                    break;
                case 'b':
                    printf("1011 ");
                    break;
                case 'c':
                    printf("1100 ");
                    break;
                case 'd':
                    printf("1101 ");
                    break;
                case 'e':
                    printf("1110 ");
                    break;
                case 'f':
                    printf("1111 ");
                    break;
            }
            pntr++;
        }
        printf("\n");
    } else {
        printf("Please enter one number!\n");
    }

    return 0;
}
