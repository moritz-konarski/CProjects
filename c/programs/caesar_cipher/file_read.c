#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    if(strlen(argv[1]) > 4) {
        FILE * input;
        input = fopen(argv[1], "r");
        FILE * output;
        output = fopen("output.txt", "a");
        char text[500];
        while (fgets(text, 500, input) != NULL) {
            printf("%s\n", text);
            fputs(text, output);
        }
        fclose(input);
        fclose(output);
    }
    return 0;
}
