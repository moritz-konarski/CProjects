#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define STR_LEN     1000
#define NAME_LEN    100
#define INITIAL_CHAR ' '
#define RANGE LAST_CHAR - FIRST_CHAR
#define ARG_CHAR    '-'

#define INPUT_ARG   'i'
#define OUTPUT_ARG  'o'
#define ENCODE_ARG  'e'
#define DECODE_ARG  'd'

#define ALL_ARGS    "edi:o:"

#define EMPTY_STR   "\0"

struct Arguments {
    bool encode;
    char input_file_name[NAME_LEN], 
         output_file_name[NAME_LEN];
};

void base64_encode(struct Arguments, char input[], char output[]);
void encode_triplet(uint8_t input[], char output[], uint8_t input_len);
char get_char(uint8_t num); 

int main(uint8_t argc, char *argv[]) {

    /*
    char text[10] = "M";
    char output[20];

    encode_triplet(text, output, strlen(text));
    printf("%s\n", output);
    */

    struct Arguments args = {
        true, 
        EMPTY_STR, 
        EMPTY_STR
    };

    int opt;

    while ((opt = getopt(argc, argv, ALL_ARGS)) != -1) {
        switch (opt) {
            case ENCODE_ARG:
                args.encode = true;
                break;
            case DECODE_ARG: 
                args.encode = false;
                break;
            case INPUT_ARG:
                if (strlen(optarg) < sizeof(args.input_file_name)) {
                    strncpy(args.input_file_name, optarg, sizeof(args.input_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: input file name must be less than %ld characters\n", argv[0], sizeof(args.input_file_name));
                    return 1;
                }
                break;
            case OUTPUT_ARG:
                if (strlen(optarg) < sizeof(args.output_file_name)) {
                    strncpy(args.output_file_name, optarg, sizeof(args.output_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: input file name must be less than %ld characters\n", argv[0], sizeof(args.output_file_name));
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Usage: %s [-io] filename [-ed] encode/decode\n", argv[0]);
            break;
        }
    }

    char input[STR_LEN], output[STR_LEN];
    if (strlen(args.input_file_name) >= 3) {
        // input file and output file are given
        if (strlen(args.output_file_name) >= 3) {
            FILE * output_file;
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            output_file = fopen(args.output_file_name, "a");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                base64_encode(args, input, output);
                fputs(output, output_file);
            }
            fclose(input_file);
            fclose(output_file);
        // only input file is given
        } else {
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                base64_encode(args, input, output);
                printf("%s", output);
            }
            fclose(input_file);
        }
    } else {
        // only output file is given
        if (strlen(args.output_file_name) >= 3) {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            base64_encode(args, input, output);
            FILE * output_file;
            output_file = fopen(args.output_file_name, "a");
            fputs(output, output_file);
            fclose(output_file);
        // no files are given
        } else {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            base64_encode(args, input, output);
            printf("The result is: \"%s\"\n", output);
        }
    }

    return 0;
}

char get_char(uint8_t num) {
    if(num <= 25) {
        return num + 'A';
    } else if (num <= 51) {
        return num - 26 + 'a';
    } else if (num <= 61) {
        return num - 52 + '0';
    } else if (num == 62) {
        return '+';
    } else {
        return '/';
    }
}

//output must be 4/3 times the size of input
void base64_encode(struct Arguments args, char input[], char output[]) {
    uint8_t function_arg[3];
    char function_result[4];
    int input_index = 0,
        output_index = 0,
        n_chars = strlen(input),
        n_triplets = n_chars % 3,
        remainder = n_chars - 3*n_triplets;
    for (int i = 0; i < n_triplets; ++i) {
        for (uint8_t j = 0; j < 3; ++j) {
            function_arg[j] = input[3*i+j];
        }
        encode_triplet(function_arg, function_result, 3);
        for (uint8_t j = 0; j < 4; ++j) {
            output[4*i+j] = function_result[j];
        }
    }
    for (uint8_t j = 0; j < remainder; ++j) {
        function_arg[j] = input[3*n_triplets-1+j];
    }
    encode_triplet(function_arg, function_result, remainder);
    for (uint8_t j = 0; j < 4; ++j) {
        output[4*n_triplets-1+j] = function_result[j];
    }
    /*
    while (*input != 0) {
       function_arg[i] = *input;
       ++input_index;
       if (input_index == 2) {
           input_index = 0;
           encode_triplet(function_arg, function_result, 3);
           for (uint8_t i = 0; i < 4; ++i) {
               output[i] = function_result[i];
               ++output_index;
           }
       }
            result = ((*input - FIRST_CHAR) + sign * args.shift);
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
    */
}

void encode_triplet(uint8_t input[], char output[], uint8_t input_len) {
    uint8_t input_nums[3],
        output_count = 4;
    uint32_t triple = 0;
    for (uint8_t i = 0; i < input_len; ++i) {
        input_nums[i] = 0;
        input_nums[i] |= input[i];
    }
    for (uint8_t i = input_len; i < 3; ++i) {
        input_nums[i] = 0;
    }
    for (uint8_t i = 0; i < 3 ; ++i) {
        triple |= (input_nums[i] << (0x08 * (3 - i)));
    }
    if (input_len == 1) {
        output_count = 2;
    } else if (input_len == 2) {
        output_count = 3;
    }
    for (uint8_t i = 0; i < output_count; ++i) {
        output[i] = get_char((triple >> ((3 - i) * 0x06) + 0x08) & 0x3f);
    }
    for (uint8_t i = output_count; i < 4; ++i) {
        output[i] = '=';
    }
}
