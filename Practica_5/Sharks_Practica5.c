#include<stdio.h>
#include<stdlib.h>
#include <time.h>

// Iterativo
void MaxMin(int *arr, int *Max, int *Min, int n){
    *Max = arr[0];
    *Min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *Max)
            *Max = arr[i];
        else if (arr[i] < *Min)
            *Min = arr[i];
    }
}

// Recursivo con División y Conquista
void MaxMinDV(int A[], int i, int j, int *Max, int *Min) {
    int Max1, Min1, Max2, Min2, mit;
    
    if (i < j - 1) {  // Si hay más de dos elementos
        // Dividir el problema en 2 subproblemas
        mit = (i + j) / 2;
        MaxMinDV(A, i, mit, &Max1, &Min1);
        MaxMinDV(A, mit + 1, j, &Max2, &Min2);
        
        // Combinar los resultados
        *Max = (Max1 > Max2) ? Max1 : Max2;
        *Min = (Min1 < Min2) ? Min1 : Min2;
    }
    else if (i == j - 1) {  // Caso base: dos elementos
        if (A[i] > A[j]) {
            *Max = A[i];
            *Min = A[j];
        } else {
            *Max = A[j];
            *Min = A[i];
        }
    }
    else {  // Caso base: un solo elemento
        *Max = A[i];
        *Min = A[i];
    }
}


int num_length;

void getArray(int *num, FILE *file){
    int i;
    for(i=0 ; i<num_length ; i++){
        fscanf(file, "%d", &num[i]);
    };
}


int main(){

    int choose;
    //Aceso al documento
    FILE *file = fopen("C:/Users/brand/OneDrive/Documentos/Semestre_3/ADA/Practica_5/numeros10millones.txt","r");
    
    if(file == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }

    //Se declara un arreglo dinamico segun las nececidades del usuario
    puts("Ingrese el tamano del problema(Tamano del arreglo):");
    scanf("%d",&num_length);
    int *A = (int *)malloc(num_length * sizeof(int));

    if (A == NULL) {
        perror("Error al asignar memoria");
        fclose(file);
    }

    //Funcion para obtener los numeros deseados
    getArray(A,file);
    fclose(file);
    int Max, Min;
    puts("Este programa obtiene el maximo y el minimo de un conjunto de datos, que metodo desea realizarlo?\n1.Iterativo [1]\n2.Recursivo [2]\n");
    scanf("%d",&choose);


    clock_t start = clock();
    sleep(1);
    switch (choose){

    case 1:
        printf("itera_\n");
        MaxMin(A,&Max,&Min,num_length);

        break;
    
    case 2:
        printf("recur\n");
        MaxMinDV(A, 0, num_length - 1, &Max, &Min);

    default:
        break;
    }
    clock_t end = clock();  // Finaliza el conteo de tiempo
    printf("El valor maximo es: %d\n", Max);
    printf("El valor minimo es: %d\n", Min);
    printf("Tiempo de ejecucion: %.8f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

