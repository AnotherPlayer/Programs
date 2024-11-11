#include<stdio.h>
#include<stdlib.h>

#include"Karatsuba.h"
#include"PuntoCercano.h"
#include"Strassen.h"

int main() {
    
    int option, cant;

    printf("Selecciona un algoritmo:\n");
    printf("1. Karatsuba\n");
    printf("2. Puntos mas cercanos\n");
    printf("3. Strassen\n");
    printf("--> ");
    scanf("%d",&option);

    printf("Selecciones una cantidad\n--> ");
    scanf("%d",&cant);

    switch (option) {
        case 1:
            multiply("64","64");
            break;
        case 2:

            int A[cant][cant];
            int B[cant][cant];
            int C[cant][cant];

            multiply_matrix(A,B,C);

            break;
        case 3:
            
            

            break;
        default:
            printf("Opción no válida. Ingresa un número entre 1 y 3.\n");
            break;
    }

    return 0;
}