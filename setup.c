#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void setup(double **A, double **B, double **C, int seed, int size) {
    *A = (double *)malloc(size * size * sizeof(double));
    *B = (double *)malloc(size * size * sizeof(double));
    *C = (double *)malloc(size * size * sizeof(double));

    srand(seed);
    for (int i = 0; i < size * size; i++) {
        (*A)[i] = (double)rand() / RAND_MAX;
        (*B)[i] = (double)rand() / RAND_MAX;
        (*C)[i] = 0.0;
    }
}