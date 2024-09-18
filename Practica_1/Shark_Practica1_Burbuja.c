#include<stdio.h>
#include<stdlib.h>

int num_length;

void obtener_val(int *num, FILE *file) {
    int i;
    for(i = 0; i < num_length; i++) {
        fscanf(file, "%d", &num[i]);
    };
}

void ord_Burbuja(int *num) {
    int i, cond = 0;
    int pass = 0;
    int aux;

    while(!cond) {
        cond = 1;
        for(i = 0; i < num_length-pass-1; i++) {
            if(num[i] > num[i+1]) {
                cond = 0;
                aux = num[i];
                num[i] = num[i+1];
                num[i+1] = aux;
            }
        }
        pass++;
    }
}

void otd_Insercion(int *num) {
    int i, j;
    int aux;
    for(j = 1; j < num_length; j++) {
        aux = num[j];
        i = j-1;
        while(i >= 0 && num[i] > aux) {
            num[i+1] = num[i];
            i = i-1;
        }
        num[i+1] = aux;
    }
}

int main() {
    int opt, i = 0;

    // Acceso al documento
    FILE *file = fopen("C:/Users/anton/OneDrive/Documentos/Escritorio/practica1/numeros10millones.txt", "r");
    if(file == NULL) {
        perror("Error en la apertura del archivo");
        return 1;
    }

    // Se declara un arreglo dinámico según las necesidades del usuario
    puts("Ingrese la cantidad de numeros que desea ordenar del documento:\n");
    scanf("%d", &num_length);
    int *num = (int *)malloc(num_length * sizeof(int));
    if(num == NULL) {
        perror("Error al asignar memoria");
        fclose(file);
        return 1;
    }

    // Función para obtener los números deseados
    obtener_val(num, file);
    fclose(file);  // Cierra el archivo

    // Menú de opciones
    printf("Seleccione un metodo de ordenamiento:\n1.- Burbuja [1]\n2.- Inserción [2]\n3.- Heap Sort [3]\n");
    scanf("%d", &opt);

    switch(opt) {
        case 1:
            puts("En esta opcion se ordenara por metodo Burbuja\n");
            ord_Burbuja(num);
            printf("\n");
            for(i = 0; i < num_length; i++) {
                printf("%d\t", num[i]);
            }
        break;

        case 2:
            puts("En esta opcion se ordenara por metodo Inserción\n");
            otd_Insercion(num);
            printf("\n");
            for(i = 0; i < num_length; i++) {
                printf("%d\t", num[i]);
            }
        break;

        case 3:
            puts("En esta opcion se ordenara por metodo Heap Sort\n");
            // Implementar el método Heap Sort aquí
        break;

        default:
            puts("La opcion que ingresaste no es valida\n");
        break;
    }

    free(num);  // Libera la memoria asignada
    return 0;
}
