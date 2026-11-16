#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

/* Largest size for which size*size (used as an int index) cannot overflow. */
#define MATRIX_MAX_SIZE 46340

int setup(double **A, double **B, double **C, int seed, int size);
void DGEMM(double *A, double *B, double *C, int size);
void PrintMatrix(double *matrix, int size, int elements);
int CopyMatrix(double *src, double **dest, int size);
void DGEMM_SIMD(double *A, double *B, double *C, int size);

#endif // MATRIX_OPERATIONS_H