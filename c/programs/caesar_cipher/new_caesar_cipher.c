#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define STD_SHIFT    3
#define RANGE '~' - ' '
#define ARG_CHAR    '-'

#define ENCRYPT_ARG 'e'
#define DECRYPT_ARG 'd'
#define SHIFT_ARG   's'
#define INPUT_ARG   'i'
#define OUTPUT_ARG  'o'

#define ALL_ARGS    "edi:o:s:"

#define EMPTY_STR   "\0"

struct Arguments {
    int shift;
    bool do_encryption;
    char input_file_name[100], 
         output_file_name[100];
};

void encrypt(char input[], int shift, char output[]);
void decrypt(char input[], int shift, char output[]);
void input_en_decrypt(char action, int shift);
void sort_out_args(struct Arguments args);
bool is_digit(char c);
bool is_number(char str[]);

int main(uint8_t argc, char *argv[]) {

    struct Arguments args = {
        STD_SHIFT, 
        true, 
        EMPTY_STR, 
        EMPTY_STR
    };

    int opt;

    while ((opt = getopt(argc, argv, ALL_ARGS)) != -1) {
        switch (opt) {
            case 'e':
                args.do_encryption = true;
                break;
            case 'd':
                args.do_encryption = false;
                break;
            case 'i':
                if (sizeof(optarg) < sizeof(args.input_file_name)) {
                    strncpy(args.input_file_name, optarg, sizeof(args.input_file_name) - 1);
                }
                break;
            case 'o':
                if (sizeof(optarg) < sizeof(args.output_file_name)) {
                    strncpy(args.output_file_name, optarg, sizeof(args.output_file_name) - 1);
                }
                break;
            case 's':
                if (is_number(optarg)){
                    sscanf(optarg, "%d", &args.shift);
                } else {
                    fprintf(stderr, "%s: shift must be an integer\n", argv[0]);
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Usage: %s [-io] filename [-s] shift [-ed]\n", argv[0]);
            break;
        }
    }

    printf("%d | %d | %s - %s |\n", args.shift, args.do_encryption, args.input_file_name, args.output_file_name);

    if (strlen(args.input_file_name) > 4) {

        printf("input file\n");
    } else {
        printf("input cli\n");

    }

    if (args.do_encryption) {
        printf("encryption\n");

    } else {
        printf("decryption\n");

    }

    if (strlen(args.output_file_name) > 4) {

        printf("output file\n");
    } else {
        printf("output cli\n");

    }

    //sort_out_args(args);

    return 0;
}

bool is_number(char str[]) {
    if (*str == '-' || (*str >= '0' && *str <= '9')) {
        ++str;
        while (*str != 0) {
            if (!(*str >= '0' && *str <= '9')) {
                return false;
            }
            ++str;
        }
        return true;
    } else {
        return false;
    }
}

void input_en_decrypt(char action, int shift) {
    char input[500], output[500];
    if (action == ENCRYPT_ARG) {
        printf("Please enter the plain text: ");
        scanf("%[^\n]s", input);
        encrypt(input, shift, output);
        printf("The encrypted text is: \"%s\"\n", output);
    } else if (action == DECRYPT_ARG) {
        printf("Please enter the encrypted text: ");
        scanf("%[^\n]s", input);
        decrypt(input, shift, output);
        printf("The plain text is: \"%s\"\n", output);
    }
}

void encrypt(char input[], int shift, char output[]) {
    int result;
    while (*input != 0) {
        if (*input >= ' ' && *input <= '~') {
            result = ((*input - ' ') + shift);
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

void decrypt(char input[], int shift, char output[]) {
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

void sort_out_args(struct Arguments args) {
    char input[500], output[500];
    if (args.do_encryption) {
        printf("Please enter the plain text: ");
        scanf("%[^\n]s", input);
        encrypt(input, args.shift, output);
        printf("The encrypted text is: \"%s\"\n", output);
    } else {
        printf("Please enter the encrypted text: ");
        scanf("%[^\n]s", input);
        decrypt(input, args.shift, output);
        printf("The plain text is: \"%s\"\n", output);
    }
}
