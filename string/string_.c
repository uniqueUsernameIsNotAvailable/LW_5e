#include "string_.h"

size_t strLen(char *start) {
    char *end = start;
    while (*end != '\0')
        end++;

    return end - start;
}


char *find(char *start, const char *end, int target) {
    while (start != end && *start != target)
        start++;

    return start;
}


char *findNonSpace(char *start) {
    while (*start != '\0' && (isspace(*start)))
        start++;

    return start;
}

char *findSpace(char *start) {
    while (*start != '\0' && !(isspace(*start)))
        start++;

    return start;
}

char *findNonSpaceReverse(char *rstart, const char *rend) {
    while (*rstart != *rend && (isspace(*rstart)))
        rstart--;

    return rstart;
}


char *findSpaceReverse(char *rstart, const char *rend) {
    while (*rstart != *rend && !(isspace(*rstart)))
        rstart--;

    return rstart;
}

//seems working pretty well
int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *rhs == *lhs)
        lhs++, rhs++;

    return *lhs - *rhs;
}

char *copy(const char *startSource, const char *endSource, char *startDestination) {
    memcpy(startDestination, startSource, endSource - startSource);

    return startDestination + (endSource - startSource);
}

char *copyIf(char *startSource, const char *endSource, char *startDestination, int (*f)(int)) {
    while (startSource != endSource) {
        if (f(*startSource)) {
            *startDestination = *startSource;
            startDestination++;
        }
        startSource++;
    }

    return startDestination;
}

char *copyIfReverse(char *rstartSource, const char *rendSource, char *startDestination, int (*f)(int)) {
    while (rstartSource != rendSource) {
        if (f(*rstartSource)) {
            *startDestination = *rstartSource;
            startDestination++;
        }
        rstartSource--;
    }

    return startDestination;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    if (w1.end - w1.begin != w2.end - w2.begin)
        return 0;

    return !memcmp(w1.begin, w2.begin, w1.end - w1.begin);
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, " Got : \"%s \"\n\n", got);
    } else
        fprintf(stderr, "%s - :) \n", funcName);
}
