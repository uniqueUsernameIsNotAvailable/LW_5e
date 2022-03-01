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
    assert(findNonSpace(s) == s+4);
}

void test_findNonSpace_spacesString() {
    char s[] = "\t \n   ";
    assert(findNonSpace(s) == s+6);
}

void test_findNonSpace() {
    test_findNonSpace_emptyString();
    test_findNonSpace_defaultString();
    test_findNonSpace_spacesString();
}



void test_findSpace_noSpacesString(){
    char s[] = "ab";
    assert(findSpace(s) == s+2);
}

void test_findSpace_defaultString() {
    char s[] = "abc\t \n abc /t ";
    assert(findSpace(s) == s+3);
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
    assert(findNonSpaceReverse(s+2, s-1) == s-1);
}

void test_findNonSpaceReverse_defaultString() {
    char s[] = "\t \n abc \t";
    assert(findNonSpaceReverse(s+8, s-1) == s+7);
}

void test_findNonSpaceReverse_noSpacesString() {
    char s[] = "abcd";
    assert(findNonSpaceReverse(s+3, s-1) == s+3);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_spacesString();
    test_findNonSpaceReverse_defaultString();
    test_findNonSpaceReverse_noSpacesString();
}



void test_findSpaceReverse_noSpacesString(){
    char s[] = "bcde";
    assert(findSpaceReverse(s+3, s-1) == s-1);
}

void test_findSpaceReverse_defaultString() {
    char s[] = " \t ";
    assert(findSpaceReverse(s+2, s-1) == s+2);
}

void test_findSpaceReverse_spacesString() {
    char s[] = " \t ";
    assert(findSpaceReverse(s+2, s-1) == s+2);
}
void test_findSpaceReverse() {
    test_findSpaceReverse_noSpacesString();
    test_findSpaceReverse_defaultString();
    test_findSpaceReverse_spacesString();
}

int main() {
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();

    /*
     */
    return 0;
}
