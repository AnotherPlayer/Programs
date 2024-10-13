#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include"Busqueda.h"

int num_length;

void getArray(int *num, FILE *file){

    int i;
    for(i=0 ; i<num_length ; i++)
        fscanf(file, "%d", &num[i]);
}

int main(){

int caso, dato, cond, i=0;
double time = 0;


//Aceso al documento

    FILE *file;

    file = fopen("num.txt","r");
            if(file == NULL){
                perror("Error en la apertura del archivo");
                exit(0);
           }

//Usuario escoger numero
    printf("Seleccione un numero:\n");
    scanf("%d",&dato);

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

//Seleccionar metodo de busqueda
    puts("Seleccion un metodo de ordenamiento:\n1.- Busqueda secuencial [1]\n2.- Busqueda binaria [2]\n--> ");
    fflush(stdin);
    scanf("%d",&caso);

    clock_t begin = clock();

    switch(caso){

        case 1:

            cond = busquedaSecuencial(num,num_length,dato);

        break;

        case 2:

            cond = busquedaBinaria(num,dato,0,num_length-1);

        break;

        default:

            puts("La opcion que ingresaste no es valida\n");
            exit(0);

        break;

    }

    sleep(1);
    clock_t end = clock();

    if(cond < 0)
        printf("\nNo se encontro el numero: %d\n",cond);

    else
        printf("\nAqui ta: %d\n",cond+1);

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion busqueda: %f s\n-----------------------------------------",time);

    free(num);


}