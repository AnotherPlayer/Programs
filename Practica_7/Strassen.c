#include <stdio.h>
#include <stdlib.h>

//#define ROW_1 4
//#define COL_1 4
//#define ROW_2 4
//#define COL_2 4

void print(const char* display, int matrix[][COL_1], int start_row, int start_column, int end_row, int end_column) {
    printf("\n%s =>\n", display);
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void add_matrix(int matrix_A[][COL_1], int matrix_B[][COL_1], int matrix_C[][COL_1], int split_index) {
    for (int i = 0; i < split_index; i++) {
        for (int j = 0; j < split_index; j++) {
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}

void multiply_matrix(int matrix_A[ROW_1][COL_1], int matrix_B[ROW_2][COL_2], int result_matrix[ROW_2][COL_2]) {
    int col_1 = COL_1;
    int row_1 = ROW_1;
    int col_2 = COL_2;
    int row_2 = ROW_2;

    if (col_1 != row_2) {
        printf("\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n");
        return;
    }

    if (col_1 == 1) {
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    } else {
        int split_index = col_1 / 2;
        int result_matrix_00[split_index][split_index], result_matrix_01[split_index][split_index], result_matrix_10[split_index][split_index], result_matrix_11[split_index][split_index];
        int a00[split_index][split_index], a01[split_index][split_index], a10[split_index][split_index], a11[split_index][split_index];
        int b00[split_index][split_index], b01[split_index][split_index], b10[split_index][split_index], b11[split_index][split_index];

        for (int i = 0; i < split_index; i++) {
            for (int j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }
        }

        add_matrix(multiply_matrix(a00, b00), multiply_matrix(a01, b10), result_matrix_00, split_index);
        add_matrix(multiply_matrix(a00, b01), multiply_matrix(a01, b11), result_matrix_01, split_index);
        add_matrix(multiply_matrix(a10, b00), multiply_matrix(a11, b10), result_matrix_10, split_index);
        add_matrix(multiply_matrix(a10, b01), multiply_matrix(a11, b11), result_matrix_11, split_index);

        for (int i = 0; i < split_index; i++) {
            for (int j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
        }
    }
}

/*int main() {
    int matrix_A[ROW_1][COL_1] = { { 1, 1, 1, 1 },
                                   { 2, 2, 2, 2 },
                                   { 3, 3, 3, 3 },
                                   { 2, 2, 2, 2 } };

    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);

    int matrix_B[ROW_2][COL_2] = { { 1, 1, 1, 1 },
                                   { 2, 2, 2, 2 },
                                   { 3, 3, 3, 3 },
                                   { 2, 2, 2, 2 } };

    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    int result_matrix[ROW_1][COL_2];

    multiply_matrix(matrix_A, matrix_B, result_matrix);

    print("Result Array", result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);

    return 0;
}*/
