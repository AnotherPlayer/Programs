#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


    //Algoritmo Kadame
int maxSubarraySumite(int arr[], int size) {
    int maxSum = arr[0];
    // Outer loop for starting point of subarray
    for (int i = 0; i < size; i++) {
        int currSum = 0;
        // Inner loop for ending point of subarray
        for (int j = i; j < size; j++) {
            currSum = currSum + arr[j];
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

    //Algoritmo divide y venceras

// A utility function to find maximum of two integers 
int max(int a, int b) { 
    return (a > b) ? a : b; 
} 

// A utility function to find maximum of three integers 
int max3(int a, int b, int c) { 
    return max(max(a, b), c); 
} 

// Find the maximum possible sum in arr[] such that arr[m] is part of it 
int maxCrossingSum(int arr[], int l, int m, int h) { 
    // Include elements on left of mid. 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= l; i--) { 
        sum += arr[i]; 
        if (sum > left_sum) 
            left_sum = sum; 
    } 

    // Include elements on right of mid 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m + 1; i <= h; i++) { 
        sum += arr[i]; 
        if (sum > right_sum) 
            right_sum = sum; 
    } 

    // Return sum of elements on left and right of mid 
    return max3(left_sum + right_sum, left_sum, right_sum); 
} 

// Returns sum of maximum sum subarray in arr[l..h] 
int maxSubArraySum(int arr[], int l, int h) { 
    // Invalid Range: low is greater than high 
    if (l > h) 
        return INT_MIN; 
    // Base Case: Only one element 
    if (l == h) 
        return arr[l]; 

    // Find middle point 
    int m = (l + h) / 2; 

    /* Return maximum of following three possible cases 
        a) Maximum subarray sum in left half 
        b) Maximum subarray sum in right half 
        c) Maximum subarray sum such that the subarray crosses the midpoint */
    return max3(maxSubArraySum(arr, l, m - 1),maxSubArraySum(arr, m + 1, h),maxCrossingSum(arr, l, m, h)); 
}

int num_length;

void getArray(int *num, FILE *file){
    int i;
    for(i=0 ; i<num_length ; i++){
        fscanf(file, "%d", &num[i]);
    };
}


int main(){
int choose;
    //Aceso al documento
    FILE *file = fopen("numeros.txt","r");
    
    if(file == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }

    //Se declara un arreglo dinamico segun las nececidades del usuario
    puts("Ingrese el tamano del problema(Tamano del arreglo):");
    scanf("%d",&num_length);
    int *A = (int *)malloc(num_length * sizeof(int));

    if (A == NULL) {
        perror("Error al asignar memoria");
        fclose(file);
    }

    //Funcion para obtener los numeros deseados
    getArray(A,file);
    fclose(file);
    int Max, Min;
    puts("Este programa obtiene la suma maxima de un subarreglo\n1.Iterativo [1]\n2.Recursivo [2]\n");
    scanf("%d",&choose);


    clock_t start = clock();
    sleep(1);
    switch (choose){

    case 1:
        printf("Iteracion: ");
        printf("%d", maxSubarraySumite(A,num_length));

        break;
    
    case 2:
        printf("Recurcion: ");
        printf("%d", maxSubArraySum(A, 0, num_length - 1));
        

    default:
        break;
    }
    clock_t end = clock();  // Finaliza el conteo de tiempo
    printf("\nTiempo de ejecucion: %.8f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
