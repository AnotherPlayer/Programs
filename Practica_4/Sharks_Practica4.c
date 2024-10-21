#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#include"algorIte.h"
#include"algorRec.h"

int main(){

    int choose,n;
    double time;
    int check;

    printf("\nIngrese longitud del problema: ");
    scanf("%d",&n);

    printf("Seleccione un algoritmo:\n\n[1] Factorial Iterativo\t [2] Factorial Recursivo\n[3] TOH Iterativo\t [4] TOH Recursivo\n[5] Fibonacci Iterativo\t [6] Fibonacci Recursivo\n-->");
    scanf("%d",&choose);

    clock_t begin = clock();

    switch (choose){

    case 1:
        check = factorialIte(n);
        printf("Factorial %d: %d\n",n,check);   
        break;
        
    case 2:
        check = factorialrec(n);
        printf("Factorial %d: %d\n",n,check);
        break;

    case 3:

        torresDeHanoi(n);

        break;

    case 4:
        hanoi(n,'A','B','C');
        break;

    case 5:
        fibonacci(n);
        break;

    case 6:
        check = fiborec(n);
        printf("Factorial %d: %d\n",n,check);
        break;
    
    default:
        break;

    }

    sleep(1);
    clock_t end = clock();

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion algoritmo: %lf s\n-----------------------------------------\n",time);


}