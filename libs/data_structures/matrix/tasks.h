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

//Заменяет 𝐴 ее квадратом если данная квадратная матрица 𝐴 симметрична
void getSquareOfMatrixIfSymmetric(matrix *m);

long long getSum(int *a, int n);

bool isUnique(long long *a, int n);

//Транспонирует матрицу если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//Возвращает 1 если матрицы взаимно обратны,
//0 - если не взаимо обратны
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

#endif //LABS_LIBS_TASKS_H
