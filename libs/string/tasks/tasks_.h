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


#endif //LABS_LIBS_TASKS__H
