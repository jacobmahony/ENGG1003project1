#include <stdio.h>
#include <string.h>

void cipherDecrypted(char x[]);

int bruteForceDecrypt(int x);

int checkForWords(char m[], char w[]);

int main() {
    char message[1000]; //this array holds a message of up to 1000 characters
    int i, j, k, l, len;
    char check1[5] = {' ', 'T', 'H', 'E', ' '}; //this array holds the string 'THE'. This will be a word that we check for in each possible decrypted message to see if it is actually decrypted
    char check2[4] = {' ', 'O', 'F', ' '};
    char check3[5] = {' ', 'A', 'N', 'D', ' '};
    char check4[4] = {' ', 'T', 'O', ' '};
    char check5[3] = {' ', 'A', ' '};
    FILE *input; //file pointer to input
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, " %[^\n]s", message); //scans all of input and stores it in message
    len = strlen(message); //stores length of string in len
    printf("Encrypted Message: %s\n", message);
    for(i = 0; i < 26; i++) { //this is our for loop that tests for each possible decrypted message
        for(j = 0; j < len; j++) {
            message[j] = bruteForceDecrypt(message[j]); //shifts each character in the original message by 1
        }
        if(checkForWords(message, check1) == 1) { //if the checkForWords function found a word that matched, it will return a value of 1, so the function cipherDecrypted will run and print the original message to stdout and output
            cipherDecrypted(message);
            return 0;
        }
        else if(checkForWords(message, check2) == 1) {
            cipherDecrypted(message);
            return 0;
        }
        else if(checkForWords(message, check3) == 1) {
            cipherDecrypted(message);
            return 0;
        }
        else if(checkForWords(message, check4) == 1) {
            cipherDecrypted(message);
            return 0;
        }
        else if(checkForWords(message, check5) == 1) {
            cipherDecrypted(message);
            return 0;
        }
    }
    return 0;
}

void cipherDecrypted(char x[]) {
    int l, len;
    printf("A proper word has been found, hence the cipher has been decrypted\n");
    printf("Original Message: %s", x);
    FILE *output; //file pointer to output
    output = fopen("output", "w"); //opens output for writing
    len = strlen(x);
    for(l = 0; l < len; l++) {
        fprintf(output, "%c", x[l]); //prints each individual character of the message to file output
    }
    return;
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

int checkForWords(char m[], char w[]) {
    int len1, len2, i, j;
    len1 = strlen(m); //stores length of message in len1
    len2 = strlen(w); //stores length of word to be checked (including the space after it) in len2
    for(i = 0; i < len1; i++) {
        if(m[i] == w[0]) { //checks each individual character in message and sees if it matches with the first character of the word to be checked
            for(j = 1; j < len2; j++) {
                if(m[i + j] == w[j]) { //if each successive character is equal continue the for loop
                    if(j == len2 - 1) { //if the last character is the same the function returns a value of 1
                        return 1;
                    }
                }
                else {
                    j = len2; //if a successive character is not equal stop this for loop
                }
            }
        }
    }
    return 0; //if there are no words that match the function returns a value of 0
}