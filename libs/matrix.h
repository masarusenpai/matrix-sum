#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define __PRINT_ALIGN 3
#define __MATRIX_MAX 100

typedef struct {
    int **matrix;
    int row, dim;
    int partial_sum;
} thread_data_t;

int **get_matrix(int dim);
int single_thread_sum(int **matrix, int dim);
void *set_row_sum(void *arg);
void print_matrix(int **matrix, int dim);
void destroy_matrix(int **matrix, int dim);
