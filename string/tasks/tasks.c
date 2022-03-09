#include "../string_.h"

char _stringBuffer[MAX_STRING_SIZE + 1];

//---------------------------------------- TASK 1
char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;
    return s;
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_simpleCase() {
    char testString[] = "A   B \n \t C D";
    removeNonLetters(testString);

    ASSERT_STRING("ABCD", testString);
}

//---------------------------------------- TASK 2
void removeExtraSpaces(char *s) {
    char *start = s;
    char *end = start;

    char next = *start;

    while (*start != '\0') {
        if (*start != next || !isspace(next))
            *end++ = *start;

        next = *start++;
    }

    *end = '\0';
}

void test_removeExtraSpaces_simpleCase() {
    char testString[] = "The       quick    brown fox jumps   over the lazy dog";
    removeExtraSpaces(testString);

    ASSERT_STRING("The quick brown fox jumps over the lazy dog", testString);
}

void test_removeExtraSpaces_emptyStringCase() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_lastSpaceStringCase() {
    char s[] = "The quick brown fox jumps over the lazy dog  ";
    removeExtraSpaces(s);
    ASSERT_STRING("The quick brown fox jumps over the lazy dog ", s);
}


//---------------------------------------- TASK 3.3
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart_(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStart(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart_(word);
        beginSearch = word.end;
    }
}

void test_digitToStart_simpleCase() {
    char testString[] = "SimpleText123";
    digitToStart(testString);

    ASSERT_STRING("123SimpleText", testString);
}

void test_digitToStart_emptyStringCase() {
    char s[] = "";
    digitToStart(s);

    ASSERT_STRING("", s);
}

void test_digitToStart_difficultCase() {
    char s[] = "123Simple Text23";
    digitToStart(s);

    ASSERT_STRING("123Simple 23Text", s);
}

//---------------------------------------- TASK 4
void replaceNumsWithSpaces(char *s) {
    char *endBuffer = copy(s, s + strLen(s), _stringBuffer);
    char *beginBuffer = _stringBuffer;

    while (beginBuffer < endBuffer) {
        if (isdigit(*beginBuffer)) {
            long long spacesAmount = *beginBuffer - '0';

            for (int i = 0; i < spacesAmount; ++i)
                *s++ = ' ';

        } else
            *s++ = *beginBuffer;

        beginBuffer++;
    }

    *s = '\0';
}

void test_replaceNumsWithSpaces_emptyString() {
    char s[] = "";
    replaceNumsWithSpaces(s);

    ASSERT_STRING("", s);
}

void test_replaceNumsWithSpaces_noNums() {
    char s[] = "simple text";
    replaceNumsWithSpaces(s);

    ASSERT_STRING("simple text", s);
}

void test_replaceNumsWithSpaces_numsOnly() {
    char s[MAX_STRING_SIZE] = "012";
    replaceNumsWithSpaces(s);

    ASSERT_STRING("   ", s);
}

void test_replaceNumsWithSpaces_simpleCase() {
    char s[MAX_STRING_SIZE] = "oneSpace1twoSpaces2";
    replaceNumsWithSpaces(s);

    ASSERT_STRING("oneSpace twoSpaces  ", s);
}

void test_replaceNumsWithSpaces() {
    test_replaceNumsWithSpaces_emptyString();
    test_replaceNumsWithSpaces_noNums();
    test_replaceNumsWithSpaces_numsOnly();
    test_replaceNumsWithSpaces_simpleCase();
}
//---------------------------------------- TASK 5
//---------------------------------------- TASK 6
//---------------------------------------- TASK 7
//---------------------------------------- TASK 8
//---------------------------------------- TASK 9

//---------------------------------------- TASK 10

//---------------------------------------- TASK 11

//---------------------------------------- TASK 12

//---------------------------------------- TASK 13

//---------------------------------------- TASK 14

//---------------------------------------- TASK 15

//---------------------------------------- TASK 16

//---------------------------------------- TASK 17

//---------------------------------------- TASK 18

//---------------------------------------- TASK 19

int main() {
    test_removeNonLetters_simpleCase();
    test_removeExtraSpaces_simpleCase();
    test_removeExtraSpaces_emptyStringCase();
    test_removeExtraSpaces_lastSpaceStringCase();
    test_digitToStart_simpleCase();
    test_digitToStart_emptyStringCase();
    test_digitToStart_difficultCase();
    test_replaceNumsWithSpaces();
}


