//
// Created by Admin on 30.03.2022.
//

#ifndef LABS_LIBS_TASKS_H
#define LABS_LIBS_TASKS_H

#include "../matrix.h"
#include <math.h>


//Меняет местами строки,
//в которых находятся максимальный и минимальный элементы
void swapMinAndMaxRows(matrix m);

//Располагает строки матрицы по неубыванию наибольших элементов строк
void sortColsByMinElement(matrix m);

int getMin(int *a, int size);

//Располагает столбцы матрицы по неубыванию
//минимальных элементов столбцов
void sortRowsByMaxElement(matrix *m);

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

//Находит сумму максимальных элементов всех псевдодиагоналей данной матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//Находит минимальный элемент матрицы в выделенной области
int getMinInArea(matrix m);

float getDistance(int *a, int size);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

//Располаагет точки по неубыванию их расстояний до начала координат
void sortByDistances(matrix m);


#endif //LABS_LIBS_TASKS_H
