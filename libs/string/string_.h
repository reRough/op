//
// Created by Admin on 02.04.2022.
//

#ifndef LABS_LIBS_STRING__H
#define LABS_LIBS_STRING__H

#include <stdlib.h>
#include <ctype.h>

//возвращает количество символов в строке (не считая ноль-символ)
size_t strlen(const char *begin);

//возвращает указатель на первый элемент с кодом ch,
//расположенным на ленте памяти между адресами begin и end не включая end
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных
char* findNonSpaceReserve(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа
char* findSpaceReverse(char *rbegin, const char *rend);

//Функция возвращает отрицательное значение, если lhs располагается до rhs
//в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
//равны, иначе – положительное значение.
int strmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента памяти
//начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f
char* copyIf(const char *beginSource, const char *endSource, char *beginDestination, int(*f)(int));

//записывает по адресу beginDestination элементы из фрагмента памяти
//начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f
char *copyIfReverce(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));


#endif //LABS_LIBS_STRING__H
