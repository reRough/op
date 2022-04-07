//
// Created by Admin on 06.04.2022.
//

#include "sorts.h"

void generateRandomArray(int *a, size_t n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = INT_MIN / 2 + rand();
}

void generateOrderedArray(int *a, size_t n) {
    for (int i = 0; i < n; i++)
        a[i] = i;
}

void generateOrderedBackwardsArray(int *a, size_t n) {
    int value = n - 1;
    for (int i = 0; i < n; i++)
        a[i] = value--;
}

bool isOrdered(int *a, size_t n) {
    for (size_t i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

void outputArray_(const int *a, const size_t n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    int* innerBuffer = malloc(sizeof(int) * 100000);
    generateFunc(innerBuffer, size);
    printf(" Run #%zu| ", runCounter++);
    printf(" Name: %s\n", experimentName);

    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time);

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f\n", time);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (NULL == f) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }

    free(innerBuffer);
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;

}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSrt(int *a, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}


void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort, "bubbleSort"},
            {selectionSrt, "selectionSort"},

    };

    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generating[] = {
            {generateRandomArray,           "random"},
            {generateOrderedArray,          "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"},
    };

    const unsigned CASES_N = ARRAY_SIZE(generating);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("----------------------------\n");
        printf("Size: %d\n", size);

        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generating[j].name);
                checkTime(sorts[i].sort,
                          generating[j].generate,
                          size, filename);

            }
        }

        printf("\n");
    }

}



