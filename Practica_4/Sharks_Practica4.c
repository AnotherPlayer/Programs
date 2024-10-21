#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include"algorIte.h"
#include"algorRec.h"

struct Stack{ 
unsigned capacity; 
int top; 
int *array; 
}; 

int main(){

    int choose,n;
    double time;
    struct Stack src,aux,dest;

    printf("\nIngrese longitud del problema: ");
    scanf("%d",&n);

    printf("Seleccione un algoritmo:\n\n[1] Factorial Iterativo\t [2] Factorial Recursivo\n[3] TOH Iterativo\t [4] TOH Recursivo\n[5] Fibonacci Iterativo\t [6] Fibonacci Recursivo\n-->");
    scanf("%d",&choose);

    clock_t begin = clock();

    switch (choose){

    case 1:
        factorialIte(n);        
        break;
        
    case 2:
        factorialrec(n);
        break;

    case 3:

        tohIterative(n,Stack src, Stack aux, Stack dest);
        break;

    case 4:
        hanoi(n,'x','y','z');
        break;

    case 5:
        fibonacci(n);
        break;

    case 6:
        fiborec(n);
        break;
    
    default:
        break;

    }

    sleep(1);
    clock_t end = clock();

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion algoritmo: %f s\n-----------------------------------------\n",time);


}