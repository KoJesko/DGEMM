#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void run_dgemm(int size, int seed) {
    double *A, *B, *C;
    setup(&A, &B, &C, seed, size);

    clock_t start = clock();
    DGEMM(A, B, C, size);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for DGEMM of size %dx%d: %f seconds\n", size, size, time_spent);

    PrintMatrix(C, size, 10);

    free(A);
    free(B);
    free(C);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int sizes[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        run_dgemm(sizes[i], seed);
    }

    int custom_size;
    printf("Enter a custom matrix size: ");
    if (scanf("%d", &custom_size) != 1) {
        fprintf(stderr, "Invalid input. Exiting.\n");
        return 1;
    }
    run_dgemm(custom_size, seed);

    return 0;
}