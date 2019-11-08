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

#define ALL_ARGS    "edios"

#define EMPTY_STR   "\0"

struct Arguments {
    int16_t shift;
    bool non_std_shift,
         do_encryption,
         has_input_file,
         has_output_file;
    char input_file_name[100], 
         output_file_name[100];
};

void encrypt(char input[], int16_t shift, char output[]);
void decrypt(char input[], int16_t shift, char output[]);
void input_en_decrypt(char action, int16_t shift);
void sort_out_args(struct Arguments args);
bool is_digit(char c);
bool is_number(char str[]);

int main(uint8_t argc, char *argv[]) {

    struct Arguments args = {
        STD_SHIFT, 
        false,
        true, 
        false, 
        false, 
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
                args.has_input_file = true;
                break;
            case 'o':
                args.has_output_file = true;
                break;
            case 's':
                args.non_std_shift = true;
                break;
            default:
                //abort();
                break;
        }
    }

    printf("%d - %d | %d | %d - %d | %s - %s |\n", args.shift, args.non_std_shift, args.do_encryption, args.has_input_file, args.has_output_file, args.input_file_name, args.output_file_name);

    printf("-------------\n");
    for (uint8_t i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    printf("-------------\n");
    // read the shift input
    if (args.non_std_shift) {
        for (uint8_t i = 1; i < argc; i++) {
            if (argv[i][0] == ARG_CHAR && argv[i][1] == SHIFT_ARG) {
                if (i+1 < argc && is_number(argv[i+1])) {
                    sscanf(argv[i+1], "%d", &args.shift);
                } else {
                    printf("Shift argument is incorrect!\n");
                    return 1;
                }
                break;
            } 
        }
    }   
    printf("%d - %d | %d | %d - %d | %s - %s |\n", args.shift, args.non_std_shift, args.do_encryption, args.has_input_file, args.has_output_file, args.input_file_name, args.output_file_name);
    /*
    for (uint8_t i = 1; i < argc; i++) {
        switch (argv[i][0]) {
            case ARG_CHAR:
                switch (argv[i][1]) {
        //shift argument
                    case SHIFT_ARG:
                        if (i+1 < argc && (argv[i+1][0] != ARG_CHAR || (argv[i+1][1] >= '0' && argv[i+1][1] <= '9')) && strlen(argv[i+1]) > 0) {
                            ++i;
                            sscanf(argv[i], "%d", &args.shift);
                        }
                        break;
        //input argument
                    case INPUT_ARG:
                        if (i+1 < argc && argv[i+1][0] != ARG_CHAR && strlen(argv[i+1]) > 0) {
                            ++i;
                            char name[1000];
                            sscanf(argv[i], "%s", name);
                            if (strlen(name) < sizeof(args.input_file_name)) {
                                strncpy(args.input_file_name, name, sizeof(args.input_file_name) - 1);
                                args.has_input_file = true;
                            }
                        }
                        break;
        //output argument
                    case OUTPUT_ARG:
                        if (i+1 < argc && argv[i+1][0] != ARG_CHAR && strlen(argv[i+1]) > 0) {
                            ++i;
                            char name1[1000];
                            sscanf(argv[i], "%s", name1);
                            if (strlen(name1) < sizeof(args.output_file_name)) {
                                strncpy(args.output_file_name, name1, sizeof(args.output_file_name) - 1);
                                args.has_output_file = true;
                            }
                        }
                        break;
                }
                break;
        } 
    }
    
    printf("%d - %d | %d | %d - %d | %s - %s |\n", args.shift, args.non_std_shift, args.do_encryption, args.has_input_file, args.has_output_file, args.input_file_name, args.output_file_name);

    sort_out_args(args);
    */


    return 0;
}

bool is_number(char str[]) {
    printf("-- %s\n", str);
    if (*str == '-' || is_digit(*str)) {
        ++str;
        while (*str != 0) {
            if (!is_digit(*str)) {
                return false;
            }
            ++str;
        }
        return true;
    } else {
        return false;
    }
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void input_en_decrypt(char action, int16_t shift) {
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

void encrypt(char input[], int16_t shift, char output[]) {
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

void decrypt(char input[], int16_t shift, char output[]) {
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
