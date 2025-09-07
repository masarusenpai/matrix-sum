#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define __PRINT_ALIGN 3
#define __MATRIX_MAX 100

// Struct for handling summation of a single matrix row.
typedef struct {
    int **matrix;
    int row, dim;
    int partial_sum;
} thread_data_t;

// Returns matrix (as a dynamic double pointer array) containing random integers.
int **get_matrix(int dim);

// Simply computes the sum of all matrix entries in a single thread (for testing).
int single_thread_sum(int **matrix, int dim);

// Concurrently set the sum of a row in a thread_data_t struct.
void *set_row_sum(void *arg);

// Print matrix with formatting.
void print_matrix(int **matrix, int dim);

// Free all dynamically-allocated memory required for matrix.
void destroy_matrix(int **matrix, int dim);
