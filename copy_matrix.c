#include <stdlib.h>
#include "matrix_operations.h"

void CopyMatrix(double *src, double **dest, int size) {
    *dest = (double *)malloc(size * size * sizeof(double));
    for (int i = 0; i < size * size; i++) {
        (*dest)[i] = src[i];
    }
}