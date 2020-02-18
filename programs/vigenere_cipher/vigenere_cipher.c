#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define STD_KEYWORD "Vigenere"
#define STR_LEN     500 
#define NAME_LEN    100
#define FIRST_CHAR  ' '
#define LAST_CHAR   '~'
#define RANGE LAST_CHAR - FIRST_CHAR
#define ARG_CHAR    '-'

#define ENCRYPT_ARG 'e'
#define DECRYPT_ARG 'd'
#define KEYWORD_ARG 'k'
#define INPUT_ARG   'i'
#define OUTPUT_ARG  'o'

#define ALL_ARGS    "edi:o:k:"

#define EMPTY_STR   "\0"

struct Arguments {
    bool do_encryption;
    char input_file_name[NAME_LEN], 
         output_file_name[NAME_LEN],
         keyword[NAME_LEN];
};

void vigenere_cipher(struct Arguments, char input[], char output[], int index);

int main(uint8_t argc, char *argv[]) {

    struct Arguments args = {
        true, 
        EMPTY_STR, 
        EMPTY_STR,
        STD_KEYWORD
    };

    int opt;

    while ((opt = getopt(argc, argv, ALL_ARGS)) != -1) {
        switch (opt) {
            case ENCRYPT_ARG:
                args.do_encryption = true;
                break;
            case DECRYPT_ARG:
                args.do_encryption = false;
                break;
            case INPUT_ARG:
                if (strlen(optarg) < sizeof(args.input_file_name)) {
                    strncpy(args.input_file_name, optarg, sizeof(args.input_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: name of input file must be less than %ld characters\n", argv[0], sizeof(args.input_file_name));
                    return 1;
                }
                break;
            case OUTPUT_ARG:
                if (strlen(optarg) < sizeof(args.output_file_name)) {
                    strncpy(args.output_file_name, optarg, sizeof(args.output_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: name of output file must be less than %ld characters\n", argv[0], sizeof(args.output_file_name));
                    return 1;
                }
                break;
            case KEYWORD_ARG:
                if (strlen(optarg) < sizeof(args.keyword)) {
                    strncpy(args.keyword, optarg, sizeof(args.keyword) - 1);
                } else {
                    fprintf(stderr, "%s: keyword must be less than %ld characters\n", argv[0], sizeof(args.keyword));
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Usage: %s [-io] filename [-k] keyword [-ed]\n", argv[0]);
            break;
        }
    }

    //printf("%d | %d | %s - %s |\n", args.shift, args.do_encryption, args.input_file_name, args.output_file_name);

    char input[STR_LEN], output[STR_LEN];
    int index = 0;
    if (strlen(args.input_file_name) >= 3) {
        // input file and output file are given
        if (strlen(args.output_file_name) >= 3) {
            FILE * output_file;
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            output_file = fopen(args.output_file_name, "a");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                vigenere_cipher(args, input, output, index);
                fputs(output, output_file);
            }
            fclose(input_file);
            fclose(output_file);
        // only input file is given
        } else {
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                vigenere_cipher(args, input, output, index);
                printf("%s", output);
            }
            fclose(input_file);
        }
    } else {
        // only output file is given
        if (strlen(args.output_file_name) >= 3) {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            vigenere_cipher(args, input, output, index);
            FILE * output_file;
            output_file = fopen(args.output_file_name, "a");
            fputs(output, output_file);
            fclose(output_file);
        // no files are given
        } else {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            vigenere_cipher(args, input, output, index);
            printf("The result is: \"%s\"\n", output);
        }
    }

    return 0;
}

void vigenere_cipher(struct Arguments args, char input[], char output[], int index) {
    int keyword_len = strlen(args.keyword),
        result, 
        shift, 
        sign = args.do_encryption ? 1 : -1;
    while (*input != 0) {
        if (*input >= FIRST_CHAR && *input <= LAST_CHAR) {
            shift = args.keyword[index] - FIRST_CHAR;
            ++index;
            if (index == keyword_len) {
                index = 0;
            }
            result = ((*input - FIRST_CHAR) + sign * shift);
            if (result < 0) {
                result += RANGE;
            }
            *output = result % (RANGE) + FIRST_CHAR;
        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}
