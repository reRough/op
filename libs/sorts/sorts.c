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

void insertionSort(int *a, const size_t size) {
    for (int i = 0; i < size; ++i)
        for (int j = i; j > 0; --j)
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
}

void hairbrushSort(int *a, const size_t size) {
    size_t step = size;
    int swapp = 1;
    while (step > 1 || swapp) {
        if (step > 1)
            step /= REDUCTION_FACTOR;
        swapp = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapp = 1;
            }
    }
}

void shellSort(int *array, int size) {
    for (int s = size / 2; s > 0; s /= 2)
        for (int i = s; i < size; ++i)
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s)
                swap(&array[j], &array[j + s]);
}

void getPrefixSums(int *a, size_t size) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < size; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

void digitalSort(int *a, size_t size) {
    int *buffer = (int *) calloc(size, sizeof(int));
    int max = 0b11111111;
    int step = 8;

    for (int byte = 0; byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            values[curByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            buffer[values[curByte]++] = a[i];
        }
        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);
}

void timeExperiment() {
    SortFunc sorts[] = {
            {bubbleSort, "bubbleSort"},
            {selectionSrt, "selectionSort"},
            {insertionSort, "insertionSort"},
            {hairbrushSort, "hairbrushSort"},
            {shellSort, "shellSort"},
            {digitalSort, "digitalSort"},
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

long long getBubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size; i++)
        for (size_t j = i; ++nComps && i < size; j++)
            if (++nComps && a[i] > a[j])
                swap(&a[i], &a[j]);

    return nComps;
}

long long getSelectionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

long long getInsertionSortNComp(int *a, const size_t size) {
    long long nComp = 0;
    for (int i = 0; ++nComp && i < size; ++i)
        for (int j = i;++nComp && j > 0; --j)
            if (++nComp && a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);

    return nComp;
}

long long getHairbrushNComp(int *a, size_t size) {
    long long nComp = 0;
    size_t step = size;
    int swapped = 1;
    while (step > 1 && ++nComp || swapped) {
        if (step > 1 && ++nComp)
            step /= REDUCTION_FACTOR;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size && ++nComp; ++i, ++j)
            if (a[i] > a[j] && ++nComp) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComp;
}

long long getShellSortNComp(int *array, int size) {
    long long nComp = 0;
    for (int s = size / 2;++nComp && s > 0; s /= 2)
        for (int i = s;++nComp && i < size; ++i)
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s){
                nComp += 2;
                swap(&array[j], &array[j + s]);
            }
    return nComp;
}

long long getDigitalSortNComp(int *a, size_t size) {
    long long nComp = 0;
    int *buffer = (int *) calloc(size, sizeof(int));
    int max = 0b11111111;
    int step = 8;

    for (int byte = 0; byte < sizeof(int) && ++nComp; byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < size && ++nComp; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            values[curByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size && ++nComp; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            buffer[values[curByte]++] = a[i];
        }
        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);

    return nComp;
}

void checkNComps(long long (*sortFunc )(int *, size_t),
                 void (*generateFunc )(int *, size_t),
                 size_t size, char *experimentName) {
    static size_t runCounter = 1;

    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name : %s\n", experimentName);

    size_t nComps = sortFunc(innerBuffer, size);

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! nComps : %lld\n", nComps);

        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);

        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);
        exit(1);
    }
}

void compsExperiment() {
    SortFunc sorts[] = {
            {getBubbleSortNComp,    "bubbleSort"},
            {getSelectionSortNComp, "selectionSort"},
            {getInsertionSortNComp, "insertionSort"},
            {getHairbrushNComp,      "hairbrushSort"},
            {getShellSortNComp,     "shellSort"},
            {getDigitalSortNComp,     "digitalSort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwardsArray, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf("------------------------------\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                static char filename[128];
                sprintf(filename, "%s_%s_comps",
                        sorts[i].name, generatingFuncs[j].name);
                checkNComps(sorts[i].sort,
                            generatingFuncs[j].generate,
                            size, filename);
            }
        }
        printf("\n");
    }
}

