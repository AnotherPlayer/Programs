#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

// Asegúrate de que los archivos de encabezado estén disponibles
#include "Karatsuba.h"
#include "PuntoCercano.h"
#include "Strassen.h"

// Definición de la estructura Point, si es que no está definida en el archivo de encabezado
typedef struct {
    int x;
    int y;
} Point;

int main() {
    int option, cant;
    const int numero_maximo = 1000;  // Define el límite para los valores aleatorios

    printf("Selecciona un algoritmo:\n");
    printf("1. Karatsuba\n");
    printf("2. Puntos mas cercanos\n");
    printf("3. Strassen\n");
    printf("--> ");
    scanf("%d", &option);

    printf("Selecciona una cantidad\n--> ");
    scanf("%d", &cant);

    // Inicia el conteo de tiempo
    clock_t start = clock();

    switch (option) {
        case 1:
            // Karatsuba

            char str[12];
            itoa(cant, str, 10);

            printf("Resultado Karatsuba: %ld\n", multiply(strdup(str), strdup(str)));
            break;

        case 2: {
            // Punto más cercano
            Point P[cant];  // Crea un arreglo de 'Point' de tamaño 'cant'

            // Llenado del arreglo con puntos aleatorios
            for (int i = 0; i < cant; i++) {
                P[i].x = rand() % numero_maximo;
                P[i].y = rand() % numero_maximo;
            }

            closest(P, cant);  // Llama a la función 'closest' con el arreglo y su tamaño
            break;
        }

        case 3: {
            // Strassen
            int **matrix_A = create_matrix(cant, cant);
            int **matrix_B = create_matrix(cant, cant);

            int init_A[cant][cant];
            int init_B[cant][cant];

            for (int i = 0; i < ROW_1; i++) {
                for (int j = 0; j < COL_1; j++) {
                    matrix_A[i][j] = init_A[i][j];
                    matrix_B[i][j] = init_B[i][j];
                }
            }

            int **result_matrix = multiply_matrix(matrix_A, matrix_B, cant);
            print("Result Matrix", result_matrix, 0, 0, cant - 1, cant - 1);

            break;
        }

        default:
            printf("Opción no válida. Ingresa un número entre 1 y 3.\n");
            break;
    }

    // Finaliza el conteo de tiempo
    clock_t end = clock();
    printf("\nTiempo de ejecución: %.8f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
