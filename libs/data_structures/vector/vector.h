//
// Created by Admin on 15.02.2022.
//

#ifndef LABS_LIBS_VECTOR_H
#define LABS_LIBS_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

// обьявление структуры
typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// возвращает структуру вектор из n значений.
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, не освобождая выделенную память.
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору.
void deleteVector(vector *v);

// возвращает true, если вектор пустой, иначе возвращает false
bool isEmpty(const vector *v);

// возвращает true, если вектор заполнен, иначе возвращает false
bool isFull(const vector *v);

// возвращает i-ый элемент вектора v.
int getVectorValue(const vector *v, size_t i);

// добавляет элемент x в конец вектора v.
// увеличивает количество выделенной памяти вдвое, если вектор заполнен
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора.
void popBack(vector *v);

#endif //LABS_LIBS_VECTOR_H
