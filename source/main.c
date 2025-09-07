#include "../libs/matrix.h"

#define __ARG_MIN 2

int main(int argc, char **argv) {
    unsigned int dim;
    if (argc < __ARG_MIN || sscanf(argv[1], "%d", &dim) != 1) {
        puts("Usage: ./main <dimension>");
        return 1;
    }

    srand(time(NULL));
    int **my_matrix = get_matrix(dim);

    puts("Matrix:");
    print_matrix(my_matrix, dim);
    puts("");

    pthread_t *threads = (pthread_t*)malloc(dim * sizeof(pthread_t));
    thread_data_t *data = (thread_data_t*)malloc(dim * sizeof(thread_data_t));

    int i;
    for (i = 0; i < dim; i++) {
        data[i].matrix = my_matrix;
        data[i].row = i;
        data[i].dim = dim;
        data[i].partial_sum = 0;
        pthread_create(&threads[i], NULL, set_row_sum, &data[i]);
    }

    int total_sum = 0;
    for (i = 0; i < dim; i++) {
        pthread_join(threads[i], NULL);
        total_sum += data[i].partial_sum;
    }

    free(threads);
    free(data);

    printf("Observed sum: %d\n", total_sum);
    puts("⌛ Verifying...");
    assert(total_sum == single_thread_sum(my_matrix, dim));
    puts("🎉 \033[1;32mSuccess!\033[0m Your program calculated the correct sum!");

    destroy_matrix(my_matrix, dim);

    return 0;
}
