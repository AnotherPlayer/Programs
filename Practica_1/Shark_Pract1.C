#include<stdio.h>
#include<stdlib.h>

int num_length;

void obtener_val(int *num, FILE *file){
    int i;
    for(i=0 ; i<num_length ; i++){
        fscanf(file, "%d", &num[i]);
    };
}

void otd_Insercion(int *num){
    int i,j;
    int aux;
    for(j=1 ; j<num_length ; j++){
        aux = num[j];
        i = j-1;
            while(i>=0 && num[i]>aux){
                num[i+1] = num[i];
                i = i-1;
            }
        num[i+1] = aux;
    }
}


int main(){
    int opt , i=0;

    //Aceso al documento
    FILE *file = fopen("C:/Users/brand/OneDrive/Documentos/Semestre_3/ADA/Practica_1/numeros.txt","r");
    if(file == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }

    //Se declara un arreglo dinamico segun las nececidades del usuario
    puts("Ingrese la cantidad de numeros que desea ordenar del documento:\n");
    scanf("%d",&num_length);
    int *num = (int *)malloc(num_length * sizeof(int));
    if (num == NULL) {
        perror("Error al asignar memoria");
        fclose(file);
        return 1;
    }
    //Funcion para obtener los numeros deseados
    obtener_val(num,file);

    //Menu de opciones
    printf("Seleccione un metodo de ordenamiento:\n1.- Burbuja [1]\n2.- Inserccion [2]\n3.- Heap Short [3]\n");
    scanf("%d",&opt);

    switch(opt){
        case 1:
            puts("En esta opcion se ordenara por metodo Burbuja\n");
            /*for(;i> 3 ; i++)
                burbuja(*num, n[i]);*/
            
        break;

        case 2:
            puts("En esta opcion se ordenara por metodo Inserccion\n");
            otd_Insercion(num);
            printf("\n");
            for(i=0 ; i<num_length ; i++){
                printf("%d\t",num[i]);
            }
        break;

        case 3:
            puts("En esta opcion se ordenara por metodo Heap short\n");
            /*for(;i> 3 ; i++)
                burbuja(*num, n[i]);*/
            
        break;
        default:
            puts("La opcion que ingresaste no es valida\n");
        break;

    }

}