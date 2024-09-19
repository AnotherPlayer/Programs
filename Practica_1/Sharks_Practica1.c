#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include "Fun_ord.h"

int num_length;

void getArray(int *num, FILE *file){
    int i;
    for(i=0 ; i<num_length ; i++){
        fscanf(file, "%d", &num[i]);
    };
}

void showArray(int *num){

    int i;

    for( i = 0; i < num_length; i++ )
        printf("%d. %d\n",i+1, num[i]);

}

int main(){

int opt, i=0;
double time = 0;

//Aceso al documento
    FILE *file = fopen("numeros.txt","r");
    
    if(file == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }

//Se declara un arreglo dinamico segun las nececidades del usuario
    puts("Ingrese la cantidad de numeros que desea ordenar del documento:");
    scanf("%d",&num_length);
    int *num = (int *)malloc(num_length * sizeof(int));

    if (num == NULL) {
        perror("Error al asignar memoria");
        fclose(file);
        return 1;
    }

//Funcion para obtener los numeros deseados
    getArray(num,file);

    printf("Seleccione un metodo de ordenamiento:\n1.- Burbuja [1]\n2.- Inserccion [2]\n3.- Heap Sort [3]\n--> ");
    scanf("%d",&opt);

    clock_t begin = clock();

    switch(opt){

        //Burbuja
        case 1:
            puts("En esta opcion se ordenara por metodo Burbuja\n");
            burbuja(num,num_length);
            
        break;

        //Inserccion
        case 2:
            puts("En esta opcion se ordenara por metodo Inserccion\n");
            inserccion(num,num_length);
            
        break;

        //QuickSort
        case 3:
            puts("En esta opcion se ordenara por metodo Heap_Sort\n");
            mergeSort(num,0,num_length-1);

        break;

        default:
            puts("La opcion que ingresaste no es valida\n");
        break;

    }

    sleep(1);
    clock_t end = clock();

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    /*
    if(num != NULL)
            showArray(num);
    else
        puts("\nArreglo vacio");
    */

    printf("Tiempo de ejecucion busqueda: %f s",time);

    free(num);

}