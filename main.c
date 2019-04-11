#include <stdio.h>

int main() {
    char c;
    FILE *input; //pointer to input
    input = fopen("input", "r"); //reads input
    if(input == NULL) { 
        perror("fopen()"); //prints user-friendly error if error occurs while reading
        return 0;
    }
    while(!feof(input)) { //this while loop scans all of input and prints every character until the end of file
        fscanf(input, "%c", &c);
        printf("%c", c);
    }
    return 0;
}