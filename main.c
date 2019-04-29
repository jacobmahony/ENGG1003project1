/*
--------------------------------------------------------------------PROGRAM OVERVIEW----------------------------------------------------------------------------
This program takes information from file "input" to choose a specific task to perform. This task is selected by placing a number between 1 - 5 on the first line
to specify which task number from the following tasks:

1. Encryption of a message with a rotation cipher given the message text and rotation amount
2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
3. Encryption of a message with a substitution cipher given message text and alphabet substitution
4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
5. Decryption of a message encrypted with a rotation cipher given cipher text only

For tasks 1 - 2, an integer between 1 and 25 should be placed after the # symbol. This integer is the key for the rotation cipher encryption or decryption. For
tasks 3 - 4, a string of 26 uppercase letters should be placed after the # symbol. eg. QWERTYUIOPASDFGHJKLZXCVBNM. All letters must be different and should be
no longer or shorter than 26 characters. This string of characters represents the alphabet substitutions to be used for encryption/decryption using a
substitution cipher. For task 5, no character should be typed after the # symbol. This task doesn't require a given key so typing a character in that space will
lead to unexpected errors. A message should also be typed on the third line for all tasks. Depending on the nature of the tasks, this message either represents
an already encrypted message or just a plain message. In order to make the program work, write the ENTIRE message on this line.

Each task is placed under a switch case which selects the task based on the given task number in input. Each case has a function inside of it and this function
is where the task is to be performed. All output is printed to both stdout and the file "output".
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

/*
------------------------------------------------------------FUNCTION rCipherEncrypt-----------------------------------------------------------------------------
This function encrypts each individual letter of an array using a rotation cipher. It takes in a character (which is really an integer) and assigns a number
between 0 - 25 based on its letter A - Z. This allows the equation which encrypts a letter given a key to work. The function then shifts the encrypted letter
to its proper ASCII value and this is the integer (or character) that the function returns. A limitation of this function is that it requires an external for
loop to encrypt the message as it doesn't take in the entire string and compute it all within the function. x represents the character to be encrypted and k
is the key.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int rCipherEncrypt(int x, int k);

/*
----------------------------------------------------------------FUNCTION task1----------------------------------------------------------------------------------
This function is where all the code that belongs to Task 1 is kept. It essentially scans the message and key from file "input" and and uses the function
"rCipherEncrypt" to encrypt each letter under a for loop. It also prints the original message and encrypted message.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void task1(void);

/*
------------------------------------------------------------FUNCTION rCipherDecrypt-----------------------------------------------------------------------------
This function decrypts each individual letter of an array using a rotation cipher. It takes in a character (which is really an integer) and assigns a number
between 0 - 25 based in its letter A - Z. This allows the equation which decrypts a letter given a key to work. The function then shifts the decrypted letter
to its proper ASCII value and this is the integer (or character) that the function returns. A limitation of this function is that it requires an external for
loop to decrypt the message as it doesn't take in the entire string and compute it all within the function. x represents the character to be decrypted and k is
the key.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int rCipherDecrypt(int x, int k);

/*
----------------------------------------------------------------FUNCTION task2----------------------------------------------------------------------------------
This function is where all the code that belongs to Task 2 is kept. It essentially scans the encrypted message and key from file "input" and uses the function
"rCipherDecrypt" to decrypt each letter under a for loop. It also prints the encrypted message and the decrypted message.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void task2(void);

/*
------------------------------------------------------------FUNCTION sCipherEncrypt-----------------------------------------------------------------------------
This function encrypts each individual letter of an array using a substitution cipher. It takes in a character (which is really an integer), takes away 65 from
that integer to give it a number between 0 and 25 based on its letter A - Z and then uses a string of 26 uppercase letters in a specified order and substitutes
the original letter for the corresponding letter in the key. The new letter has 65 added to it to return it to its proper ASCII value and then this value is
what the function returns. A limitation of this function is that it requires an external for loop to encrypt the message as it doesn't take in the entire string
and compute it all within the function. x represents the character to be encrypted and k[] is the key or alphabet substitution.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int sCipherEncrypt(int x, char k[]);

/*
----------------------------------------------------------------FUNCTION task3----------------------------------------------------------------------------------
This function is where all the code that belongs to Task 3 is kept. It essentially scans the message and alphabet substitution from file "input" and uses the
function "sCipherEncrypt" to encrypt each letter under a for loop. It also prints the original message and the encrypted message.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void task3(void);

/*
------------------------------------------------------------FUNCTION sCipherDecrypt-----------------------------------------------------------------------------
This function decrypts each individual letter of an array using a substitution cipher. It takes a character (which is really an integer), takes away 65 from
that integer to give it a number between 0 and 25 based on its letter A - Z and then uses the function "findIndex" to find the original letter. It then adds 65
to this to return the letter to its proper ASCII value and the function returns this value. A limitation of this function is that it requires an external for 
loop to encrypt the message as it doesn't take in the entire string and compute it all within the function. x represents the character to be encrypted.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int sCipherDecrypt(int x);

/*
--------------------------------------------------------------FUNCTION findIndex--------------------------------------------------------------------------------
This function allows us to find the original letter when given the decrypted letter and the key. By using a for loop it checks the index of the encrypted letter
and matches it with the index of the same letter in the key. Once this index is known, we can assume that this index is the same number corresponding to the
original letter A - Z. The function returns the index found. x represents the character whose index we are trying to find.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int findIndex(int x);

/*
----------------------------------------------------------------FUNCTION task4----------------------------------------------------------------------------------
This function is where all the code that belongs to Task 4 is kept. It essentially scans the encrypted message and alphabet substitution from file "input" and
uses the function "sCipherDecrypt" to decrypt each letter under a for loop. It also prints the encrypted message and the decrypted message.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void task4(void);

/*
-------------------------------------------------------FUNCTION bruteForceRCipherDecrypt------------------------------------------------------------------------
This function takes each letter of the original message and shifts it by 1. The words in this new message will be compared with real words using the function
"checkForWords" to see if the message has been decrypted or not. A limitation of this function is that it requires an external for loop to encrypt the message 
as it doesn't take in the entire string and compute it all within the function. x represents a letter to be decrypted.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int bruteForceRCipherDecrypt(int x);

/*
-------------------------------------------------------------FUNCTION checkForWords-----------------------------------------------------------------------------
This function uses already defined arrays of characters to see if a set of ordered letters matches with any set of ordered letters in the possibly encrypted
message. If there is a word that matches, the function returns a value of 1 and otherwise returns 0. The only limitation of this function is that due to the way
that the words are checked, the first word of the message cannot be checked as there isn't a space before it. x[] represents a message to compare a given word
w[] to.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int checkForWords(char x[], char w[]);

/*
----------------------------------------------------------------FUNCTION task5----------------------------------------------------------------------------------
This function is where all the code that belongs to Task 5 is kept. It essentially scans the encrypted message from file "input" and then uses the function
"bruteForceRCipherDecrypt" to decrypt the message. It also prints the encrypted and decrypted message.
----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

void task5(void);

int main() {
    int task;
    FILE *input; //file pointer to input
    input = fopen("input", "r"); //opens input for reading
    fscanf(input, "%d", &task); //stores the integer on the first line in variable task
    switch(task) { //based on the value stored in task it selects the corresponding switch case
        case 1: 
            task1();
            break;
        case 2: 
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
    }       
    return 0;    
}

int rCipherEncrypt(int x, int k) {
    x = x - 65; //this shifts the actual ASCII value of the letter A-Z to a number 0 - 25
    if(x >= 0 && x < 26) { //if the character is a capital letter
        x = (x + k)%26 + 65; //this shifts the letter by the key, makes sure it is a value between 0 and 26 and then returns that letter to its proper ASCII value
        return x; //this returns the encrypted letter
    }
    if(x >= 32 && x < 58) { //if the character is a lowercase letter
        x = x - 32; //this makes the character an uppercase letter
        x = (x + k)%26 + 65; //see comments for line 178
        return x; //this returns the encrypted letter
    }
    else { //if the character is not a letter
        x = x + 65; //return the character to its proper ASCII value
        return x; //return the character
    }
}

void task1(void) {
    FILE *input;
    FILE *output;
    input = fopen("input", "r"); //opens input for reading
    output = fopen("output", "w"); //opens output for writing
    int key, i, len;
    char m[1000]; //this array stores the message
    fseek(input, 4, 1); //jumps to the location where the key is stored
    fscanf(input, "%d", &key); //stores the encryption key in variable key
    printf("Task 1 has been selected with key %d.\n", key);
    fprintf(output, "Task 1 has been selected with key %d.\n", key);
    fseek(input, 2, 1); //jumps to location where the start of the message is
    fscanf(input, " %[^\n]s", m); //stores the message in m
    printf("Original Message: %s\n", m);
    fprintf(output, "Original Message: %s\n", m);
    len = strlen(m); //stores the length of string in len
    for(i = 0; i < len; i++) { //this for loop selects each individual letter in the message and passes it to the function rCipherEncrypt
        m[i] = rCipherEncrypt(m[i], key); //see function description (line 37)
    }
    printf("Encrypted Message: %s\n", m);
    fprintf(output, "Encrypted Message: %s\n", m);
    return;
}

int rCipherDecrypt(int x, int k) {
    x = x - 65; //this shifts the actual ASCII value of the letter A-Z to a number 0 - 25
    if(x >= 0 && x < 26) { //if the character is a capital letter
        if((x - k) < 0) { //if x - k is negative
            x = (x - k) + 26; //add 26 to x - k as the modulus has undefined behaviour for negative numbers
            x = x + 65; //add 65 to return it to its proper ASCII value
            return x; //returns the decrypted letter
        }
        else {
            x = ((x - k)%26) + 65; //shifts the letter by the given key and then adds 65 to return it to its proper ASCII code
            return x; //this returns the decrypted letter
        }
    }
    if(x >= 32 && x < 58) { //if the character is a lowercase letter
        x = x - 32; //this makes the character an uppercase letter
        if((x - k) < 0) { //if x - k is negative
            x = (x - k) + 26; //add 26 as the modulus has undefined behaviour for negative numbers
            x = x + 65; //add 65 to return it to its proper ASCII value
            return x; //returns the decrypted
        }
        else {
            x = ((x - k)%26) + 65; //see comments for line 225
            return x; //this returns the decrypted letter
        }
    }
    else { //if the character is not a letter
        x = x + 65; //return the character to its proper ASCII value
        return x;
    }
}

void task2(void) {
    FILE *input;
    FILE *output;
    input = fopen("input", "r"); //opens input for reading
    output = fopen("output", "w"); //opens output for writing
    int key, i, len;
    char m[1000]; //this array stores the message
    fseek(input, 4, 1); //jumps to the location where the key is stored
    fscanf(input, "%d", &key); //stores the encryption key in variable key
    printf("Task 2 has been selected with key %d.\n", key);
    fprintf(output, "Task 2 has been selected with key %d.\n", key);
    fseek(input, 2, 1); //jumps to location where the start of the encrypted message is
    fscanf(input, " %[^\n]s", m); //stores the encrypted message in m
    printf("Encrypted Message: %s.\n", m);
    fprintf(output, "Encrypted Message: %s.\n", m);
    len = strlen(m); //stores the length of string in len
    for(i = 0; i < len; i++) { //this for loop selects each individual letter in the message and passes it to the function rCipherDecrypt
        m[i] = rCipherDecrypt(m[i], key); //see function description (line 58)
    }
    printf("Original Message: %s\n", m);
    fprintf(output, "Original Message: %s\n", m);
    return;
}

int sCipherEncrypt(int x, char k[]) {
    x = x - 65; //this shifts the actual ASCII value of the letter A-Z to a number 0 - 25
    if(x >= 0 && x < 26) { //if character is an uppercase letter
        x = k[x]; //assigns the new letter to x
        return x; //returns the encrypted letter
    }
    if(x >= 32 && x < 58) { //if the character is a lowercase letter
        x = x - 32; //this makes the character an uppercase letter
        x = k[x]; //assigns the new letter to x
        return x; //returns the encrypted letter
    }
    else { //if the character is not a letter
        x = x + 65; //return the character to its proper ASCII value
        return x;
    }
}

void task3(void) {
    FILE *input;
    FILE *output;
    input = fopen("input", "r"); //opens input for reading
    output = fopen("output", "w"); //opens output for writing
    int i, len;
    char m[1000], key[26]; //this array stores the message
    fseek(input, 4, 1); //jumps to the location where the key is stored
    fscanf(input, "%s", key); //stores the encryption key in variable key
    printf("Task 3 has been selected with key %s.\n", key);
    fprintf(output, "Task 3 has been selected with key %s.\n", key);
    fseek(input, 2, 1); //jumps to location where the start of the message is
    fscanf(input, " %[^\n]s", m); //stores message in m
    printf("Original Message: %s\n", m);
    fprintf(output, "Original Message: %s\n", m);
    len = strlen(m); //stores the length of string in len
    for(i = 0; i < len; i++) {
        m[i] = sCipherEncrypt(m[i], key); //see function description (line 79)
    }
    printf("Encrypted Message: %s\n", m);
    fprintf(output, "Encrypted Message: %s\n", m);
    return;
}

int sCipherDecrypt(int x) {
    x = x - 65; //this shifts the actual ASCII value of the letter A-Z to a number 0 - 25
    if(x >= 0 && x < 26) { //if the letter is a capital letter
        x = findIndex(x); //assign the index of the decrypted letter to x
        x = x + 65; //return the letter to its proper ASCII value
        return x; //return the derypted letter
    }
    if(x >= 32 && x < 58) { //if the letter is a lowercase letter
        x = x - 32; //make the letter a capital letter
        x = findIndex(x); //assign the index of the decrypted letter to x
        x = x + 65; //return the letter to its proper ASCII value
        return x; //return the decrypted letter
    }
    else { //if the character is not a letter
        x = x + 65; //return the character to its proper ASCII value
        return x;
    }
}

int findIndex(int x) {
    FILE *input;
    char encIndex[26]; //array to store the key in
    input = fopen("input", "r"); //opens input for reading
    fseek(input, 4, 1); //jumps to where the key is stored
    fscanf(input, "%s", encIndex);
    int j;
    for(j = 0; j < 26; j++) { //tests each individual letter stored in the array
        encIndex[j] = encIndex[j] - 65; //takes away 65 from each character in the key to make our condition below work
        if(encIndex[j] == x) { //when the character 'x' is the same as the character in the array encIndex, return the index corresponding to that character in the array
            return j;
        }
    }
    return 0; //if something goes horribly wrong it will just return the character 'A' as 0 corresponds to A. This shouldn't happen.
}

void task4(void) {
    FILE *input;
    FILE *output;
    input = fopen("input", "r"); //opens input for reading
    output = fopen("output", "w"); //opens output for writing
    int i, len;
    char m[1000], key[26]; //this array stores the message
    fseek(input, 4, 1); //jumps to the location where the key is stored
    fscanf(input, "%s", key); //stores the encryption key in variable key
    printf("Task 4 has been selected with key %s.\n", key);
    fprintf(output, "Task 4 has been selected with key %s.\n", key);
    fseek(input, 2, 1); //jumps to location where the start of the message is
    fscanf(input, " %[^\n]s", m); //stores message in m
    printf("Encrypted Message: %s\n", m);
    fprintf(output, "Encrypted Message: %s\n", m);
    len = strlen(m); //stores the length of string in len
    for(i = 0; i < len; i++) { //accesses each character in message
        m[i] = sCipherDecrypt(m[i]); //see function description (line 91)
    }
    printf("Original Message: %s\n", m);
    fprintf(output, "Original Message: %s\n", m);
    return;
}

int bruteForceRCipherDecrypt(int x) {
    x = x - 65; //this shifts the actual ASCII value of the letter A-Z to a number 0 - 25
    if(x >= 0 && x < 26) { //if the letter is a capital letter
        x = (x + 1)%26 + 65; //shifts each character in the message by 1 and returns it to its original ASCII value
        return x; //returns encrypted letter
    }
    if(x >= 32 && x < 58) { //if the letter is a lowercase letter
        x = x - 32; //make the letter uppercase
        x = (x+1)%26 + 65; //see line 374
        return x; //returns encrypted letter
    }
    else { //if the character is not a letter
        x = x + 65; //return the character to its original ASCII value
        return x;
    }
}

int checkForWords(char x[], char w[]) {
    int len1, len2, i, j;
    len1 = strlen(x); //stores length of message in len1
    len2 = strlen(w); //stores length of word to be checked (including the space after it) in len2
    for(i = 0; i < len1; i++) {
        if(x[i] == w[0]) { //checks each individual character in message and sees if it matches with the first character of the word to be checked
            for(j = 1; j < len2; j++) {
                if(x[i + j] == w[j]) { //if each successive character is equal continue the for loop
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

void task5(void) {
    FILE *input;
    FILE *output;
    input = fopen("input", "r"); //opens input for reading
    output = fopen("output", "w"); //opens output for writing
    int i, j, len;
    char m[1000]; //this array stores the message
    char check1[5] = {' ', 'T', 'H', 'E', ' '}; //this array holds the string 'THE'. This will be a word that we check for in each possible decrypted message to see if it is actually decrypted
    char check2[4] = {' ', 'O', 'F', ' '};
    char check3[5] = {' ', 'A', 'N', 'D', ' '};
    char check4[4] = {' ', 'T', 'O', ' '};
    char check5[3] = {' ', 'A', ' '};
    printf("Task 5 has been selected.\n");
    fprintf(output, "Task 5 has been selected.\n");
    fseek(input, 4, 1); //jumps to location where the start of the message is
    fscanf(input, " %[^\n]s", m); //stores message in m
    printf("Encrypted Message: %s\n", m);
    fprintf(output, "Encrypted Message: %s\n", m);
    len = strlen(m); //stores the length of string in len
    for(j = 0; j < 26; j++) { //this is our for loop that tests for each possible decrypted message
        for(i = 0; i < len; i++) { //this loop essentially shifts each letter in our message by 1
            m[i] = bruteForceRCipherDecrypt(m[i]); //see function description (line 121)
        }
        if(checkForWords(m, check1) == 1) { //if the checkForWords function found a word that matched, it will return a value of 1, so the code below will run
            printf("A proper word has been found, hence the cipher has been decrypted\n");
            fprintf(output, "A proper word has been found, hence the cipher has been decrypted.\n");
            printf("Original Message: %s\n", m);
            fprintf(output, "Original Message: %s\n", m);
            return;
        }
        else if(checkForWords(m, check2) == 1) {
            printf("A proper word has been found, hence the cipher has been decrypted\n");
            fprintf(output, "A proper word has been found, hence the cipher has been decrypted.\n");
            printf("Original Message: %s\n", m);
            fprintf(output, "Original Message: %s\n", m);
            return;
        }
        else if(checkForWords(m, check3) == 1) {
            printf("A proper word has been found, hence the cipher has been decrypted\n");
            fprintf(output, "A proper word has been found, hence the cipher has been decrypted.\n");
            printf("Original Message: %s\n", m);
            fprintf(output, "Original Message: %s\n", m);
            return;
        }
        else if(checkForWords(m, check4) == 1) {
            printf("A proper word has been found, hence the cipher has been decrypted\n");
            fprintf(output, "A proper word has been found, hence the cipher has been decrypted.\n");
            printf("Original Message: %s\n", m);
            fprintf(output, "Original Message: %s\n", m);
            return;
        }
        else if(checkForWords(m, check5) == 1) {
            printf("A proper word has been found, hence the cipher has been decrypted\n");
            fprintf(output, "A proper word has been found, hence the cipher has been decrypted.\n");
            printf("Original Message: %s\n", m);
            fprintf(output, "Original Message: %s\n", m);
            return;
        }
    }
}