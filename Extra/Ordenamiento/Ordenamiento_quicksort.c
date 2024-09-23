#include <stdio.h>
#include <stdlib.h>

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


int main() {
    //estas 2 siguientes lineas copy
    int *num;
    int n = sizeof(num) / sizeof(num[0]);
    quickSort(num, 0, n - 1);

}

