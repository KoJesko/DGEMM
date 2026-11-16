#include "matrix_operations.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* Returns 0 on success, -1 on invalid size or allocation failure.
   On failure *A, *B and *C are left NULL. */
int setup(double **A, double **B, double **C, int seed, int size) {
  *A = *B = *C = NULL;
  if (size <= 0 || size > MATRIX_MAX_SIZE ||
      (size_t)size * (size_t)size > SIZE_MAX / sizeof(double)) {
    return -1;
  }
  size_t n = (size_t)size * (size_t)size;

  *A = malloc(n * sizeof(double));
  *B = malloc(n * sizeof(double));
  *C = malloc(n * sizeof(double));
  if (*A == NULL || *B == NULL || *C == NULL) {
    free(*A);
    free(*B);
    free(*C);
    *A = *B = *C = NULL;
    return -1;
  }

  srand(seed);
  for (size_t i = 0; i < n; i++) {
    (*A)[i] = (double)rand() / RAND_MAX;
    (*B)[i] = (double)rand() / RAND_MAX;
    (*C)[i] = 0.0;
  }
  return 0;
}
