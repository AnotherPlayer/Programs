#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *flujo = fopen("datos.txt","rb");
    int num_elementos, elementos_leidos;
    char *cadena;
    
    if(flujo == NULL){

        perror("Erro en la apertura del archivo");
        return 1;

    }

    fseek(flujo,0,SEEK_END);
    num_elementos = ftell(flujo);
    rewind(flujo);              //Regresa al inicio del archivo

    cadena = (char *)calloc(sizeof(char),num_elementos,flujo);

    if(cadena == NULL){

        perror("Error en reserva de memoria");
        return 2;

    }

    elementos_leidos = fread(cadena,sizeof(char),num_elementos,flujo);

    if(num_elementos != elementos_leidos){

        perror("Error leyendo el archivo");
        return 3;

    }



    free(cadena);
    fclose(flujo);
    printf("\n\nSe ha leido el archivo correctamente ...");

    return 0;

}