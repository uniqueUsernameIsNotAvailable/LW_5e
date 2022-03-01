#include <stdio.h>

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

#endif //LW_5E_STRING__H
