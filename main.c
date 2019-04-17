#include <stdio.h>
#include <string.h>

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//QWERTYUIOPASDFGHJKLZXCVBNM

int decrypt(int x);

int find_index(char )

int main() {
    char c[1000]; //array of length 1000 to hold message string
    char de[1000];
    int i, len;
    FILE *input; //file pointer to input
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, " %[^\n]s", c); //scans all of input and stores it in c
    len = strlen(c); //stores number of characters of the message in variable len
    printf("Encrypted Message: %s %d\n", c, len);
    for(i = 0; i < len; i++) {
        de[i] = decrypt(c[i]); //decrypts original message
        //printf("\t%d %c %d %c\n", c[i], c[i], de[i], de[i]); //prints ASCII value and character for the character in the original message and the encrypted message
    }
    printf("Decrypted Message: %s\n", de);
    return 0;
}

int decrypt(int x) {
    int e, c_index, g;
    char enc_index[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}; //this string holds the value for each new letter in the index of the array
    x = x - 65; //this shifts the ASCII number for the capital letter by 65 to make our equation below work
    if(x >= 0 && x < 26) {
        c_index = find_index(x)
    }
}

int find_index(char enc_index[], char match) {
    int j;
    char enc_index[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}; //this string holds the value for each new letter in the index of the array
    for(j = 0; j < 26; j++) {
        if(enc_index[j] == match) {
            return j;
        }
    }
    return 0;
}