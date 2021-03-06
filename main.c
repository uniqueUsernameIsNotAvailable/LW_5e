#include <stdio.h>
#include <assert.h>
#include "string/string_.h"

//-------------------------------------TESTS
void test_findNonSpace_emptyString() {
    char s[] = "";
    assert(findNonSpace(s) == s);
}

void test_findNonSpace_defaultString() {
    char s[] = "\t \n abc /t ";
    assert(findNonSpace(s) == s + 4);
}

void test_findNonSpace_spacesString() {
    char s[] = "\t \n   ";
    assert(findNonSpace(s) == s + 6);
}

void test_findNonSpace() {
    test_findNonSpace_emptyString();
    test_findNonSpace_defaultString();
    test_findNonSpace_spacesString();
}


void test_findSpace_noSpacesString() {
    char s[] = "ab";
    assert(findSpace(s) == s + 2);
}

void test_findSpace_defaultString() {
    char s[] = "abc\t \n abc /t ";
    assert(findSpace(s) == s + 3);
}

void test_findSpace_spacesString() {
    char s[] = "\t \n   ";
    assert(findSpace(s) == s);
}

void test_findSpace() {
    test_findSpace_noSpacesString();
    test_findSpace_defaultString();
    test_findSpace_spacesString();
}


void test_findNonSpaceReverse_spacesString() {
    char s[] = " \t ";
    assert(findNonSpaceReverse(s + 2, s - 1) == s - 1);
}

void test_findNonSpaceReverse_defaultString() {
    char s[] = "\t \n abc \t";
    assert(findNonSpaceReverse(s + 8, s - 1) == s + 7);
}

void test_findNonSpaceReverse_noSpacesString() {
    char s[] = "abcd";
    assert(findNonSpaceReverse(s + 3, s - 1) == s + 3);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_spacesString();
    test_findNonSpaceReverse_defaultString();
    test_findNonSpaceReverse_noSpacesString();
}


void test_findSpaceReverse_noSpacesString() {
    char s[] = "bcde";
    assert(findSpaceReverse(s + 3, s - 1) == s - 1);
}

void test_findSpaceReverse_defaultString() {
    char s[] = " \t ";
    assert(findSpaceReverse(s + 2, s - 1) == s + 2);
}

void test_findSpaceReverse_spacesString() {
    char s[] = " \t ";
    assert(findSpaceReverse(s + 2, s - 1) == s + 2);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_noSpacesString();
    test_findSpaceReverse_defaultString();
    test_findSpaceReverse_spacesString();
}


void test_strcmp_equalStrings() {
    char s[] = " \t ";
    char s1[] = " \t ";

    assert(strcmp(s, s1) == 0);
}

void test_strcmp_firstStringLower() {
    char s[] = "IMLOWER";
    char s1[] = "imhigher";

    assert(strcmp(s, s1) < 0);
}

void test_strcmp_secondStringLower() {
    char s[] = "imhigher";
    char s1[] = "IMLOWER";

    assert(strcmp(s, s1) > 0);
}

void test_strcmp_stringContainsStringLower() {
    char s[] = "imhigher";
    char s1[] = "IMLOWER";

    assert(strcmp(s, s1) > 0);
}

void test_strcmp() {
    test_strcmp_equalStrings();
    test_strcmp_firstStringLower();
    test_strcmp_secondStringLower();
    test_strcmp_stringContainsStringLower();
}

void test_copy_defaultString(){
    char s1[8] = "abcdefg";
    char s2[100];

    char *newPointer = copy(&s1[0], &s1[7], s2);
    assert(s2[0] == 'a');
    assert(s2[1] == 'b');
    assert(s2[2] == 'c');
    assert(s2[3] == 'd');
    assert(s2[4] == 'e');
    assert(s2[5] == 'f');
    assert(s2[6] == 'g');
    ASSERT_STRING("abcdefg", s2);
    assert(&s2[7] == newPointer);
}

void test_copyIf_defaultString(){
    char s1[8] = "abcdefg";
    char s2[10];

    char *newPointer = copyIf(&s1[0], &s1[7], s2, isgraph);
    assert(s2[0] == 'a');
    assert(&s2[7] == newPointer);
//    assert(s2[0] == 'a');
//    assert(s2[1] == 'b');
//    assert(s2[2] == 'c');
//    assert(s2[3] == 'd');
//    assert(s2[4] == 'e');
//    assert(s2[5] == 'f');
//    assert(s2[6] == 'g');
//    assert(&s2[7] == newPointer);
}
void test_copy(){
    test_copy_defaultString();
    test_copyIf_defaultString();
}

int main() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    /*
     */
    return 0;
}

