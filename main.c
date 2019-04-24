#include <stdio.h>
#include <string.h>

//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//QWERTYUIOPASDFGHJKLZXCVBNM

int decrypt(int x);

int find_index(int match);

int main() {
    char c[1000]; //array of length 1000 to hold message string
    char de[1000];//array of length 1000 to hold decrypted message string
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
    int e;
    x = x - 65; //this shifts the ASCII number for the capital letter by 65 to make our equation below work
    if(x >= 0 && x < 26) {
        e = find_index(x);
        e = e + 65; //shifts the number by 65 to make our character the correct ASCII number corresponding to the letter
        return e;
}
    else {
        x = x + 65;
        return x;
    }
}

int find_index(int match) {
    int j;
    char enc_index[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}; //this string holds the value for each new letter in the index of the array
    for(j = 0; j < 26; j++) {
        enc_index[j] = enc_index[j] - 65;
        if(enc_index[j] == match) { //when the character 'match' is the same as the character in the array enc_index, return the index corresponding to that character in the array
            return j;
        }
    }
    return 0;
}