#include <stdio.h>
#include <string.h>

int encrypt(int x);

int main() {
    char m[1000]; //creates an array which can store up to 1000 characters
    char en[1000];
    int i, j, n;
    FILE *input; //pointer to input
    input = fopen("input", "r"); //reads input
    fscanf(input, " %[^\n]s", m); //scans the entirety of input and assigns it to 1 string
    n=strlen(m);
    printf("Original Message: %s len: %d\n", m, n);
    /*for(i = 0; i<n; i++) { // m[i] != '\0' && en[i] != '\0' i accesses each character in message string
        en[i] = encrypt(m[i]);
        printf("\t%d, %c, %d, %c\n", en[i], en[i], m[i], m[i]);*/
    }
    printf("Encrypted Message: %s", en); //prints the whole encrypted message
    return 0;
}

int encrypt(int x) { //encryption function definition
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
    e = (x + key)%26 + 65; //shifts the letter by the given key and then adds 65 to return it to its proper ASCII code
    return e;
}
}