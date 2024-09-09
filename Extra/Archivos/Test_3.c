#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *pfile = fopen("Check_2.txt","a");
	
	if(pfile == NULL){
		perror("Error leyendo archivo");
	}
	else{
		
		int i,j;
		
		for(i=0 ; i<10 ; i++){
			for(j=0 ; j<20; j++){
				fputs("O  ",pfile);
			}
			fputc('\n',pfile);
		}
		
	}
	
	fflush(pfile);
	
	fclose(pfile);
	
	printf("Exito");
	
	return 0;
	
}
