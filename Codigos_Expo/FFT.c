#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

// Función recursiva FFT
void fft(complex double *x, int n) {
    // Caso base: si la longitud de la señal es 1, ya está transformada
    if (n <= 1) return;

    // Separar en subarrays de pares e impares
    complex double even[n/2];
    complex double odd[n/2];

    for (int i = 0; i < n/2; i++) {
        even[i] = x[i*2];       // Elementos pares
        odd[i] = x[i*2 + 1];    // Elementos impares
    }

    // Llamadas recursivas para subproblemas más pequeños
    fft(even, n/2);
    fft(odd, n/2);

    // Combinar resultados de los subproblemas
    for (int k = 0; k < n/2; k++) {
        // Calcular el término twiddle factor (raíz de la unidad)
        complex double t = cexp(-2.0 * I * PI * k / n) * odd[k];
        x[k] = even[k] + t;         // Parte "baja" del resultado FFT
        x[k + n/2] = even[k] - t;   // Parte "alta" del resultado FFT
    }
}

int main() {
    // Tamaño de la señal (debe ser potencia de 2)
    int n = 8;

    // Definir la señal de entrada (ejemplo: números reales)
    complex double x[] = {1.0 + 0.0*I, 1.0 + 0.0*I, 1.0 + 0.0*I, 1.0 + 0.0*I, 
                          0.0 + 0.0*I, 0.0 + 0.0*I, 0.0 + 0.0*I, 0.0 + 0.0*I};

    // Mostrar la señal de entrada
    printf("Señal de entrada:\n");
    for (int i = 0; i < n; i++) {
        printf("%2.1f + %2.1fi\n", creal(x[i]), cimag(x[i]));
    }

    // Llamada recursiva a FFT
    fft(x, n);

    // Imprimir el resultado de la FFT
    printf("\nResultado de la FFT:\n");
    for (int i = 0; i < n; i++) {
        printf("%2.1f + %2.1fi\n", creal(x[i]), cimag(x[i]));
    }

    return 0;
}