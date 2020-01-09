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

// TODO: add a string encode and a number encode
void base64_encode(struct Arguments, uint8_t input[], char output[], int input_len);
void encode_triplet(uint32_t triplet, char output[]);
char get_char(uint8_t num); 

int main(uint8_t argc, char *argv[]) {

    /*
    uint64_t test =      1010010101010010100101010010101010010100101001010010101001010100;
    char test_str[70] = "1010010101010010100101010010101010010100101001010010101001010100";
    char test_code[70];
    */

    struct Arguments args = {
        true,
        EMPTY_STR, 
        EMPTY_STR
    };
    
   // base64_encode(args, test_str, test_code);

    //printf("binary: %s\n", test_str);


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
    int len;
    if (strlen(args.input_file_name) >= 3) {
        // input file and output file are given
        if (strlen(args.output_file_name) >= 3) {
            FILE * output_file;
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            output_file = fopen(args.output_file_name, "a");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                base64_encode(args, input, output, strlen(input));
                fputs(output, output_file);
            }
            fclose(input_file);
            fclose(output_file);
        // only input file is given
        } else {
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            while (fgets(input, STR_LEN, input_file) != NULL) {
                base64_encode(args, input, output, strlen(input));
                printf("%s", output);
            }
            fclose(input_file);
        }
    } else {
        // only output file is given
        if (strlen(args.output_file_name) >= 3) {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            base64_encode(args, input, output, strlen(input));
            FILE * output_file;
            output_file = fopen(args.output_file_name, "a");
            fputs(output, output_file);
            fclose(output_file);
        // no files are given
        } else {
            printf("Please enter the text: ");
            scanf("%[^\n]s", input);
            base64_encode(args, input, output, strlen(input));
            printf("The result is: \"%s\"\n", output);
        }
    }

    return 0;
}

// does the encoding or decoding of a string
void base64_encode(struct Arguments args, uint8_t input[], char output[], int input_len) {
    char function_output[4];
    uint32_t triplet;
    int n_triplets = (input_len % 3 == 0) ? input_len / 3 : input_len / 3 + 1;
    uint8_t missing_triplets;

    printf("%d\n", input_len);
    printf("%d\n", n_triplets);
    printf("%s\n", input);

    int i = 0;
    // step through all the triplets
    for (; i < n_triplets - 1; ++i) {
        triplet = 0;
        // for each element in the triplet
        for (uint8_t j = 0; j < 3; ++j) {
            if (3*i+j < input_len) {
                printf("in: %x\n", input[3*i+j]);
                triplet |= (input[3 * i + j] << (0x08 * (3 - j)));
            }
        }
        printf("tr: %x\n", triplet);
        encode_triplet(triplet, function_output);
        for (uint8_t j = 0; j < 4; ++j) {
            output[4*i+j] = function_output[j];
        }
    }
    i = n_triplets - 1;
    triplet = 0;
    missing_triplets = 0;
    // for each element in the triplet
    for (uint8_t j = 0; j < 3; ++j) {
        if (3*i+j < input_len) {
            printf("in: %x\n", input[3*i+j]);
            triplet |= (input[3 * i + j] << (0x08 * (3 - j)));
        } else {
            ++missing_triplets;
        }
    }
    printf("tr: %x\n", triplet);
    printf("mt: %d\n", missing_triplets);
    encode_triplet(triplet, function_output);
    for (uint8_t j = 0; j < 4 - missing_triplets; ++j) {
        output[4*i+j] = function_output[j];
    }
    for (uint8_t j = 4 - missing_triplets; j < 4; ++j) {
        output[4*i+j] = '=';
    }

    output[4 * n_triplets] = '\0';
}

// encode individual triplets of input characters
void encode_triplet(uint32_t triplet, char output[]) {
    for (uint8_t i = 0; i < 4; ++i) {
        // convert the parts of the triple into the respective characters
        printf("- %d\n", (triplet >> ((3 - i) * 0x06) + 0x08) & 0x3f);
        output[i] = get_char((triplet >> ((3 - i) * 0x06) + 0x08) & 0x3f);
    }
}

// returns the character for the Base64 encoding
char get_char(uint8_t num) {
    if (num <= 25) {
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
