

#include <stdio.h>

int main() {
    char message[100][100];
    int i, key = 4;
    FILE *input;
    input = fopen("input", "r");
    fscanf(input, "%s %s %s", message[1], message[2], message[3]);
    printf(Original message: )
    for(i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] + key;
    }
    printf("Encrypted message: %s", message);
    return 0;
}
