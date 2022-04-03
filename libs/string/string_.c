//
// Created by Admin on 02.04.2022.
//

#include "string_.h"

size_t strlen(const char *begin) {
    const char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* findNonSpace(char *begin){
    while(*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char* findSpace(char *begin){
    while(*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend){
    while(rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs){
    while(*lhs == *rhs && *lhs != '\0')
        lhs++, rhs++;

    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination){
    const char *begin = beginSource;
    while(begin != endSource){
        *beginDestination = *begin;
        beginDestination++;
        begin++;
    }
    return beginDestination;
}

char* copyIf(const char *beginSource, const char *endSource, char *beginDestination, int(*f)(int)){
    const char *begin = beginSource;
    while(begin != endSource) {
        if (f(*begin)) {
            *beginDestination = *begin;
            beginDestination++;
        }
        begin++;
    }
    return beginDestination;
}

char *copyIfReverse(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)){
    const char *begin = rbeginSource;
    while(begin != rendSource) {
        if (f(*begin)) {
            *beginDestination = *begin;
            beginDestination++;
        }
        begin--;
    }
    return beginDestination;
}

