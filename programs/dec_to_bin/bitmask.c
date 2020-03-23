#include <stdio.h>
#include <stdint.h>

/*This program takes integer input and outputs the corresponding binary string
 * using bit masking and bit shifting*/

int main(uint8_t argc, char *argv[]) {

    if (argc == 2) {
        uint32_t number = 0;
        sscanf(argv[1], "%d", &number);
        
        uint16_t count = 1;
        for (int16_t i = 31; i >= 0; i--) {
            if ((number >> i) & 0x01) {
                printf("1");
            } else {
                printf("0");
            }
            if (count++ % 4 == 0) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        printf("Please enter one number!\n");
    }

    return 0;
}
