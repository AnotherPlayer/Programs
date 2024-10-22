#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
#include <limits.h> 

//Factorial iterativo
double factorialIte(int n){

    int i;
    double x=1;

    if(n==0 || n==1)
        x=1;
    
    else{
        for(i=1 ; i<=n ; i++){
            x*=(double)i;
            printf("  %f\n",x);
        }
    }

	return x;

}

// Fibonacci iterativo
void fibonacci(int n) {

	double curr;

    if (n < 1) {
        printf("Invalid Number of terms\n");
        return;
    }

    // When number of terms is greater than 0
    double prev1 = 1;
    double prev2 = 0;

    // If n is 1, then we do not need to
    // proceed further
    if (n == 1)
        return;

    // Print 3rd number onwards using
    // the recursive formula
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        //printf("%d ", curr);
    }

	printf("Fibonacci %d: %f\n",n,curr);
}



//TORRES DE HAOI Iterativo

// Función para mover un disco de una varilla a otra
void moverDisco(char desde, char hacia) {
    printf("Mover disco de %c a %c\n", desde, hacia);
}

// Función iterativa para resolver las Torres de Hanói
void torresDeHanoi(int n) {
    char torre1 = 'A', torre2 = 'B', torre3 = 'C';

    // Si el número de discos es par, intercambiamos torre2 y torre3
    if (n % 2 == 0) {
        char temp = torre2;
        torre2 = torre3;
        torre3 = temp;
    }

    int totalMovimientos = (1 << n) - 1;  // 2^n - 1

    // Bucle para realizar cada movimiento
    for (int i = 1; i <= totalMovimientos; i++) {
        if (i % 3 == 1) {
            moverDisco(torre1, torre3);  // Movimiento entre torre A y C
        } else if (i % 3 == 2) {
            moverDisco(torre1, torre2);  // Movimiento entre torre A y B
        } else {
            moverDisco(torre2, torre3);  // Movimiento entre torre B y C
        }
    }
}




