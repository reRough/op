//
// Created by Admin on 30.03.2022.
//

#include "tasks.h"

int max2(const int x, const int y) {
    return x > y ? x : y;
}

int getMax(const int *const a, const int size) {
    int max = a[0];
    for (int i = 1; i < size; ++i)
        max = max2(max, a[i]);

    return max;
}

void swapRowsWithMaxMinElements(matrix m) {
    position posMin = getMinValuePos(m);
    position posMax = getMaxValuePos(m);

    swapRows(m, posMin.rowIndex, posMax.rowIndex);
}

