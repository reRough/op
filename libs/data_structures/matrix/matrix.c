//
// Created by Admin on 06.03.2022.
//

#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

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
    int rows = m->nRows;
    for (int i = 0; i < rows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix *m){
    int rows = m->nRows;
    int cols = m->nCols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices){
    for(int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m){
    int rows = m.nRows;
    int cols = m.nCols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
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