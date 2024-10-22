#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void setup(double **A, double **B, double **C, int seed, int size);
void DGEMM(double *A, double *B, double *C, int size);
void PrintMatrix(double *matrix, int size, int elements);
void CopyMatrix(double *src, double **dest, int size);
void DGEMM_SIMD(double *A, double *B, double *C, int size);

#endif // MATRIX_OPERATIONS_H