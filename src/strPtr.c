#include <stdlib.h>
#include "strPtr.h"

#include <stdlib.h>
#include "strPtr.h"

/*
 *  Elijah Ren - CSE 220
 *  116253293
*/

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

        if(*(src+idx) == 0){    //Copy first, then break if needed
            break;
        }
    }
}

void strgChangeCase(char *s) {
    if(s == NULL){
        return;
    }

    for(int idx = 0; *(s+idx) != 0; idx++){
        //Check surrounding characters if they are digits
        if((*(s+idx+1) >= 48 && *(s+idx+1) <= 57) ||            //If next character is a digit
           (idx != 0 && *(s+idx-1) >= 48 && *(s+idx-1) <= 57)){ //If this is NOT the first character and previous character is a digit
            continue;
        }

        //Lower case
        if(*(s+idx) >= 97 && *(s+idx) <= 122){
            *(s+idx) = *(s+idx)-32;
        }
        //Upper case
        else if(*(s+idx) >= 65 && *(s+idx) <= 90){
            *(s+idx) = *(s+idx)+32;
        }
    }
}

int strgDiff(char *s1, char *s2) {
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

void strgInterleave(char *s1, char *s2, char *d) {
    if(s1 == NULL || s2 == NULL || d == NULL){
        return;
    }

    int s1Idx = 0;
    int s2Idx = 0;
    int dIdx = 0;

    //While both strings are NOT null character, copy and keep going
    while(*(s1+s1Idx) != 0 && *(s2+s2Idx) != 0){
        *(d+dIdx) = *(s1+s1Idx);
        *(d+dIdx+1) = *(s2+s2Idx);

        s1Idx++;
        s2Idx++;
        dIdx+=2;
    }

    //Check which string still has leftover characters
    if(*(s1+s1Idx) == 0){
        while(*(s2+s2Idx) != 0){
            *(d+dIdx) = *(s2+s2Idx);
            s2Idx++;
            dIdx++;
        }
    }
    else if(*(s2+s2Idx) == 0){
        while(*(s1+s1Idx) != 0){
            *(d+dIdx) = *(s1+s1Idx);
            s1Idx++;
            dIdx++;
        }
    }

    //End on null character
    *(d+dIdx) = 0;
}

void strgReverseLetters(char *s) {
    if(s == NULL){
        return;
    }

    int len = strgLen(s);
    char mem[len];
    int memIdx = 0;

    //Start from end, go to beginning
    while(len > 0){
        len--;
        //If not an alphabet character, skip over it
        if(!((*(s+len) >= 97 && *(s+len) <= 122) || (*(s+len) >= 65 && *(s+len) <= 90))){
            continue;
        }

        //Otherwise, add character to "mem" array
        mem[memIdx] = *(s+len);
        memIdx++;
    }

    //Replace original string with contents in "mem" array
    //Already stored in reverse order
    for(int idx = 0; *(s+idx) != 0; idx++){
        //If current character isn't alphabet, skip over it
        if(!((*(s+idx) >= 97 && *(s+idx) <= 122) || (*(s+idx) >= 65 && *(s+idx) <= 90))){
            continue;
        }

        *(s+idx) = mem[len];
        len++;
    }
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
// int main(int argc, char* argv[]){
// 	(void)argc;
// 	(void)argv;
// 	/** CREATE TEST CASES HERE **/

// 	// printf("%d\n", strgLen("Stony Brook"));
// 	// printf("%d\n", strgLen("CSE 220"));
// 	// printf("%d\n", strgLen("C"));
// 	// printf("%d\n", strgLen("System Fundamental"));
// 	// printf("%d\n", strgLen("1"));
// 	// printf("%d\n", strgLen(""));
// 	// printf("%d\n", strgLen("1234567890-=+_"));
// 	// printf("%d\n", strgLen("\n\n\n"));
// 	// printf("%d\n", strgLen("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"));
// 	// printf("%d\n", strgLen(NULL));

//     // char dest[32] = {0};
//     // strgCopy(dest, "Computer Science");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "CSE-220");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "System Fundamental");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "1");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "Hello!");
//     // printf("%s\n", dest);
//     // strgCopy(dest, NULL);       //Does nothing
//     // printf("%s\n", dest);
//     // strgCopy(NULL, "Hello!");   //Does nothing
//     // printf("%s\n", dest);
//     // strgCopy(dest, "\t\they");
//     // printf("%s\n", dest);
//     // strgCopy(dest, "\t .\t.\n\t\\________/"); //Smiley face
//     // printf("%s\n", dest);

//     // char s1[] = "Stony Brook";
//     // strgChangeCase(s1);
//     // printf("%s\n", s1);
//     // char s2[] = "CSE220";
//     // strgChangeCase(s2);
//     // printf("%s\n", s2);
//     // char s3[] = "a1b";
//     // strgChangeCase(s3);
//     // printf("%s\n", s3);
//     // char s4[] = "System Fundamental220";
//     // strgChangeCase(s4);
//     // printf("%s\n", s4);
//     // char s5[] = "1";
//     // strgChangeCase(s5);
//     // printf("%s\n", s5);
//     // char s6[] = "";
//     // strgChangeCase(s6);
//     // printf("%s\n", s6);
//     // strgChangeCase(NULL);   //Does nothing and Returns
//     // char s7[] = "a1ab2bc3cd4de5ef6fg7g";
//     // strgChangeCase(s7);
//     // printf("%s\n", s7);
//     // char s8[] = "1_+{];'[];[-=_+:]}";
//     // strgChangeCase(s8);
//     // printf("%s\n", s8);
//     // char s9[] = "A-aB+bC=cD_dE]eF.fG;g";
//     // strgChangeCase(s9);
//     // printf("%s\n", s9);
//     // char s10[] = "ZYXWVUTSR\t3AaaA";
//     // strgChangeCase(s10);
//     // printf("%s\n", s10);

//     // printf("%d\n", strgDiff("Hello", "Hello"));
//     // printf("%d\n", strgDiff("CSE-220", "CSE220"));
//     // printf("%d\n", strgDiff("CSE220", "SE220"));
//     // printf("%d\n", strgDiff("", ""));
//     // printf("%d\n", strgDiff("ABCDEF", "ABCDE"));
//     // printf("%d\n", strgDiff(NULL, NULL));
//     // printf("%d\n", strgDiff(NULL, "NULL"));
//     // printf("%d\n", strgDiff("\t\tHEY!", "\t\tHEY!"));
//     // printf("%d\n", strgDiff("\t\tHello", "\t\tHEY!"));
//     // printf("%d\n", strgDiff("\t\tHello", "\t\nHEY!"));

//     // char dest[32] = {0};
//     // strgInterleave("abc", "123", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("abcdef", "123", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("cse", "12345", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("1234", "cs", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("", "", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("", "123", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("NULL", NULL, dest); //Does nothing
//     // strgInterleave(NULL, NULL, dest);   //Does nothing
//     // strgInterleave("\t \t ab", "123 ", dest);
//     // printf("%s\n", dest);
//     // strgInterleave("_+{}:<>?", "1 a2\t3", dest);
//     // printf("%s\n", dest);

//     // char t1[] = "Hello";
//     // strgReverseLetters(t1);
//     // printf("%s\n", t1);
//     // char t2[] = "ab-cd";
//     // strgReverseLetters(t2);
//     // printf("%s\n", t2);
//     // char t3[] = "a1b2c";
//     // strgReverseLetters(t3);
//     // printf("%s\n", t3);
//     // char t4[] = "hello world";
//     // strgReverseLetters(t4);
//     // printf("%s\n", t4);
//     // char t5[] = "_X_";
//     // strgReverseLetters(t5);
//     // printf("%s\n", t5);
//     // char t6[] = "";
//     // strgReverseLetters(t6);
//     // printf("%s\n", t6);
//     // char t7[] = "elf!";
//     // strgReverseLetters(t7);
//     // printf("%s\n", t7);
//     // char t8[] = "\tHEY! I would like 3 pineapple pies :)";
//     // strgReverseLetters(t8);
//     // printf("%s\n", t8);
//     // char t9[] = "aaA123_+[][:>><?']321BB";
//     // strgReverseLetters(t9);
//     // printf("%s\n", t9);
//     // char t10[] = "sbat re tfaera ereh\t\tsre ttelehT sbat ero febsi sihT!"; //Already reverse. Reverse for message
//     // strgReverseLetters(t10);
//     // printf("%s\n", t10);

// 	/** ---------------------- **/
// 	return 0;
// }
