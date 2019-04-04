#include <stdio.h>
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//ZABCDEFGHIJKLMNOPQRSTUVWXY

int e(int a); //encryption function prototype 
char a[10][10];
int main() {
    /*for(int i=0; i<26; i++) {
        printf("%c %d\n", i+65, i+65);
    }*/
FILE *input;
input = fopen("input", "r");
fscanf(input, "%s %s %s", a[0],a[1],a[2]);
printf("%s %s %s", a[0],a[1],a[2]);
    return 0;
}

/*int e(int a) { //encryption function definition

}*/