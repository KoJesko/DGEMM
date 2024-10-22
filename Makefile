CC = gcc
CFLAGS = -Wall -O2

OBJS = main.o setup.o dgemm.o print_matrix.o copy_matrix.o dgemm_simd.o

all: dgemm_program

dgemm_program: $(OBJS)
    $(CC) $(CFLAGS) -o dgemm_program $(OBJS)

main.o: main.c matrix_operations.h
    $(CC) $(CFLAGS) -c main.c

setup.o: setup.c matrix_operations.h
    $(CC) $(CFLAGS) -c setup.c

dgemm.o: dgemm.c matrix_operations.h
    $(CC) $(CFLAGS) -c dgemm.c

print_matrix.o: print_matrix.c matrix_operations.h
    $(CC) $(CFLAGS) -c print_matrix.c

copy_matrix.o: copy_matrix.c matrix_operations.h
    $(CC) $(CFLAGS) -c copy_matrix.c

dgemm_simd.o: dgemm_simd.c matrix_operations.h
    $(CC) $(CFLAGS) -c dgemm_simd.c

clean:
    rm -f *.o dgemm_program