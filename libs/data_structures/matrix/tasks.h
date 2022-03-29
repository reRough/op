//
// Created by Admin on 30.03.2022.
//

#ifndef LABS_LIBS_TASKS_H
#define LABS_LIBS_TASKS_H

#include "matrix.h"

int getMax(const int *const a, const int size);

void swapMinAndMaxRows(matrix m)

void sortColsByMinElement(matrix m);

int getMin(int *a, int size);

void sortRowsByMaxElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

#endif //LABS_LIBS_TASKS_H
