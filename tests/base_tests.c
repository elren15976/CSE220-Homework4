#include <criterion/criterion.h>
#include <string.h>

#include "caesar.h" 
#include "strPtr.h"


/*
 * Part 1: String utility functions
 */

Test(strgLen, basic) {
    cr_assert_eq(strgLen("Stony Brook"), 11);
    cr_assert_eq(strgLen("CSE 220"), 7);
    cr_assert_eq(strgLen("C"), 1);
    cr_assert_eq(strgLen("System Fundamental"), 18);
    cr_assert_eq(strgLen("1"), 1);
    cr_assert_eq(strgLen(""), 0);
    cr_assert_eq(strgLen("1234567890-=+_"), 14);
    cr_assert_eq(strgLen("\n\n\n"), 3);
    cr_assert_eq(strgLen("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"), 52);
}

Test(strgLen, null_input) {
    cr_assert_eq(strgLen(NULL), -1);
}

Test(strgCopy, normal_and_empty) {
    char dest[32] = {0};
    strgCopy(dest, "Computer Science");
    cr_assert_str_eq(dest, "Computer Science");

    dest[0] = '\0';
    strgCopy(dest, "");
    cr_assert_str_eq(dest, "");

    strgCopy(dest, "CSE-220");
    cr_assert_str_eq(dest, "CSE-220");

    strgCopy(dest, "System Fundamental");
    cr_assert_str_eq(dest, "System Fundamental");

    strgCopy(dest, "1");
    cr_assert_str_eq(dest, "1");

    strgCopy(dest, "Hello!");
    cr_assert_str_eq(dest, "Hello!");

    strgCopy(dest, "\t\they");
    cr_assert_str_eq(dest, "\t\they");

    strgCopy(dest, "\t .\t.\n\t\\________/");   //Smiley Face
    cr_assert_str_eq(dest, "\t .\t.\n\t\\________/");
}

// Test(strgCopy, truncation) {
//     char d[5] = {0};
//     strgCopy(d, "Computer Science");
//     cr_assert_str_eq(d, "Comp");  // 4 chars + '\0'
// }

Test(strgCopy, null_args_do_nothing) {
    char dest[16] = "UNCHANGED";
    strgCopy(NULL, "foo");
    cr_assert_str_eq(dest, "UNCHANGED");
    strgCopy(dest, NULL);
    cr_assert_str_eq(dest, "UNCHANGED");
}

Test(strgChangeCase, flip_only_non_adjacent_to_digits) {
    char s1[] = "Stony Brook";
    strgChangeCase(s1);
    cr_assert_str_eq(s1, "sTONY bROOK");

    char s2[] = "CSE220";
    strgChangeCase(s2);
    cr_assert_str_eq(s2, "csE220");

    char s3[] = "a1b";
    strgChangeCase(s3);
    cr_assert_str_eq(s3, "a1b");

    char s4[] = "A9B";
    strgChangeCase(s4);
    cr_assert_str_eq(s4, "A9B");

    char s5[] = "_X_";
    strgChangeCase(s5);
    cr_assert_str_eq(s5, "_x_");

    char s6[] = "System Fundamental220";
    strgChangeCase(s6);
    cr_assert_str_eq(s6, "sYSTEM fUNDAMENTAl220");

    char s7[] = "a1ab2bc3cd4de5ef6fg7g";
    strgChangeCase(s7);
    cr_assert_str_eq(s7, "a1ab2bc3cd4de5ef6fg7g");

    char s8[] = "1_+{];'[];[-=_+:]}";
    strgChangeCase(s8);
    cr_assert_str_eq(s8, "1_+{];'[];[-=_+:]}");
    
    char s9[] = "A-aB+bC=cD_dE]eF.fG;g";
    strgChangeCase(s9);
    cr_assert_str_eq(s9, "a-Ab+Bc=Cd_De]Ef.Fg;G");

    char s10[] = "zyxwvutsr\t3AAAa";
    strgChangeCase(s10);
}

Test(strgChangeCase, empty_and_digit_only) {
    char e1[] = "";
    strgChangeCase(e1);
    cr_assert_str_eq(e1, "");

    char e2[] = "1";
    strgChangeCase(e2);
    cr_assert_str_eq(e2, "1");
}

