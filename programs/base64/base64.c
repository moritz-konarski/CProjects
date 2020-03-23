#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// numeric constants
#define IN_LEN      1332
#define OUT_LEN     1332
#define NAME_LEN    100

// character constants
#define ARG_CHAR    '-'
#define INPUT_ARG   'i'
#define OUTPUT_ARG  'o'
#define ENCODE_ARG  'e'
#define DECODE_ARG  'd'

#define ALL_ARGS    "edi:o:"

#define EMPTY_STR   "\0"

// structure for function arguments
struct Arguments {
    bool encode;
    char input_file_name[NAME_LEN], 
         output_file_name[NAME_LEN];
};

// encode any length of input
void base64_encode(struct Arguments, uint8_t input[], char output[], 
    int input_len);

// encode a single triplet
char encode_sextet(uint8_t num); 

int main(uint8_t argc, char *argv[]) {

    struct Arguments args = {
        true,       // standard is encode
        EMPTY_STR,  // standard is no input
        EMPTY_STR   // standard is no output
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
                    strncpy(args.input_file_name, optarg, 
                        sizeof(args.input_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: input file name must be less than %ld\\ 
                        characters\n", argv[0], sizeof(args.input_file_name));
                    return 1;
                }
                break;
            case OUTPUT_ARG:
                if (strlen(optarg) < sizeof(args.output_file_name)) {
                    strncpy(args.output_file_name, optarg, 
                        sizeof(args.output_file_name) - 1);
                } else {
                    fprintf(stderr, "%s: input file name must be less than %ld\\ 
                        characters\n", argv[0], sizeof(args.output_file_name));
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Usage: %s [-io] filename [-ed] encode/decode\\
                    \n", argv[0]);
            break;
        }
    }

    // input and output arrays
    uint8_t input[IN_LEN], output[OUT_LEN];
    // input file given
    if (strlen(args.input_file_name) >= 3) {
        // input file and output file are given
        if (strlen(args.output_file_name) >= 3) {
            FILE * output_file;
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            output_file = fopen(args.output_file_name, "a");
            while (fgets(input, IN_LEN, input_file) != NULL) {
                base64_encode(args, input, output, strlen(input));
                fputs(output, output_file);
            }
            fclose(input_file);
            fclose(output_file);
        // only input file is given
        } else {
            FILE * input_file;
            input_file = fopen(args.input_file_name, "r");
            while (fgets(input, IN_LEN, input_file) != NULL) {
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
void base64_encode(struct Arguments args, uint8_t input[], char output[], 
    int input_len) {
    if (args.encode) {
        // output of the encoding function
        char function_output[4];
        // triplet for splitting 3 bytes into 4 six bit sextets
        uint32_t triplet;
        // computing how many triplets are in the input
        int n_triplets = (input_len % 3 == 0) ? input_len / 3 : 
            input_len / 3 + 1;
        // counting how many triplets were missed in the last one
        uint8_t missing_triplets = 0;

        //TODO: clean up this code and make it more readable - maybe use an if
        //statement for whether or not the input is evenly divisible
        // persistent index for the two loops
        int i = 0;
        // step through all but the last of the triplets
        for (; i < n_triplets - 1; ++i) {
            triplet = 0;
            // for each element in the triplet
            for (uint8_t j = 0; j < 3; ++j) {
                if (3*i+j < input_len) {
                    // shift 3 bytes into a 4 byte int
                    triplet |= (input[3 * i + j] << (0x08 * (3 - j)));
                }
            }
            for (uint8_t j = 0; j < 4; ++j) {
                // convert the parts of the triple into the respective characters
                function_output[j] = encode_sextet((triplet >> ((3 - j) * 0x06) + 0x08) & 0x3f);
            }
            // copy the output from the function into the output string
            for (uint8_t j = 0; j < 4; ++j) {
                output[4*i+j] = function_output[j];
            }
        }
        // set the index correctly
        i = n_triplets - 1;
        triplet = 0;
        // for each element in the triplet
        for (uint8_t j = 0; j < 3; ++j) {
            if (3*i+j < input_len) {
                triplet |= (input[3 * i + j] << (0x08 * (3 - j)));
            } else {
                ++missing_triplets;
            }
        }
        for (uint8_t j = 0; j < 4; ++j) {
            // convert the parts of the triple into the respective characters
            function_output[j] = encode_sextet((triplet >> ((3 - j) * 0x06) + 0x08) & 0x3f);
        }
        for (uint8_t j = 0; j < 4 - missing_triplets; ++j) {
            output[4*i+j] = function_output[j];
        }
        for (uint8_t j = 4 - missing_triplets; j < 4; ++j) {
            output[4*i+j] = '=';
        }

        output[4 * n_triplets] = '\0';
    } else {
        // output of the encoding function
        uint8_t function_output[3];
        // triplet for splitting 4 sextets into 3 bytes
        uint32_t triplet;
        // computing how many triplets are in the input
        int n_triplets = input_len / 4;
        // counting how many triplets were missed in the last one
        uint8_t empty_sextets = 0;

        // persistent index for the two loops
        int i = 0;
        // step through all but the last of the triplets
        for (; i < n_triplets - 1; ++i) {
            triplet = 0;
            // for each element in the triplet
            for (uint8_t j = 0; j < 4; ++j) {
                if (4*i+j < input_len) {
                    // shift 4 sextets into a 4 byte int
                    triplet |= (input[4 * i + j] << (0x08 * (3 - j)));
                }
            }
            // copy the output from the function into the output string
            for (uint8_t j = 0; j < 4; ++j) {
                output[4*i+j] = function_output[j];
            }
        }
        // set the index correctly
        i = n_triplets - 1;
        triplet = 0;
        // for each element in the triplet
        /*
        for (uint8_t j = 0; j < 3; ++j) {
            if (3*i+j < input_len) {
                triplet |= (input[3 * i + j] << (0x08 * (3 - j)));
            } else {
                ++missing_triplets;
            }
        }
        for (uint8_t j = 0; j < 4 - missing_triplets; ++j) {
            output[4*i+j] = function_output[j];
        }
        for (uint8_t j = 4 - missing_triplets; j < 4; ++j) {
            output[4*i+j] = '=';
        }

        output[4 * n_triplets] = '\0';
        */
    }
}

// returns the character for the base64 encoding
char encode_sextet(uint8_t num) {
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
