#include <stdint.h>
#include <stdlib.h>
#include "matrix_operations.h"

/* Returns 0 on success, -1 on invalid size or allocation failure (*dest = NULL). */
int CopyMatrix(double *src, double **dest, int size) {
    *dest = NULL;
    if (size <= 0 || size > MATRIX_MAX_SIZE ||
        (size_t)size * (size_t)size > SIZE_MAX / sizeof(double)) {
        return -1;
    }
    size_t n = (size_t)size * (size_t)size;
    *dest = malloc(n * sizeof(double));
    if (*dest == NULL) {
        return -1;
    }
    for (size_t i = 0; i < n; i++) {
        (*dest)[i] = src[i];
    }
    return 0;
}
