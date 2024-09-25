#include<stdlib.h>

//Quick Sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *num, int low, int high) {
  
    // Elegir pivote
    int pivot = num[high];
  
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (num[j] < pivot) {
            i++;
            swap(&num[i], &num[j]);
        }
    }
    
    swap(&num[i + 1], &num[high]);
    return i + 1;
}

void quickSort(int *num, int low, int high) {
  
    if (low < high) {
        int pi = partition(num, low, high);
        
        quickSort(num, low, pi - 1);
        quickSort(num, pi + 1, high);
    }
}


//Merge Sort
void merge(int *arr, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arrays temporales
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Verifica si la asignación de memoria fue exitosa
    /*if (!L || !R) {
        fprintf(stderr, "Error de asignación de memoria\n");
        exit(1);
    }*/

    // Copiar datos a los arrays temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Combinar los arrays temporales de vuelta en arr[p..r] de mayor a menor
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { // Cambia aquí para ordenar de mayor a menor
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Liberar la memoria
    free(L);
    free(R);
}

// Función de ordenamiento por merge sort
void mergeSort(int *arr, int p, int r) {
    if (p < r) {
        // Encuentra el punto medio del arreglo
        int q = p + (r - p) / 2;

        // Ordena la primera y segunda mitad del array
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        // Combina las mitades ordenadas
        merge(arr, p, q, r);
    }
}