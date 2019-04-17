#include <stdio.h>
#include <string.h>

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//QWERTYUIOPASDFGHJKLZXCVBNM

int encrypt(int x);

int main() {
    char m[1000]; //array of length 1000 to hold message string
    char en[1000];
    int i, len;
    FILE *input; //file pointer to input
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, " %[^\n]s", m); //scans all of input and stores it in m
    len = strlen(m); //stores number of characters of the message in variable len
    printf("Original Message: %s %d\n", m, len);
    for(i = 0; i < len; i++) {
        en[i] = encrypt(m[i]); //encrypts original message
        //printf("\t%d %c %d %c\n", m[i], m[i], en[i], en[i]); //prints ASCII value and character for the character in the original message and the encrypted message
    }
    printf("Encrypted Message: %s\n", en);
    return 0;
}

int encrypt(int x) {
    int e;
    char enc_index[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}; //this string holds the value for each new letter in the index of the array
    x = x - 65; //this shifts the ASCII number for the capital letter by 65 to make our equation below work
    if(x >= 0 && x < 26) { //if character is an uppercase letter
        e = enc_index[x]; //assigns the new letter in variable e
        return e;
    }
    else {
        x = x + 65;
        return x;
    }
}