//
// Created by Admin on 30.03.2022.
//

#include "tasks.h"

int max2(int x, int y) {
    return x > y ? x : y;
}

int min2(int x, int y) {
    return x < y ? x : y;
}

int getMax(int *a, int size) {
    int max = a[0];
    for (int i = 1; i < size; ++i)
        max = max2(max, a[i]);

    return max;
}

void swapMinAndMaxRows(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

int getMin(int *a, int size) {
    int min = a[0];
    for (int i = 1; i < size; ++i)
        min = min2(min, a[i]);

    return min;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

