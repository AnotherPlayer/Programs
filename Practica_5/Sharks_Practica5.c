#include<stdio.h>
#include<stdlib.h>

void MaxMin(int *arr, int Max, int min){
  Max= arr[1];
  Min= arr[2];
  for(int i=0;i<n;i++){
    if(arr[i]>Max)
        Max=arr[i];
    else if(arr[i]<Min)
      Min=arr[i]
  }
  print("Este es el maximo: %d\nEste es el minimo: %d",Max,Min);
}

void MaxMinDV(int A[], int i, int j, int *Max, int *Min) {
    int Max1, Min1, Max2, Min2, mit;
    
    if (i == j) {  // Caso base: un solo elemento
        *Max = A[i];
        *Min = A[i];
    } 
    else if (i == j - 1) {  // Caso base: dos elementos
        if (A[i] > A[j]) {
            *Max = A[i];
            *Min = A[j];
        } else {
            *Max = A[j];
            *Min = A[i];
        }
    } 
    else {  // Dividir y combinar
        mit = (i + j) / 2;
        MaxMinDV(A, i, mit, &Max1, &Min1);
        MaxMinDV(A, mit + 1, j, &Max2, &Min2);
        
        // Combinar resultados
        *Max = (Max1 > Max2) ? Max1 : Max2;
        *Min = (Min1 < Min2) ? Min1 : Min2;
    }
}




int main(){
    int A[] = {3, 5, 1, 8, 2, 9, 4, 7};
    int n = sizeof(A) / sizeof(A[0]);
    int Max, Min;

    MaxMin(*arr,Max,Min);

    MaxMinDV(A, 0, n - 1, &Max, &Min);

    printf("El valor máximo es: %d\n", Max);
    printf("El valor mínimo es: %d\n", Min);

    return 0;
}


}
