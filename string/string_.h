#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#ifndef LW_5E_STRING__H
#define LW_5E_STRING__H

/*!
 *
 * @param start
 * @return
 */
size_t strLen(char *start);


char *findNonSpace(char *start);

char *findSpace(char *start);

char *findNonSpaceReverse(char *rstart, const char *rend);

char *findSpaceReverse(char *rstart, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char* copy(const char *startSource, const char *endSource, char *startDestination);

char* copyIf(char *startSource, const char *endSource, char *startDestination, int (*f)(int));

char* copyIfReverse(char *rstartSource, const char *rendSource, char *startDestination, int (*f)(int));

#endif //LW_5E_STRING__H
