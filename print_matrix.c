#include "matrix_operations.h"
#include <stdio.h>

void PrintMatrix(double *matrix, int size, int elements) {
  /* Never read past the size*size elements that were allocated. */
  long long total = size > 0 ? (long long)size * size : 0;
  if (elements > total) {
    elements = (int)total;
  }

  for (int i = 0; i < elements; i++) {
    printf("%f ", matrix[i]);
  }
  printf("\n");
}
