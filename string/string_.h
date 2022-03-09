#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#ifndef LW_5E_STRING__H
#define LW_5E_STRING__H

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

//Returning the length of the string.
size_t strLen(char *start);

//It finds the first occurrence of the character `target` in the string.
char *find(char *start, const char *end, int target);

//Finding the first non-space character in the string.
char *findNonSpace(char *start);

//Finding the first space character in the string.
char *findSpace(char *start);

//Finding the first non-space character in the string by reversed order.
char *findNonSpaceReverse(char *rstart, const char *rend);

//Finding the first space character in the string by reversed order.
char *findSpaceReverse(char *rstart, const char *rend);

//Comparing two strings.
int strcmp(const char *lhs, const char *rhs);

//Copying the string from the source to the destination.
char *copy(const char *startSource, const char *endSource, char *startDestination);

//Copying the string from the source to the destination by predicate.
char *copyIf(char *startSource, const char *endSource, char *startDestination, int (*f)(int));

//Copying the string from the source to the destination by predicate by reversed order.
char *copyIfReverse(char *rstartSource, const char *rendSource, char *startDestination, int (*f)(int));

//Returning the length of the word.
int getWord(char *beginSearch, WordDescriptor *word);

//Comparing two words.
int areWordsEqual(WordDescriptor word1, WordDescriptor word2);

//Filling the `bag` with the words from the `s`.
void getBagOfWords(BagOfWords *bag, char *s);

//Assert function that checks if the string `got` is equal to the string `expected`.
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

#endif //LW_5E_STRING__H
