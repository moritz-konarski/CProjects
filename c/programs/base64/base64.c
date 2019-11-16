#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define STR_LEN     500
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
int encode_triplet(char input[], char output[]);
char get_char(uint8_t num); 

int main(uint8_t argc, char *argv[]) {

    char text[10] = "Man";
    
    printf("%s\n", text);
            uint32_t triple = 0;
            
            for (uint8_t i = 3; i > 0 ; --i) {
                printf("%c\n", text[-i+3]);
                printf("%x\n", text[-i+3]);
                printf("%lx\n", text[-i+3] << (0x08 * i));
                triple = triple | (text[-i+3] << (0x08 * i));
            }
            printf("%x\n", triple);
    char output[20];

    encode_triplet(text, output);
    printf("%s\n", output);


    /*
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
*/

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

/*
void base64_encode(struct Arguments args, char input[], char output[]) {
    int result,
        sign = args.encode ? 1 : -1;
    while (*input != 0) {
        if (*input >= FIRST_CHAR && *input <= LAST_CHAR) {
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


    //take three chars as input
    char result[4];
    //output 4 chars
    uint32_t triple;
    while (*input != 0) {
        if (*input >= FIRST_CHAR && *input <= LAST_CHAR) {
            triple = 0;
            for (uint8_t i = 3; i > 0 ; --i) {
                triple = triple | (*input << (0x08 * i));
                input++;
            }

        } else {
            *output = *input;
        }
        input++;
        output++;
    }
    *output = 0;
}
*/

int encode_triplet(char input[], char output[]) {
    if (strlen(input) == 3) {
        char result[4];
        uint32_t triple = 0;
        for (uint8_t i = 3; i > 0 ; --i) {
            triple = triple | (*input << (0x08 * (i - 1)));
            input++;
        }
        printf("func: %x\n", triple);
        for (uint8_t j = 0; j < 4; ++j) {
            output[j] = get_char((triple >> ((3 - j) * 0x06)) & 0x3f);
            printf("%d\n", (triple >> ((3 - j) * 0x06)) & 0x3f);
        }
    } else {
        return 1;
    }
    return 0;
}
