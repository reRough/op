//
// Created by Admin on 15.02.2022.
//

#include "VectorTests.h"
#include <assert.h>
#include "../vector.h"

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
    popBack(v.size == 1);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]) {1, 2, 3, 4}, 4, 4};

    assert(*atVector(&v, 2) == 3);
}

void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]) {1, 2, 3, 4}, 4, 4};

    assert(*atVector(&v, 3) == 4);
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]) {44}, 1, 1};

    assert(*back(&v) == 44);
}

void test_front_oneElementInVector() {
    vector v = (vector) {(int[]) {44}, 1, 1};

    assert(*front(&v) == 44);
}

void test_vector() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}
