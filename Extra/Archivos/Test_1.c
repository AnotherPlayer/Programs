#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *pfile = fopen("Texto.txt","rb");
	
	if(pfile == NULL){
		perror("Erro abriendo archivo\n");
	}
	
	char caracter;
	
	while(!feof(pfile)){
		
		caracter = fgetc(pfile);
		printf("%c",caracter);
		
	}
	
	fclose(pfile);
	
	return 0;
	
}
