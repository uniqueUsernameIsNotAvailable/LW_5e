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