Test(strgDiff, differences_and_equals) {
    cr_assert_eq(strgDiff("Hello","Hello"), -1);
    cr_assert_eq(strgDiff("CSE-220","CSE220"), 3);
    cr_assert_eq(strgDiff("CSE220","SE220"), 0);
    cr_assert_eq(strgDiff("",""), -1);
    cr_assert_eq(strgDiff("ABCDEF", "ABCDE"), 5);
    cr_assert_eq(strgDiff("\t\tHEY!", "\t\tHEY!"), -1);
    cr_assert_eq(strgDiff("\t\tHello", "\t\tHEY!"), 3);
    cr_assert_eq(strgDiff("\t\tHello", "\t\nHEY!"), 1);
}

Test(strgDiff, null_inputs) {
    cr_assert_eq(strgDiff(NULL, "foo"), -2);
    cr_assert_eq(strgDiff("foo", NULL), -2);
    cr_assert_eq(strgDiff(NULL, NULL), -2);
}

Test(strgInterleave, normal_and_unequal_lengths) {
    char dest[32] = {0};

    strgInterleave("abc","123", dest);
    cr_assert_str_eq(dest, "a1b2c3");

    strgInterleave("abcdef","123", dest);
    cr_assert_str_eq(dest, "a1b2c3def");

    strgInterleave("cse","12345", dest);
    cr_assert_str_eq(dest, "c1s2e345");

    strgInterleave("1234","cs", dest);
    cr_assert_str_eq(dest, "1c2s34");

    strgInterleave("", "", dest);
    cr_assert_str_eq(dest, "");

    strgInterleave("","123", dest);
    cr_assert_str_eq(dest, "123");

    strgInterleave("\t \t ab", "123 ", dest);
    cr_assert_str_eq(dest, "\t1 2\t3  ab");

    strgInterleave("_+{}:<>?", "1 a2\t3", dest);
    cr_assert_str_eq(dest, "_1+ {a}2:\t<3>?");

    char dest2[32] = "UNCHANGED";

    strgInterleave("NULL", NULL, dest2);
    cr_assert_str_eq(dest2, "UNCHANGED");

    strgInterleave(NULL, "Hi", dest2);
    cr_assert_str_eq(dest2, "UNCHANGED");
}

// Test(strgInterleave, truncation) {
//     char tiny[5] = {0};
//     strgInterleave("abc","123", tiny);
//     cr_assert_str_eq(tiny, "a1b2");  // truncated to 4 chars + '\0'
// }

Test(strgReverseLetters, basic) {
    char t1[] = "hello";
    strgReverseLetters(t1);
    cr_assert_str_eq(t1, "olleh");

    char t2[] = "hello world";
    strgReverseLetters(t2);
    cr_assert_str_eq(t2, "dlrow olleh");

    char t3[] = "ab-cd";
    strgReverseLetters(t3);
    cr_assert_str_eq(t3, "dc-ba");

    char t4[] = "e1f!";
    strgReverseLetters(t4);
    cr_assert_str_eq(t4, "f1e!");

    char t5[] = "_X_";
    strgReverseLetters(t5);
    cr_assert_str_eq(t5, "_X_");

    char t6[] = "";
    strgReverseLetters(t6);
    cr_assert_str_eq(t6, "");

    char t7[] = "a1b2c";
    strgReverseLetters(t7);
    cr_assert_str_eq(t7, "c1b2a");

    char t8[] = "\tHEY! I would like 3 pineapple pies :)";
    strgReverseLetters(t8);
    cr_assert_str_eq(t8, "\tsei! p elppa enip 3 ekildluow IYEH :)");

    char t9[] = "aaA123_+[][:>><?']321BB";
    strgReverseLetters(t9);
    cr_assert_str_eq(t9, "BBA123_+[][:>><?']321aa");

    char t10[] = "sbat re tfaera ereh\t\tsre ttelehT sbat ero febsi sihT!"; //Already reverse. Reverse for message
    strgReverseLetters(t10);
    cr_assert_str_eq(t10, "This is before tabs\t\tThe letters here are after tabs!");
}

/*
 * Part 2: Position-aware Caesar cipher
 */

/* encryptCaesar tests */


