#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include"algorIte.h"
#include"algorRec.h"

int main(){

    int chose,n;
    double time;

    printf("\nIngrese longitud del problema: ");
    scanf("%d",&n);

    printf("Seleccione un algoritmo:\n\n[1] Factorial Iterativo\t [2] Factorial Recursivo\n[3] TOH Iterativo\t [4] TOH Recursivo\n[5] Fibonacci Iterativo\t [6] Fibonacci Recursivo\n-->");
    scanf("%d",&chose);

    clock_t begin = clock();

    switch (chose){

    case 1:
        factorialIte(n);        
    break;

    case 2:
        
    break;

    case 3:
        
    break;

    case 4:
        
    break;

    case 5:
        
    break;

    case 6:
        
    break;
    
    default:
        break;

    }

    sleep(1);
    clock_t end = clock();

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion algoritmo: %f s\n-----------------------------------------",time);


}