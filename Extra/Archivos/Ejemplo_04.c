#include <stdio.h>

int main(){

    FILE *flujo = fopen("datos.txt","rb");

    int numero;
    char cadena[10];
    
    if(flujo == NULL){

        perror("Erro en la apertura del archivo");
        return 1;

    }

    while(feof(flujo) == 0){

        fscanf(flujo,"%d%s",&numero, &cadena);
        printf("%d %s\n",numero, cadena);

    }

    fclose(flujo);
    printf("\n\nSe ha leido el archivo correctamente ...");

    return 0;

}