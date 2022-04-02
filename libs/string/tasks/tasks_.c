//
// Created by Admin on 02.04.2022.
//

#include "tasks_.h"

char *getEndOfString(char *s){
    while(*s)
        s++;

    return s;
}

void removeNonLetter(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void removeAdjacentEqualLetters(char *s) {
    if (!s)
        return;

    char *prev = s;
    while (*s) {
        if (*prev != *s)
            *(++prev) = *s;
        s++;
    }
    *(++prev) = '\0';
}

void removeExtraSpaces(char *s) {
    if (!s)
        return;

    char *writePos = s;
    s++;
    while (*s) {
        if (isspace(*s) && isspace(*writePos))
            *writePos = ' ';
        else
            *(++writePos) = *s;
        s++;
    }
    *(++writePos) = '\0';
}
