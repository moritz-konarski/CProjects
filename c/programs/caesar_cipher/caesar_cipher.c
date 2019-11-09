#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define STD_SHIFT    3
#define STR_LEN     500
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

void caesar_shift(struct Arguments, char input[], char output[]);
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

    //printf("%d | %d | %s - %s |\n", args.shift, args.do_encryption, args.input_file_name, args.output_file_name);

    char input[STR_LEN], output[STR_LEN];
    if (strlen(args.input_file_name) >= 3) {
        // input file and output file are given
        if (strlen(args.output_file_name) >= 3) {
            FILE * output_file;
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            output_file = fopen(args.output_file_name, "a");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                caesar_shift(args, input, output);
                fputs(output, output_file);
            }
            fclose(input_file);
            fclose(output_file);
        // only input file is given
        } else {
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                caesar_shift(args, input, output);
                printf("%s", output);
            }
            fclose(input_file);
        }
    } else {
        // only output file is given
        if (strlen(args.output_file_name) >= 3) {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            caesar_shift(args, input, output);
            FILE * output_file;
            output_file = fopen(args.output_file_name, "a");
            fputs(output, output_file);
            fclose(output_file);
        // no files are given
        } else {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            caesar_shift(args, input, output);
            printf("The result is: \"%s\"\n", output);
        }
    }

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

void caesar_shift(struct Arguments args, char input[], char output[]) {
    int result;
    if (args.do_encryption) {
        while (*input != 0) {
            if (*input >= ' ' && *input <= '~') {
                result = ((*input - ' ') + args.shift);
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
    } else {
        while (*input != 0) {
            if (*input >= ' ' && *input <= '~') {
                result = ((*input - ' ') - args.shift);
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
}

/*
// encrypts the given string using the caesar cipher and shift
void encrypt(char input[], int shift, char output[]) {
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

// decrypts the given string using the caesar cipher and shift
void decrypt(char input[], int shift, char output[]) {
    encrypt(input, -shift, output);
}
*/
