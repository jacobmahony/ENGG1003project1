

#include <stdio.h>

int main() {
    char message[100][100]; //creates a 100x100 array to store many strings
    int i, j, key = 4;
    FILE *input; //pointer to file name
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, "%s %s %s", message[1], message[2], message[3]); //scans the 3 different words from input and stores them in the array
    printf("Original message: %s %s %s\n", message[1], message[2], message[3] );
    for(i = 1; i < 4; i++) { //only applies code to the first 3 messages in input
        for(j = 0; message[i][j] != '\0'; j++) { //ends for loop when it reaches a null character
            message[i][j] = message[i][j] + key; //accesses each character and shifts it by key
        }        
    }
    printf("Encrypted message: %s %s %s", message[1], message[2], message[3] );
    return 0;
}
