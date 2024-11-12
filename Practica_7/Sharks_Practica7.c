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
            multiply(str, cant);  // Asegurarse de que la función 'multiply' recibe enteros, no chars
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
            int A[cant][cant];
            int B[cant][cant];
            int C[cant][cant];

            multiply_matrix(A, B, C);  // Llama a la función 'multiply_matrix' con las matrices A, B y C
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
