#include <stdio.h>
#include <stdlib.h>

// Función para encontrar el valor máximo del rod cortado
int cutRodRecur(int i, int price[], int n) {
    // Caso base
    if (i == 0)
        return 0;

    int ans = 0;

    // Encontrar el valor máximo para cada corte.
    // Tomar el valor del rod de longitud j, y
    // encontrar recursivamente el valor del rod de longitud (i-j).
    for (int j = 1; j <= i; j++) 
        ans = (ans > price[j-1] + cutRodRecur(i-j, price, n)) ? ans : price[j-1] + cutRodRecur(i-j, price, n);

    return ans;
}

// Función para encontrar el valor máximo del rod cortado
int cutRod(int price[], int n) {
    return cutRodRecur(n, price, n);
}

int main() {

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 25, 30};
    int n[] = {4,6,8,10};

    for(int i=0 ; i<sizeof(n)/sizeof(n[0]) ; i++ ){

        printf("El valor maximo para %d obtenido es de: %d\n",n[i], cutRod(price, n[i]));

    }
    return 0;
}