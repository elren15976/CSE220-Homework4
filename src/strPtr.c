#include <stdlib.h>
#include "strPtr.h"

#include <stdlib.h>
#include "strPtr.h"

int strgLen(const char *s) {
    if(s == NULL){
        return -1;
    }

    int count = 0;
    while(*(s+count) != 0){
        count++;
    }
    return count;
}

void strgCopy(char *dest, char *src) {
    if(src == NULL || dest == NULL){
        return;
    }

    for(int idx = 0; ; idx++){
        *(dest+idx) = *(src+idx);

        if(*(src+idx) == 0){
            break;
        }
    }
}

void strgChangeCase(char *s) {
    if(s == NULL){
        return;
    }

    for(int idx = 0; *(s+idx) != 0; idx++){
        if((*(s+idx+1) >= 48 && *(s+idx+1) <= 57) ||
           (idx != 0 && *(s+idx-1) >= 48 && *(s+idx-1) <= 57)){
            continue;
        }

        if(*(s+idx) >= 97 && *(s+idx) <= 122){
            *(s+idx) = *(s+idx)-32;
        }
        else if(*(s+idx) >= 65 && *(s+idx) <= 90){
            *(s+idx) = *(s+idx)+32;
        }
    }
}

int strgDiff(char *s1, char *s2) {
    // TODO: implement
    (void)s1;
    (void)s2;
    return 0;
}

void strgInterleave(char *s1, char *s2, char *d) {
    // TODO: implement
    (void)s1;
    (void)s2;
    (void)d;
}

void strgReverseLetters(char *s) {
    // TODO: implement
    (void)s;
}



/**
 * Create all test cases inside of the main function below.
 * Run the test cases by first compiling with "make" and then 
 * running "./bin/strPtr"
 * 
 * Before submmiting your assignment, please comment out your 
 * test cases for the TAs. 
 * Comment out if using criterion to test.
 */
int main(int argc, char* argv[]){
	(void)argc;
	(void)argv;
	/** CREATE TEST CASES HERE **/

	// printf("%d\n", strgLen("Stony Brook"));
	// printf("%d\n", strgLen("CSE 220"));
	// printf("%d\n", strgLen("C"));
	// printf("%d\n", strgLen("System Fundamental"));
	// printf("%d\n", strgLen("1"));
	// printf("%d\n", strgLen(""));
	// printf("%d\n", strgLen(NULL));

    // char dest[32] = {0};
    // strgCopy(dest, "Computer Science");
    // printf("%s\n", dest);
    // strgCopy(dest, "CSE-220");
    // printf("%s\n", dest);
    // strgCopy(dest, "System Fundamental");
    // printf("%s\n", dest);
    // strgCopy(dest, "1");
    // printf("%s\n", dest);
    // strgCopy(dest, "");
    // printf("%s\n", dest);

    // char s1[] = "Stony Brook";
    // strgChangeCase(s1);
    // printf("%s\n", s1);
    // char s2[] = "CSE220";
    // strgChangeCase(s2);
    // printf("%s\n", s2);
    // char s3[] = "a1b";
    // strgChangeCase(s3);
    // printf("%s\n", s3);
    // char s4[] = "System Fundamental220";
    // strgChangeCase(s4);
    // printf("%s\n", s4);
    // char s5[] = "1";
    // strgChangeCase(s5);
    // printf("%s\n", s5);
    // char s6[] = "";
    // strgChangeCase(s6);
    // printf("%s\n", s6);
    // strgChangeCase(NULL);   //Does nothing and Returns

	/** ---------------------- **/
	return 0;
}
