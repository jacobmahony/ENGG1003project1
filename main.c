#include <stdio.h>
#include <string.h>

int bruteForceDecrypt(int x);

int main() {
    char message[1000]; //this array holds a message of up to 1000 characters
    int i, j, k, l, len;
    char check1[3] = {'T', 'H', 'E'}; //this array holds the string 'THE'. This will be the word that we check for in each possible decrypted message to see if it is actually decrypted
    FILE *input; //file pointer to input
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, " %[^\n]s", message); //scans all of input and stores it in message
    len = strlen(message); //stores length of string in len
    printf("Encrypted Message: %s\n", message);
    for(i = 0; i < 26; i++) { //this is our for loop that tests for each possible decrypted message
        for(j = 0; j < len; j++) {
            message[j] = bruteForceDecrypt(message[j]);
        }
        for(k = 0; k < len; k++) {
            if(check1[0] == message[k]) { //this checks to see if a given letter in one of the possible decrypted messages is the character T.
                if(check1[1] == message[k+1]) { //checks to see if the following character is H
                    if(check1[2] == message[k+2]) { //checks to see if the following character is E
                        printf("A proper word has been found, hence the cipher has been decrypted\n");
                        printf("Original Message: %s", message);
                        FILE *output; //file pointer to output
                        output = fopen("output", "w"); //opens output for writing
                        for(l = 0; l < len; l++) {
                            fprintf(output, "%c", message[l]); //prints each individual character of the message to file output
                        }
                        return 0;
                    }
                }
            }
        }
    }
}

int bruteForceDecrypt(int x) {
    int i, d;
    x = x - 65; //makes our letters have a value between 0 and 25 (for A - Z)
    if(x >= 0 && x < 26) {
        d = ((x + 1) % 26) + 65; //shifts each character in the message by 1 and returns it to its original ASCII value
        return d;
    }
    else { //if the character is a non-capital letter characterm this returns that character
        x = x + 65;
        return x;
    }
}