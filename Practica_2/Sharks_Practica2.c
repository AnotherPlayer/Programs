#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include "Fun_ord.h"

int num_length;

void getArray(int *num, FILE *file){

    int i;
    for(i=0 ; i<num_length ; i++)
        fscanf(file, "%d", &num[i]);

}

void showArray(int *num){

    int i;
    for( i = 0; i < num_length; i++ )
        printf("%d. %d\n",i+1, num[i]);

}

void chooseOrd(int *num, int opt){

    switch(opt){

        //Quick Sort
        case 1:
            puts("En esta opcion se ordenara por Quick Sort\n");
            quickSort(num,0, (sizeof(num) / sizeof(num[0]))-1);
            
        break;

        //Merge Sort
        case 2:
            puts("En esta opcion se ordenara por Merge Sort\n");
            mergeSort(num,0,num_length-1);
            
        break;

        default:
            puts("La opcion que ingresaste no es valida\n");
        break;

    }    

}

int main(){

int caso, opt, i=0;
double time = 0;

//Aceso al documento

    FILE *file;

    puts("Seleccion un caso:\n1.- Mejor caso\n2.- Caso medio\n3.- Peor caso\n--> ");
    fflush(stdin);
    scanf("%d",&caso);

    switch(caso){

        case 1:

            file = fopen("mejor.txt","r");
            if(file == NULL){
                perror("Error en la apertura del archivo");
                exit(0);
           }

        break;

        case 2:

            file = fopen("media.txt","r");
            if(file == NULL){
                perror("Error en la apertura del archivo");
                exit(1);
            }

        break;

        case 3:

            file = fopen("peor.txt","r");
            if(file == NULL){
                perror("Error en la apertura del archivo");
                exit(2);
            }
        
        break;

        default:

            puts("La opcion que ingresaste no es valida\n");
            exit(0);

        break;

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

    printf("Seleccione un metodo de ordenamiento:\n1.- Quick Sort [1]\n2.- Merge Sort [2]\n\n--> ");
    scanf("%d",&opt);

    clock_t begin = clock();

//Escoger un método de ordenamiento
    chooseOrd(num,opt);

    sleep(1);

    clock_t end = clock();


    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion busqueda: %f s",time);

    free(num);

}