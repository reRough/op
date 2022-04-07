//
// Created by Admin on 06.04.2022.
//

#ifndef LABS_LIBS_SORTS_H
#define LABS_LIBS_SORTS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
    clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define REDUCTION_FACTOR 1.2473309

typedef struct SortFunc {
    void(*sort)(int *a, size_t n); // указатель на функцию
                                   // сортировки
    char name[64];                 // имя сортировки
                                   // используемое при выходе
} SortFunc;

typedef struct GeneratingFunc {
    void(*generate)(int *a, size_t n); // указатель на фукнцию
                                       // генерация последовательности
    char name[64];                     // имя генератора,
                                       // используемое при выводе
} GeneratingFunc;

void timeExperiment();

#endif //LABS_LIBS_SORTS_H
