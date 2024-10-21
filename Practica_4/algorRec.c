#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

int factorialrec(int n){

  int x;

  if (n == 0 || n == 1)
    return 1;
  
  return n*factorialrec(n-1);
}

int fiborec(int n){
  if(n<2)
    return n;
  return (fiborec(n-1)+fiborec(n-2));
}


void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Mueve el disco %d de %c a %c\n",n, from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Mueve el disco %d de %c a %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}
