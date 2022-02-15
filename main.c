#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/Tests/VectorTests.h"

int main() {
    vector v = createVector(SIZE_MAX) ;

    test_vector();

    return 0;
}
