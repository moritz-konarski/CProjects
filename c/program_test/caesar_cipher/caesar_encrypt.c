#include <stdio.h>
#include <stdint.h>
#define MIN 32
#define MAX 126
#define SHIFT 3

void encrypt(char input[], char output[]);
void decrypt(char input[], int16_t shift, char output[]);

int main(uint8_t argc, char *argv[]) {
    char input[500], output[500];

    if (argc == 1) {
        printf("Please enter the plain text: ");
        scanf("%s", input);

        encrypt(input, output);
        printf("The encrypted text is: %s\n", output);

    } else if (argc == 2) {
        //TODO: implement full file encryption
        printf("Feature not yet available.\n");

    } else if (argc == 3) {
        //TODO: implement full file encryption
        printf("Feature not yet available.\n");

    }


    return 0;
}

void encrypt(char input[], char output[]) {
    while (*input != 0) {
        if (*input >= MIN && *input <= MAX) {
            *output = (*input + SHIFT - MIN) % (MAX - MIN) + MIN;
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}

void decrypt(char input[], int16_t shift, char output[]) {

}
