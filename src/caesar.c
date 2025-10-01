#include <stdlib.h>
#include "caesar.h" 
#include "strPtr.h"

/*
 *  Elijah Ren - CSE 220
 *  116253293
*/

/**
 *  Feel free to use the functions that you made in strPtr.c
*/ 

//For some reason, this isn't linking correctly
//So I just added the function here
void strCopy(char *dest, char *src) {
    if(src == NULL || dest == NULL){
        return;
    }

    for(int idx = 0; ; idx++){
        *(dest+idx) = *(src+idx);

        if(*(src+idx) == 0){    //Copy first, then break if needed
            break;
        }
    }
}

int strDiff(const char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL){
        return -2;
    }

    for(int idx = 0; ; idx++){
        if(*(s1+idx) != *(s2+idx)){
            return idx;
        }

        if(*(s1+idx) == 0 || *(s2+idx) == 0){   //Compare first, then break if needed
            break;
        }
    }
    return -1;
}

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    if(plaintext == NULL || ciphertext == NULL){
        return -2;
    }
    else if(*(plaintext) == 0){
        strCopy(ciphertext, "undefined__EOM__");
        return 0;
    }

    int counter = 0;

    //Loop through the plaintext
    int idx = 0;
    for( ; *(plaintext+idx) != 0; idx++){
        char newChar;
        //Cipher only if one of the following:
        if(*(plaintext+idx) >= 97 && *(plaintext+idx) <= 122){     //Lowercase Letters
            newChar = (((*(plaintext+idx)-97) + key + idx) % 26) + 97;
            counter++;
        }
        else if(*(plaintext+idx) >= 65 && *(plaintext+idx) <= 90){  //Uppercase Letters
            newChar = (((*(plaintext+idx)-65) + key + idx) % 26) + 65;
            counter++;
        }
        else if(*(plaintext+idx) >= 48 && *(plaintext+idx) <= 57){  //Numbers
            newChar = (((*(plaintext+idx)-48) + key + (2*idx)) % 10) + 48;
            counter++;
        }
        else{   //Otherwise, just keep it the same
            newChar = *(plaintext+idx);
        }

        *(ciphertext+idx) = newChar;
    }

    //Add __EOM__ and null character
    *(ciphertext+idx) = '_';
    *(ciphertext+idx+1) = '_';
    *(ciphertext+idx+2) = 'E';
    *(ciphertext+idx+3) = 'O';
    *(ciphertext+idx+4) = 'M';
    *(ciphertext+idx+5) = '_';
    *(ciphertext+idx+6) = '_';
    *(ciphertext+idx+7) = 0;

    return counter;
}

int decryptCaesar(const char *ciphertext, char *plaintext, int key) {
    if(plaintext == NULL || ciphertext == NULL){
        return -2;
    }
    else if(strDiff(ciphertext, "undefined__EOM__") == -1){
        strCopy(plaintext, "undefined");
        return 0;
    }

    int counter = 0;

    //Loop through the ciphertext
    int idx = 0;
    for( ; *(ciphertext+idx) != 0; idx++){
        char newChar;
        //Cipher only if one of the following:
        if(*(ciphertext+idx) >= 97 && *(ciphertext+idx) <= 122){     //Lowercase Letters
            newChar = (((*(ciphertext+idx)-122) - (key + idx)) % 26) + 122;
            counter++;
        }
        else if(*(ciphertext+idx) >= 65 && *(ciphertext+idx) <= 90){  //Uppercase Letters
            newChar = (((*(ciphertext+idx)-90) - (key + idx)) % 26) + 90;
            counter++;
        }
        else if(*(ciphertext+idx) >= 48 && *(ciphertext+idx) <= 57){  //Numbers
            newChar = (((*(ciphertext+idx)-57) - (key + (2*idx))) % 10) + 57;
            counter++;
        }
        else{   //Otherwise, just keep it the same
            newChar = *(ciphertext+idx);
        }

        //Check if this is end of memory
        if(strDiff((ciphertext+idx), "__EOM__") == -1){
            //Add null character
            *(plaintext+idx) = 0;
            return counter;
        }

        *(plaintext+idx) = newChar;
    }

    //If this is reached, that means no EOM, but
    //null character is reached
    return -1;
}


/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/caesar"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
// int main(int argc, char* argv[]){
// 	(void)argc;
// 	(void)argv;
// 	/** CREATE TEST CASES HERE **/
//     // char out[64];
//     // printf("%d\n", encryptCaesar("abc",  out, 2));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("Ayb",  out, 3));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("Cse220",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("CS",  out, 0));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("System Fundamentals",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("",  out, 42));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar(NULL,  out, 42));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("abc",  NULL, 42));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("[]_+;?><123",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", encryptCaesar("1234567",  out, 0));
//     // printf("%s\n", out);

//     // char out[64];
//     // printf("%d\n", decryptCaesar("ceg__EOM__",  out, 2));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("Dcg__EOM__",  out, 3));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("Duh911__EOM__",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("CT__EOM__",  out, 0));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("no marker",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("NULL__EOM__",  NULL, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar(NULL,  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("undefined__EOM__",  out, 1));
//     // printf("%s\n", out);
//     // printf("%d\n", decryptCaesar("1470369__EOM__",  out, 0));
//     // printf("%s\n", out);
	
// 	/** ---------------------- **/
// 	return 0;
// }
