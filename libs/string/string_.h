//
// Created by Admin on 02.04.2022.
//

#ifndef LABS_LIBS_STRING__H
#define LABS_LIBS_STRING__H

#include <stdlib.h>

//возвращает количество символов в строке (не считая ноль-символ)
size_t strlen(const char *begin);

//возвращает указатель на первый элемент с кодом ch,
// расположенным на ленте памяти между адресами begin и end не включая end
char *find(char *begin, char *end, int ch);



#endif //LABS_LIBS_STRING__H
