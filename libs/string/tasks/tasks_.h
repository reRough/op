//
// Created by Admin on 02.04.2022.
//

#ifndef LABS_LIBS_TASKS__H
#define LABS_LIBS_TASKS__H

#include "../string_.h"

char *getEndOfString(char *s);

//удаляет из строки все пробельные символы
void removeNonLetter(char *s);

//Преобразовывает строку, оставляя только один символ в каждой последовательности
//подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

//Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);
#endif //LABS_LIBS_TASKS__H
