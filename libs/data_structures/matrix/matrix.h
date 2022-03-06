//
// Created by Admin on 06.03.2022.
//

#ifndef LABS_LIBS_MATRIX_H
#define LABS_LIBS_MATRIX_H

//обьявление структур
typedef struct matrix{
    int **values; //элементы матрицы
    int nRows; //количество рядов
    int nCols; //количество столбцов
} matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
} position;

//возвращает матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

//возвращает массив из nMatrices матриц размером nRows на nCols
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix *m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

#endif //LABS_LIBS_MATRIX_H
