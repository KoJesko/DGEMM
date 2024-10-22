#include <stdio.h>
#include "matrix_operations.h"

void PrintMatrix(double *matrix, int size, int elements) {
    for (int i = 0; i < elements; i++) {
        printf("%f ", matrix[i]);
    }
    printf("\n");
}