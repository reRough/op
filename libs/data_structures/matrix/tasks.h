//
// Created by Admin on 30.03.2022.
//

#ifndef LABS_LIBS_TASKS_H
#define LABS_LIBS_TASKS_H

#include "matrix.h"

int getMax(const int *const a, const int size);

//Меняет местами строки,
//в которых находятся максимальный и минимальный элементы
void swapMinAndMaxRows(matrix m)

//Располагает строки матрицы по неубыванию наибольших элементов строк
void sortColsByMinElement(matrix m);

int getMin(int *a, int size);

//Располагает столбцы матрицы по неубыванию
//минимальных элементов столбцов
void sortRowsByMaxElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

//Если данная квадратная матрица 𝐴 симметрична,
//то заменить 𝐴 ее квадратом
void getSquareOfMatrixIfSymmetric(matrix *m);



#endif //LABS_LIBS_TASKS_H
