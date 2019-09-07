#include <stdio.h>
#include <stdint.h>

#define SHIFT 3
#define RANGE '~' - ' '
#define ARG_CHAR    '-'
#define ENCRYPT_ARG 'e'
#define DECRYPT_ARG 'd'
#define SHIFT_ARG   's'

void encrypt(char input[], int16_t shift, char output[]);
void decrypt(char input[], int16_t shift, char output[]);
void input_en_decrypt(char action, int16_t shift);

int main(uint8_t argc, char *argv[]) {
    int shift_input = 0;
    char argument = 'a';
    switch (argc) {
    // no extra arguments given - encrypt only
        case 1:
            input_en_decrypt(ENCRYPT_ARG, SHIFT);
            break;
    // one argument given - either decrpyt or encrypt
        case 2:
            for (uint8_t i = 1; i < argc; i++) {
                if (argv[i][0] == ARG_CHAR) {
                    // if encrypt / decrypt command given
                    if (argv[i][1] == ENCRYPT_ARG || argv[i][1] == DECRYPT_ARG) {
                        input_en_decrypt(argv[i][1], SHIFT);
                    }
                    break;
                }
            }
            break;
        case 3:
    // two arguments given - set the encryption key
            for (uint8_t i = 1; i < argc; i++) {
                if (argv[i][0] == ARG_CHAR) {
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
    // three arguments given - set key and de or encrypt
        case 4:
            for (uint8_t i = 1; i < argc; i++) {
                switch (argv[i][0]) {
                    case ARG_CHAR:
                        switch (argv[i][1]) {
                            case SHIFT_ARG:
                                if (i + 1 < argc) {
                                    sscanf(argv[i+1], "%d", &shift_input);
                                }
                                break;
                            case DECRYPT_ARG:
                            case ENCRYPT_ARG:
                                argument = argv[i][1];
                                break;
                        }
                        break;
                }
            }
            if (argument == DECRYPT_ARG || argument == ENCRYPT_ARG) {
                input_en_decrypt(argument, shift_input);
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
        printf("The encrypted text is: \"%s\"\n", output);
    } else if (action == 'd') {
        printf("Please enter the encrypted text: ");
        scanf("%[^\n]s", input);
        decrypt(input, shift, output);
        printf("The plain text is: \"%s\"\n", output);
    }
}

void encrypt(char input[], int16_t shift, char output[]) {
    int result;
    while (*input != 0) {
        if (*input >= ' ' && *input <= '~') {
            result = ((*input - ' ') + shift);
            printf("%d\n", result);
            if (result < 0) {
                result += RANGE;
            }
            *output = result % (RANGE) + ' ';
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}

void decrypt(char input[], int16_t shift, char output[]) {
    int result;
    printf("%s\n", input);
    while (*input != 0) {
        if (*input >= ' ' && *input <= '~') {
            result = ((*input - ' ') - shift);
            if (result < 0) {
                result += RANGE;
            }
            *output = result % (RANGE) + ' ';
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
    }