//
// Created by Admin on 15.02.2022.
//

#include "VectorTests.h"
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 2);

    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    int *data = (int *) malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; ++i)
        data[i] = i;

    vector v = (vector) {data, 3, 3};
    pushBack(&v, 10);

    assert(v.size == 5);
    assert(v.capacity == 7);

    deleteVector(&v);
}

void test_popBack_notEmptyVector(){
    vector v = createVector(0);
    pushBack(v.size == 1);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_vector() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}
