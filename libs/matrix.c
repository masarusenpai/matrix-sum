#include "matrix.h"

int **get_matrix(int dim) {
    int **matrix = (int**)malloc(dim *sizeof(int*));

    for (int i = 0; i < dim; i++) {
        matrix[i] = (int*)malloc(dim * sizeof(int));
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = rand() % __MATRIX_MAX;
        }
    }

    return matrix;
}

int single_thread_sum(int **matrix, int dim) {
    int sum = 0;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

void *set_row_sum(void *arg) {
    thread_data_t *data = (thread_data_t*)arg;

    for (int i = 0; i < data->dim; i++) {
        data->partial_sum += data->matrix[data->row][i];
    }

    return NULL;
}

void print_matrix(int **matrix, int dim) {
    int i, j;
    printf("+");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < __PRINT_ALIGN; j++) {
            printf("-");
        }
    }
    puts("-+");

    for (i = 0; i < dim; i++) {
        printf("|");
        for (j = 0; j < dim; j++) {
            printf("%*d", __PRINT_ALIGN, matrix[i][j]);

            if (j == dim - 1) {
                puts(" |");
            }
        }
    }

    printf("+");
    for (i = 0; i < dim; i++) {
        for (j = 0; j < __PRINT_ALIGN; j++) {
            printf("-");
        }
    }
    puts("-+");
}

void destroy_matrix(int **matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        free(matrix[i]);
    }

    free(matrix);
}
