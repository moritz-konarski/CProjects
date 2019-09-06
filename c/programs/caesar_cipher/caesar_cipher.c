#include <stdio.h>
#include <stdint.h>

#define SHIFT 3
#define RANGE '~' - ' '
#define ENCRYPT_ARG 'e'
#define DECRYPT_ARG 'd'
#define SHIFT_ARG   's'

void encrypt(char input[], int16_t shift, char output[]);
void decrypt(char input[], int16_t shift, char output[]);
void input_en_decrypt(char action, int16_t shift);

int main(uint8_t argc, char *argv[]) {
    switch (argc) {
    // no extra arguments given
        case 1:
            input_en_decrypt(ENCRYPT_ARG, SHIFT);
            break;
    // one argument given
        case 2:
            for (uint8_t i = 1; i < argc; i++) {
                if (argv[i][0] == '-') {
                    // if encrypt / decrypt command given
                    if (argv[i][1] == ENCRYPT_ARG || argv[i][1] == DECRYPT_ARG) {
                        input_en_decrypt(argv[i][1], SHIFT);
                    }
                    break;
                }
            }
            break;
        case 3:
    // two arguments given
            for (uint8_t i = 1; i < argc; i++) {
                if (argv[i][0] == '-') {
                    //if a shift command is given
                    if (argv[i][1] == SHIFT_ARG && i + 1 < argc) {
                        int shift_input;
                        sscanf(argv[i+1], "%d", &shift_input);
                        input_en_decrypt(ENCRYPT_ARG, shift_input);
                    }
                    break;
                }
            }
            break;
    }

    return 0;
}

void input_en_decrypt(char action, int16_t shift) {
    char input[500], output[500];
    if (action == 'e') {
        printf("Please enter the plain text: ");
        scanf("%[^\n]s", input);
        encrypt(input, shift, output);
        printf("The encrypted text is: %s\n", output);
    } else if (action == 'd') {
        printf("Please enter the encrypted text: ");
        scanf("%[^\n]s", input);
        decrypt(input, shift, output);
        printf("The plain text is: %s\n", output);
    }
}

void encrypt(char input[], int16_t shift, char output[]) {
    while (*input != 0) {
        if (*input >= ' ' && *input <= '~') {
            *output = ((*input - ' ') + shift) % (RANGE) + ' ';
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}

void decrypt(char input[], int16_t shift, char output[]) {
    while (*input != 0) {
        if (*input >= ' ' && *input <= '~') {
            *output = ((*input - ' ') - shift) % (RANGE) + ' ';
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}
