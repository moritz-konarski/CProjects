#include <stdio.h>

/*make a last name initials acronym out of author's names that are separated by hyphens*/

int main() {

    int index = 0;
    char names[100];
    char acronym[100];

    scanf("%s", names);

    for (int i = 0; names[i] != '\0'; i++) {
        if (names[i] < 'a' && names[i] != '-') {
            acronym[index++] = names[i];
        }
    }

    acronym[index] = '\0';

    printf("%s\n", acronym);

    return 0;
}