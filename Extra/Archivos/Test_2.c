#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *pfile = fopen("Prueba.txt","rb");
	
	if(pfile == NULL){
		perror("Erro abriendo archivo\n");
		return 1;
	}
	
	fseek(pfile,0,SEEK_END);
	int num_elementos = ftell(pfile);
	rewind(pfile);
	
	char *cadena = (char *) calloc(num_elementos,sizeof(char));
	
	if(cadena == NULL){
		
		perror("Error en reserva de memoria");
		return 2;
		
	}
	
	int elementos_leidos = fread(cadena,sizeof(char),num_elementos,pfile);
	if(num_elementos != elementos_leidos){
		perror("Error leyendo archivo");
		return 3;
	}
	
	printf("%s",cadena);
	
	free(cadena);
	
	fclose(pfile);
	
	return 0;
	
}
