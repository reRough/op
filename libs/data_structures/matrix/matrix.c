//
// Created by Admin on 06.03.2022.
//

#include "matrix.h"

void swapArray(int *m, int a, int b) {
    int t = m[a];
    m[a] = m[b];
    m[b] = t;
}

void createArray(int *a, matrix m, int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        a[i] = m.values[i][cols];
    }
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix *m){
    for(int i = 0; i < m->nRows; i++)
        for(int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m){
    for(int i = 0; i < m.nRows; i++){
        for(int j = 0; j < m.nCols; j++)
            printf("%d", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices){
    for( int i = 0; i < nMatrices; i++){
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2){
    assert(m.nCols > i1);
    assert(m.nCols > i2);

    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] =  t;
}

void swapColumns(matrix m, int j1, int j2){
    assert(m.nCols > j1);
    assert(m.nCols > j2);

    for(int i = 0; i < m.nRows; i++){
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        a[i] = criteria(m.values[i], m.nCols);
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                for (int k = i; k > j; k--) {
                    swapArray(a, k - 1, k);
                    swapRows(m, k - 1, k);
                }
            }
        }
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int a[m.nCols];
    int b[m.nRows];
    for (int i = 0; i < m.nCols; i++) {
        createArray(b, m, m.nRows, i);
        a[i] = criteria(b, m.nRows);
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                for (int k = i; k > j; k--) {
                    swapArray(a, k - 1, k);
                    swapColumns(m, k - 1, k);
                }
            }
        }
    }
}

bool isSquareMatrix(matrix *m) {
    if (m->nRows == m->nCols)
        return true;
    return false;
}

bool sameSizeMatrices(matrix *m1, matrix *m2) {
    if (m1->nRows == m2->nRows && m1->nCols == m2->nCols)
        return true;
    return false;
}

bool isEMatrix(matrix *m){
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m->nRows; ++i)
        for (int j = 0; j < m->nCols; ++j)
            if (i == j && m->values[i][j] != 1 || i != j && m->values[i][j] != 0)
                return false;
    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m->nRows; ++i)
        for (int j = 0; j < m->nCols; ++j)
            if (m->values[i][j] != m->values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix *m) {
    assert(isSquareMatrix(m));

    for (int i = 0; i < m->nRows; ++i)
        for (int j = i; j < m->nCols; ++j)
            if (i != j){
                int t = m->values[i][j];
                m->values[i][j] = m->values[j][i];
                m->values[j][i] = t;
            }
}

void transposeMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i)
        for (int j = i; j < m->nCols; ++j)
            if (i != j){
                int t = m->values[i][j];
                m->values[i][j] = m->values[j][i];
                m->values[j][i] = t;
            }
}

position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols;  ++j) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                pos = (position) {i, j};
            }
        }

    return pos;
}

position getMaxValuePos(const matrix m) {
    int max = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                pos = (position) {i, j};
            }
        }

    return pos;
}

matrix createMatrixFromArray(const int *values, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            m.values[i][j] = values[k++];

    return m;
}

matrix *createArrayOfMatricesFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *m = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int i = 0; i < nMatrices; ++i)
        for (int j = 0; j < nRows; ++j)
            for (int k = 0; k < nCols; ++k)
                m[i].values[j][k] = values[l++];

    return m;
}