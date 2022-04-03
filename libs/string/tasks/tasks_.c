//
// Created by Admin on 02.04.2022.
//

#include "tasks_.h"
#include <stdio.h>

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
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
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

int arrangeInOrder(char *s) {
    char *begin = s;
    char *beginW1 = _stringBuffer;
    char *beginW2;

    WordDescriptor w1;
    WordDescriptor w2;

    if (!getWord(begin, &w1))
        return 1;
    char *endWord1 = copy(w1.begin, w1.end, beginW1);
    *endWord1 = '\0';

    while (getWord(begin, &w2)) {
        beginW2 = endWord1 + 1;
        char *endWord2 = copy(w2.begin, w2.end, beginW2);
        *endWord2 = '\0';
        if (strcmp(beginW1, beginW2) > 0)
            return 0;
        w1.end = w2.end;
        w1.begin = w2.begin;
        endWord1 = copy(w2.begin, w2.end, beginW1);
        begin = w2.end;
    }

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2){
    char *begin2 = w2.begin;
    for(char *begin1 = w1.begin; *begin1 <= w1.end; *begin1++)
        if (*begin1 == *begin2)
            *begin2++;
        else
            return 0;

    return 1;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    WordDescriptor *bagStart = bag->words;
    char *strStart = s;

    bag->size = 0;
    while (getWord(strStart, &word)) {
        *bagStart++ = word;
        bag->size++;
        strStart = word.end;
    }
}

bool isPalindrome(WordDescriptor w) {
    char *left = w.begin;
    char *right = w.end - 1;
    while (right - left > 0) {
        if (*(left) != *(right))
            return false;
        right--;
        left++;
    }
    return true;
}

int getWord2(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);

    return 1;
}

int countPalindromes(char *s) {
    char *begin = s;
    WordDescriptor word;
    int number = 0;
    while (getWord2(begin, &word)) {
        if (isPalindrome(word))
            number++;
        begin = word.end + 1;
    }
    return number;
}

bool isEmptyString(char *s) {
    while (*s != '\0') {
        if (!isspace(*s))
            return false;
    }
    return true;
}

void mixStrings(char *s1, char *s2, char *s3) {
    if (isEmptyString(s1) && isEmptyString(s2))
        return;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *copyS3 = s3;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            copyS3 = copy(word1.begin, word1.end, copyS3);
            *copyS3++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            copyS3 = copy(word2.begin, word2.end, copyS3);
            *copyS3++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (s3 != copyS3)
        copyS3--;
    *copyS3 = '\0';
}

void reverseWordInString(char *s) {
    char *endOfBuff = copy(s, s + strlen(s), _stringBuffer);
    *endOfBuff = '\0';

    WordDescriptor word;
    char *start = s;

    while (getWordReverse(endOfBuff - 1, _stringBuffer - 1, &word)) {
        start = copy(word.begin, word.end, start);
        *start++ = ' ';
        endOfBuff = word.begin;
    }

    if (s != start)
        *--start = '\0';
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *word) {
    WordDescriptor previousWord;
    char *start = s;

    if (!getWord(start, &previousWord))
        return EMPTY_STRING;

    if (*find(previousWord.begin, previousWord.end, 'a') == 'a' ||
        *find(previousWord.begin, previousWord.end, 'A') == 'A')
        return FIRST_WORD_WITH_A;

    start = previousWord.end;
    WordDescriptor currentWord;
    while (getWord(start, &currentWord)) {
        if (*find(currentWord.begin, currentWord.end, 'a') == 'a' ||
            *find(currentWord.begin, currentWord.end, 'A') == 'A') {
            *word = previousWord;
            return WORD_FOUND;
        }
        start = currentWord.end;
        previousWord = currentWord;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    WordDescriptor word;
    WordBeforeFirstWordWithAReturnCode k = getWordBeforeFirstWordWithA(begin, &word);
    if (k == WORD_FOUND) {
        char *end = copy(word.begin, word.end, _stringBuffer);
        *end = '\0';
        printf("%s", _stringBuffer);
    }
}

