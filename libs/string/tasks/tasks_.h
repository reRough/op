//
// Created by Admin on 02.04.2022.
//

#ifndef LABS_LIBS_TASKS__H
#define LABS_LIBS_TASKS__H

#include "../string_.h"

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // плзиуия первого символа, после последнего символа слова
} WordDescriptor;

char *getEndOfString(char *s);

//удаляет из строки все пробельные символы
void removeNonLetter(char *s);

//Преобразовывает строку, оставляя только один символ в каждой последовательности
//подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

//Возвращает значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1
int getWord ( char *beginSearch , WordDescriptor *word );

//Преобразовывает строку таким образом, чтобы цифры каждого слова были перенесены в начало слова
//и изменяет порядок следования цифр на обратный
void digitToStart(WordDescriptor word);

//Считывает слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int wordcmp(WordDescriptor w1, WordDescriptor w2);

//Заменяет все вхождения слова 𝑤1 на слово 𝑤2
void replaceWord(char *source, char *w1, char *w2);

#endif //LABS_LIBS_TASKS__H
