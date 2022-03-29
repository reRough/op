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

//ввод матрицы m
void inputMatrix(matrix *m);

//ввод массива из nMatrices матриц
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми гомерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрицы m
void swapColumns(matrix m, int j1, int j2);

#endif //LABS_LIBS_MATRIX_H
