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

void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(*m, getMax);
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m3.nRows; i++)
        for (int j = 0; j < m3.nCols; j++) {
            m3.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSquareMatrix(m) && isSymmetricMatrix(m)) {
        matrix matrixSquare = mulMatrices(*m, *m);
        freeMemMatrix(m);
        *m = matrixSquare;
    }
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long b[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        b[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(b, m.nRows)) {
        transposeSquareMatrix(&m);
    }
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    matrix m = mulMatrices(m1, m2);

    return isEMatrix(&m);
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;

    for (int i = 1; i < m.nRows; ++i) {
        int j = 0;
        int k = i;
        int max = m.values[k][j];
        while (k < m.nRows && j < m.nCols)
            max = max2(max, m.values[k++][j++]);
        sum += max;
    }
    for (int j = 1; j < m.nCols; ++j) {
        int i = 0;
        int k = j;
        int max = m.values[i][k];
        while (i < m.nRows && k < m.nCols)
            max = max2(max, m.values[i++][k++]);
        sum += max;
    }

    return sum;
}

int getMinInArea(matrix m) {
    position pos = getMaxValuePos(m);
    int leftBoarder = pos.colIndex;
    int rightBoarder = leftBoarder;
    int min = m.values[pos.rowIndex][leftBoarder];

    while (pos.rowIndex >= 0) {
        for (int k = leftBoarder; k <= rightBoarder; ++k)
            min = min2(min, m.values[pos.rowIndex][k]);
        if (leftBoarder > 0)
            leftBoarder--;
        if (rightBoarder + 1 < m.nCols)
            rightBoarder++;
        pos.rowIndex--;
    }

    return min;
}

void universalSwap(void *a, void *b, size_t size) {
    char *a1 = a;
    char *b1 = b;
    for (int i = 0; i < size; i++) {
        char t = *a1;
        *a1 = *b1;
        *b1 = t;

        a1++;
        b1++;
    }
}

float getDistance(int *a, int size) {
    double distanceSquared = 0;
    for (int i = 0; i < size; ++i)
        distanceSquared += a[i] * a[i];

    return sqrt(distanceSquared);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *rows = (float *) malloc(sizeof(float) * m.nRows);
    for (int rIndex = 0; rIndex < m.nRows; ++rIndex)
        rows[rIndex] = criteria(m.values[rIndex], m.nCols);

    for (int rIndex = 1; rIndex < m.nRows; ++rIndex) {
        int cIndex = rIndex;
        while (cIndex > 0 && rows[cIndex] < rows[cIndex - 1]) {
            swapRows(m, cIndex, cIndex - 1);
            universalSwap(&rows[cIndex], &rows[cIndex - 1], sizeof(int));
            cIndex--;
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

