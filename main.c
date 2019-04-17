#include <stdio.h>
#include <string.h>

int decrypt(int x);

int main() {
    char c[1000]; //creates an array which can store up to 1000 characters
    char de[1000];
    int i, j, n;
    FILE *input; //pointer to input
    input = fopen("input", "r"); //reads input
    fscanf(input, " %[^\n]s", c); //scans the entirety of input and assigns it to 1 string
    n=strlen(c); //assigns the amount of characters in message to variable n
    printf("Encrypted Message: %s len: %d\n", c, n);
    for(i = 0; i<n; i++) { // m[i] != '\0' && en[i] != '\0' i accesses each character in message string
        de[i] = decrypt(c[i]); //decrypts each character in string
        //printf("\t%d, %c, %d, %c\n", en[i], en[i], m[i], m[i]);
    }
    printf("Decrypted Message: %s", de); //prints the whole decrypted message
    return 0;
}

int decrypt(int x) { //encryption function definition
    int key = 1;
    int e;
    if(x == 32 ) { //if the character is space, return a space
        return 32;
    }
    else if(x == 0){ //if the character is a NULL character, return NULL
    return 0;   
    }    
    else {
        x = x-65; //this shifts the ASCII number for the capital letter by 65 to make our equation below work
    e = (x - key)%26 + 65; //shifts the letter by the given key and then adds 65 to return it to its proper ASCII code
    return e;
}
}