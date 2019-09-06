#include <stdio.h>
#include <stdint.h>

#define SHIFT 3
#define RANGE '~' - ' '

void encrypt(char input[], int16_t shift, char output[]);
void decrypt(char input[], int16_t shift, char output[]);
void process_simple_command(char action, int16_t shift);


char input[500], output[500];

int main(uint8_t argc, char *argv[]) {
    //the input and output strings

    if (argc == 1) {
        printf("Please enter the plain text: ");
        scanf("%[^\n]s", input);

        encrypt(input, SHIFT, output);
        printf("The encrypted text is: %s\n", output);

    } else if (argc == 2) {
        for (uint8_t i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                if (argv[i][1] == 'e') {
                    printf("Please enter the plain text: ");
                    scanf("%[^\n]s", input);

                    encrypt(input, SHIFT, output);
                    printf("The encrypted text is: %s\n", output);

                } else if (argv[i][1] == 'd') {
                    printf("Please enter the encrypted text: ");
                    scanf("%[^\n]s", input);

                    decrypt(input, SHIFT, output);
                    printf("The plain text is: %s\n", output);

                }
                break;
            }
        }
    } else if (argc == 3) {
        //find out which command it is
        for (uint8_t i = 1; i < argc; i++) {
            if (argv[i][0] == '-') {
                printf("- detected\n");
            }
        }
        //if there is a shift given

        //TODO: implement full file encryption

    }


    return 0;
}

void process_simple_command(char action, int16_t shift) {
    if (action == 'e') {
        printf("Please enter the plain text: ");
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
