#include <assert.h>
#include "../string_.h"

char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
BagOfWords _bag2;

int true() {
    return 1;
}

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
void digitToStart_(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStart(char *s) {
    char *startSearch = s;
    WordDescriptor word;

    while (getWord(startSearch, &word)) {
        digitToStart_(word);
        startSearch = word.end;
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
    char *startBuffer = _stringBuffer;

    while (startBuffer < endBuffer) {
        if (isdigit(*startBuffer)) {
            long long spacesAmount = *startBuffer - '0';

            for (int i = 0; i < spacesAmount; ++i)
                *s++ = ' ';

        } else
            *s++ = *startBuffer;

        startBuffer++;
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
_Bool areWordsOrdered(char *s) {
    WordDescriptor w1;
    WordDescriptor w2;
//check
    if (!getWord(s, &w1))
        return 1;

    while (getWord(s, &w2)) {
        if (!areWordsEqual(w1, w2) && strcmp(w1.begin, w2.begin) > 0)
            return 0;

        w1 = w2;
        s = w2.end;
    }

    return 1;
}

void test_areWordsOrdered_emptyString() {
    char s[] = "";

    assert(areWordsOrdered(s) == 1);
}

void test_areWordsOrdered_noOrderString() {
    char s[] = "hello World";

    assert(areWordsOrdered(s) == 0);
}

void test_areWordsOrdered_oneWordString() {
    char s[] = "Hello";

    assert(areWordsOrdered(s) == 1);
}

void test_areWordsOrdered_orderedString() {
    char s[] = "Hello world";

    assert(areWordsOrdered(s) == 1);
}

void test_areWordsOrdered() {
    test_areWordsOrdered_emptyString();
    test_areWordsOrdered_oneWordString();
    test_areWordsOrdered_noOrderString();
    test_areWordsOrdered_orderedString();
}

//---------------------------------------- TASK 7
void reverseOutputWordsFromBag(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    char *start = s;
    for (int i = 0; i < _bag.size; i++) {
        *copyIfReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, start, true) = '\0';
        printf("%s \n", start);
    }
}

//---------------------------------------- TASK 8
_Bool isPaliWord(char *begin, char *end) {
    end--;

    while (end - begin > 0) {
        if (*begin != *end)
            return 0;

        begin++;
        end--;
    }

    return 1;
}


int countPaliWords(char *s) {
    char *end = getEndOfString(s);
    char *beginSearch = findNonSpace(s);

    int amountOfPaliWords = 0;

    char *separatorPlace = find(beginSearch, end, ',');
    _Bool separatorNotFound = *separatorPlace == '\0' && end - beginSearch != 0;

    while (*separatorPlace != '\0' || separatorNotFound) {
        amountOfPaliWords += isPaliWord(beginSearch, separatorPlace);

        beginSearch = separatorPlace + 1;

        if (*separatorPlace == '\0')
            return amountOfPaliWords;

        separatorPlace = find(beginSearch, end, ',');
        separatorNotFound = *separatorPlace == '\0';
    }

    return amountOfPaliWords;
}

void test_countPaliWords_emptyString() {
    char s[] = "";

    assert(countPaliWords(s) == 0);
}

void test_countPaliWords_multiplePalindromeString() {
    char s[] = "AABAA,BBABB";
    assert(countPaliWords(s) == 2);
}

void test_countPaliWords_notEveryIsPalindromeString() {
    char s[] = "AABAA, BBAAB";
    assert(countPaliWords(s) == 1);
}

void test_getCountPoly() {
    test_countPaliWords_emptyString();
    test_countPaliWords_multiplePalindromeString();
    test_countPaliWords_notEveryIsPalindromeString();
}
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
    test_areWordsOrdered();
    char s7[] = "ABCCCB";
    reverseOutputWordsFromBag(s7);
    test_getCountPoly();
}


