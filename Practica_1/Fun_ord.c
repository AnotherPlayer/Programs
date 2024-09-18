//Burbuja
void burbuja(int *num, int num_length){

    int i, cond = 0;
    int pass = 0;
    int aux;

    while(!cond) {
        cond = 1;
        for(i = 0; i < num_length-pass-1; i++) {
            if(num[i] > num[i+1]) {
                cond = 0;
                aux = num[i];
                num[i] = num[i+1];
                num[i+1] = aux;
            }
        }
        pass++;
    }
}

//Inserccion 
void inserccion(int *num, int num_length){

    int i,j,aux;

    for(j=1 ; j<num_length ; j++){
        aux = num[j];
        i = j-1;
            while(i>=0 && num[i]>aux){
                num[i+1] = num[i];
                i = i-1;
            }
            
        num[i+1] = aux;
    }

}

//QuickSort
void merge(int *arr, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arrays temporales
    int L[n1], R[n2];

    // Copiar datos a los arrays temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Combinar los arrays temporales de vuelta en arr[p..r]
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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
}

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