#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ROW_1 64
#define COL_1 64
#define ROW_2 64
#define COL_2 64

// Function to print a matrix
void print(const char *display, int **matrix, int start_row, int start_column, int end_row, int end_column) {
    printf("\n%s =>\n", display);
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Helper function to create a new 2D array dynamically
int** create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Helper function to free a dynamically allocated 2D array
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
int** add_matrix(int **matrix_A, int **matrix_B, int split_index, int multiplier) {
    int **result = create_matrix(split_index, split_index);
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            result[i][j] = matrix_A[i][j] + multiplier * matrix_B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices using divide and conquer (Strassen's Algorithm)
int** multiply_matrix(int **matrix_A, int **matrix_B, int size) {
    if (size == 1) {
        int **result = create_matrix(1, 1);
        result[0][0] = matrix_A[0][0] * matrix_B[0][0];
        return result;
    }

    int split_index = size / 2;

    int **a00 = create_matrix(split_index, split_index);
    int **a01 = create_matrix(split_index, split_index);
    int **a10 = create_matrix(split_index, split_index);
    int **a11 = create_matrix(split_index, split_index);
    int **b00 = create_matrix(split_index, split_index);
    int **b01 = create_matrix(split_index, split_index);
    int **b10 = create_matrix(split_index, split_index);
    int **b11 = create_matrix(split_index, split_index);

    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            a00[i][j] = matrix_A[i][j];
            a01[i][j] = matrix_A[i][j + split_index];
            a10[i][j] = matrix_A[i + split_index][j];
            a11[i][j] = matrix_A[i + split_index][j + split_index];

            b00[i][j] = matrix_B[i][j];
            b01[i][j] = matrix_B[i][j + split_index];
            b10[i][j] = matrix_B[i + split_index][j];
            b11[i][j] = matrix_B[i + split_index][j + split_index];
        }
    }

    int **p = multiply_matrix(a00, add_matrix(b01, b11, split_index, -1), split_index);
    int **q = multiply_matrix(add_matrix(a00, a01, split_index, 1), b11, split_index);
    int **r = multiply_matrix(add_matrix(a10, a11, split_index, 1), b00, split_index);
    int **s = multiply_matrix(a11, add_matrix(b10, b00, split_index, -1), split_index);
    int **t = multiply_matrix(add_matrix(a00, a11, split_index, 1), add_matrix(b00, b11, split_index, 1), split_index);
    int **u = multiply_matrix(add_matrix(a01, a11, split_index, -1), add_matrix(b10, b11, split_index, 1), split_index);
    int **v = multiply_matrix(add_matrix(a00, a10, split_index, -1), add_matrix(b00, b01, split_index, 1), split_index);

    int **result = create_matrix(size, size);
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            result[i][j] = t[i][j] + s[i][j] - q[i][j] + p[i][j];
            result[i][j + split_index] = p[i][j] + q[i][j];
            result[i + split_index][j] = r[i][j] + s[i][j];
            result[i + split_index][j + split_index] = t[i][j] + p[i][j] - r[i][j] - v[i][j];
        }
    }

    free_matrix(a00, split_index);
    free_matrix(a01, split_index);
    free_matrix(a10, split_index);
    free_matrix(a11, split_index);
    free_matrix(b00, split_index);
    free_matrix(b01, split_index);
    free_matrix(b10, split_index);
    free_matrix(b11, split_index);

    free_matrix(p, split_index);
    free_matrix(q, split_index);
    free_matrix(r, split_index);
    free_matrix(s, split_index);
    free_matrix(t, split_index);
    free_matrix(u, split_index);
    free_matrix(v, split_index);

    return result;
}

int main() {
    int **matrix_A = create_matrix(ROW_1, COL_1);
    int **matrix_B = create_matrix(ROW_2, COL_2);

    int init_A[ROW_1][COL_1];
    int init_B[ROW_2][COL_2];

    for (int i = 0; i < ROW_1; i++) {
        for (int j = 0; j < COL_1; j++) {
            matrix_A[i][j] = init_A[i][j];
            matrix_B[i][j] = init_B[i][j];
        }
    }

    print("Matrix A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
    print("Matrix B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    clock_t start = clock();

    int **result_matrix = multiply_matrix(matrix_A, matrix_B, ROW_1);
    print("Result Matrix", result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);

    sleep(1);
    clock_t end = clock();
    printf("\nTiempo de ejecucion: %.8f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free_matrix(matrix_A, ROW_1);
    free_matrix(matrix_B, ROW_2);
    free_matrix(result_matrix, ROW_1);

    return 0;
}
