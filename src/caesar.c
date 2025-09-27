#include <stdlib.h>
#include "caesar.h" 
#include "strPtr.h"

/**
 *  Feel free to use the functions that you made in strPtr.c
*/ 

//Helper function for decrypting
int isEOM(char *strPointer){
    if(*(strPointer) == '_' &&
       *(strPointer+1) == '_' &&
       *(strPointer+2) == 'E' &&
       *(strPointer+3) == 'O' &&
       *(strPointer+4) == 'M' &&
       *(strPointer+5) == '_' &&
       *(strPointer+6) == '_'){
        return 1;
    }

    return 0;
}

int encryptCaesar(const char *plaintext, char *ciphertext, int key) {
    if(plaintext == NULL || ciphertext == NULL){
        return -2;
    }

    int counter = 0;

    //Loop through the plaintext
    int idx = 0;
    for( ; *(plaintext+idx) != 0; idx++){
        char newChar;
        //Cipher only if one of the following:
        if(*(plaintext+idx) >= 97 && *(plaintext+idx) <= 122){     //Lowercase Letters
            newChar = (((*(plaintext+idx)-97) + ((key + idx) % 26))) + 97;
            counter++;
        }
        else if(*(plaintext+idx) >= 65 && *(plaintext+idx) <= 90){  //Uppercase Letters
            newChar = (((*(plaintext+idx)-65) + ((key + idx) % 26))) + 65;
            counter++;
        }
        else if(*(plaintext+idx) >= 48 && *(plaintext+idx) <= 57){  //Numbers
            newChar = ((*(plaintext+idx)-48) + ((key + (2*idx)) % 10)) + 48;
            counter++;
        }
        else{   //Otherwise, just keep it the same
            newChar = *(plaintext+idx);
        }

        *(ciphertext+idx) = newChar;
    }

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

    int counter = 0;

    //Loop through the ciphertext
    int idx = 0;
    for( ; isEOM(ciphertext+idx); idx++){
        char newChar;
        //Cipher only if one of the following:
        if(*(ciphertext+idx) >= 97 && *(ciphertext+idx) <= 122){     //Lowercase Letters
            newChar = (((*(ciphertext+idx)-97) - (key + idx)) % 26) + 97;
            counter++;
        }
        else if(*(ciphertext+idx) >= 65 && *(ciphertext+idx) <= 90){  //Uppercase Letters
            newChar = (((*(ciphertext+idx)-65) - (key + idx)) % 26) + 65;
            counter++;
        }
        else if(*(ciphertext+idx) >= 48 && *(ciphertext+idx) <= 57){  //Numbers
            newChar = (((*(ciphertext+idx)-48) - (key + (2*idx))) % 10) + 48;
            counter++;
        }
        else{   //Otherwise, just keep it the same
            newChar = *(ciphertext+idx);
        }

        *(plaintext+idx) = newChar;
    }

	// TODO: implement
    (void)ciphertext;
    (void)plaintext;
    (void)key;
    return 0;
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
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/
    char out[64];
    printf("%d\n", encryptCaesar("abc",  out, 2));
    printf("%s\n", out);
    printf("%d\n", encryptCaesar("Ayb",  out, 3));
    printf("%s\n", out);
    printf("%d\n", encryptCaesar("Cse220",  out, 1));
    printf("%s\n", out);
    printf("%d\n", encryptCaesar("CS",  out, 0));
    printf("%s\n", out);
    printf("%d\n", encryptCaesar("System Fundamentals",  out, 1));
    printf("%s\n", out);
    printf("%d\n", encryptCaesar("",  out, 42));
    printf("%s\n", out);

	
	/** ---------------------- **/
	return 0;
}
