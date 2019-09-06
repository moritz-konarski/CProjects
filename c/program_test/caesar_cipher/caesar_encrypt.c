#include <stdio.h>
#include <stdint.h>

#define SHIFT 3
#define RANGE '~' - ' '

void encrypt(char input[], int16_t shift, char output[]);
void decrypt(char input[], int16_t shift, char output[]);

int main(uint8_t argc, char *argv[]) {
    //the input and output strings
    char input[500], output[500];

    if (argc == 1) {
        printf("Please enter the plain text: ");
        scanf("%s", input);

        encrypt(input, SHIFT, output);
        printf("The encrypted text is: %s\n", output);

    } else if (argc == 2) {
        //TODO: implement full file encryption
        printf("Feature not yet available.\n");

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
