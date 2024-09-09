#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char nombre[11] = "datos4.dat", mensaje[81]="";
  FILE *fichero;
  long int comienzo, final;

  fichero = fopen( nombre, "r" );
  printf( "Fichero: %s -> ", nombre );
  if( fichero )
    printf( "existe (ABIERTO)\n" );

  else{
    printf( "Error (NO ABIERTO)\n" );
    return 1;
  }

  if( (comienzo=ftell( fichero )) < 0 )   printf( "ERROR: ftell no ha funcionado\n" );
  else    printf( "Posición del fichero: %d\n\n", comienzo );

  fseek( fichero, 0L, SEEK_END );
  final = ftell( fichero );

  fseek( fichero, 0L, SEEK_SET );
  fgets( mensaje, 80, fichero );
  printf( "Tamano del fichero \"%s\": %d bytes\n", nombre, final-comienzo+1 );
  printf( "Mensaje del fichero:\n%s\n", mensaje );
  printf( "\nTamaño del mensaje (usando strlen): %d\n", strlen(mensaje) );

  if( !fclose(fichero) )
    printf( "Fichero cerrado\n" );
  else
  {
    printf( "Error: fichero NO CERRADO\n" );
    return 1;
  }

  return 0;
}
