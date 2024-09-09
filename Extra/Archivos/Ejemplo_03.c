#include <stdio.h>

int main(){

    FILE *flujo = fopen("datos.txt","rb");
    char caracter;
    
    if(flujo == NULL){

        perror("Erro en la apertura del archivo");
        return 1;

    }

    while(feof(flujo) == 0){

        caracter = fgetc(flujo);
        printf("%c",caracter);

    }

    fclose(flujo);
    printf("\n\nSe ha leido el archivo correctamente ...");

    return 0;

}