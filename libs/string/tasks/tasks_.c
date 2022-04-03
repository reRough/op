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

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart(WordDescriptor word){
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverce(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = *findNonSpaceReverse(rbegin, rend);
    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend);
    word->begin++;
    word->end++;
    return true;
}

int wordcmp(WordDescriptor w1, WordDescriptor w2) {
    char *start1 = w1.begin;
    char *start2 = w2.begin;
    unsigned long size = w1.end - start1;
    if (size != w2.end - start2)
        return 0;

    return memcmp(start1, start2, size) == 0;
}

void replaceWord(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    recPtr = source;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        char *endOfBuff = copy(source, getEndOfString(source), _stringBuffer);
        *endOfBuff = '\0';
        readPtr = _stringBuffer;
    }

    WordDescriptor currentWord;
    while (getWord(readPtr, &currentWord)) {
        if (wordcmp(word1, currentWord)) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else
            recPtr = copy(currentWord.begin, currentWord.end, recPtr);
        *recPtr++ = ' ';
        readPtr = currentWord.end;
    }

    if (recPtr != source)
        *--recPtr = '\0';
}