Test(encryptCaesar, basic_shifts) {
    char out[64];

    cr_assert_eq(encryptCaesar("abc",  out, 2), 3);
    cr_assert_str_eq(out, "ceg__EOM__");

    cr_assert_eq(encryptCaesar("Ayb",  out, 3), 3);
    cr_assert_str_eq(out, "Dcg__EOM__");

    cr_assert_eq(encryptCaesar("Cse220", out, 1), 6);
    cr_assert_str_eq(out, "Duh911__EOM__");

    cr_assert_eq(encryptCaesar("CS",   out, 0), 2);
    cr_assert_str_eq(out, "CT__EOM__");

    cr_assert_eq(encryptCaesar("System Fundamentals", out, 1), 18);
    cr_assert_str_eq(out, "Tavxjs Ndxomzscjrdl__EOM__");

    cr_assert_eq(encryptCaesar("[]_+;?><123", out, 1), 3);
    cr_assert_str_eq(out, "[]_+;?><814__EOM__");

    cr_assert_eq(encryptCaesar("1234567", out, 0), 7);
    cr_assert_str_eq(out, "1470369__EOM__");
}

Test(encryptCaesar, empty_input) {
    char out[32] = {0};
    cr_assert_eq(encryptCaesar("", out, 42), 0);
    cr_assert_str_eq(out, "undefined__EOM__");
}

// Test(encryptCaesar, insufficient_space) {
//     /* buffer length = 1 (only NUL), always too small */
//     char b1[1] = {0};
//     cr_assert_eq(encryptCaesar("anything", b1, 5), -1);

//     /* buffer length = 4, contains "abc", so strlen=3, still too small for __EOM__ */
//     char b2[4] = "abc";
//     cr_assert_eq(encryptCaesar("abc", b2, 2), -1);
// }

Test(encryptCaesar, null_args) {
    char out[16];
    cr_assert_eq(encryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(encryptCaesar("hi",  NULL, 5), -2);
}

/* decrypt tests */

Test(decryptCaesar, basic_unshifts) {
    char out[64] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

    cr_assert_eq(decryptCaesar("Tavxjs Ndxomzscjrdl__EOM__", out, 1), 18);
    cr_assert_str_eq(out, "System Fundamentals");

    cr_assert_eq(decryptCaesar("1470369__EOM__", out, 0), 7);
    cr_assert_str_eq(out, "1234567");

    cr_assert_eq(decryptCaesar("Duh911__EOM__", out, 1), 6);
    cr_assert_str_eq(out, "Cse220");

    cr_assert_eq(decryptCaesar("ceg__EOM__", out, 2), 3);
    cr_assert_str_eq(out, "abc");

    cr_assert_eq(decryptCaesar("Dcg__EOM__", out, 3), 3);
    cr_assert_str_eq(out, "Ayb");

    cr_assert_eq(decryptCaesar("CT__EOM__", out, 0), 2);
    cr_assert_str_eq(out, "CS");
}

Test(decryptCaesar, empty_input_marker) {
    char out[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    cr_assert_eq(decryptCaesar("undefined__EOM__", out, 7), 0);
    cr_assert_str_eq(out, "undefined");
}

Test(decryptCaesar, zero_length_plaintext) {
    /* initial strlen(plaintext)==0 ⇒ return 0, no write */
    char p[1] = "";
    cr_assert_eq(decryptCaesar("ceg__EOM__", p, 2), 0);
    cr_assert_str_eq(p, "");
}

Test(decryptCaesar, missing_marker) {
    /* plaintext must remain unchanged */
    char buf[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    strcpy(buf, "no marker here");
    cr_assert_eq(decryptCaesar("no marker here", buf, 1), -1);
    cr_assert_str_eq(buf, "no marker here");
}

Test(decryptCaesar, null_args) {
    char out[16] = "xxxxxxxxxxxxxxx";
    cr_assert_eq(decryptCaesar(NULL, out, 5), -2);
    cr_assert_eq(decryptCaesar("abc__EOM__", NULL, 5), -2);
}

Test(decryptCaesar, truncation_by_strlen) {
    /* initial strlen(plaintext)==4 ⇒ can only store 4 chars + NUL */
    char p[5] = "xxxx";
    int rv = decryptCaesar("Duh911__EOM__", p, 1);
    cr_assert_eq(rv, 6);
    cr_assert_str_eq(p, "Cse2");
}