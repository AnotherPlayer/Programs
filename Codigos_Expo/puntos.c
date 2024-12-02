#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int compararX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compararY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float distancia(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float fuerzaBruta(Point P[], int n) {
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distancia(P[i], P[j]) < min)
                min = distancia(P[i], P[j]);
    return min;
}

float minimo(float x, float y) {
    return (x < y) ? x : y;
}

float franjaCercana(Point franja[], int tamano, float d) {
    float min = d;
    qsort(franja, tamano, sizeof(Point), compararY);
    for (int i = 0; i < tamano; ++i)
        for (int j = i + 1; j < tamano && (franja[j].y - franja[i].y) < min; ++j)
            if (distancia(franja[i], franja[j]) < min)
                min = distancia(franja[i], franja[j]);
    return min;
}

float encontrarCercanoUtil(Point P[], int n) {
    if (n <= 3)
        return fuerzaBruta(P, n);
    int mid = n / 2;
    Point puntoMedio = P[mid];
    float dl = encontrarCercanoUtil(P, mid);
    float dr = encontrarCercanoUtil(P + mid, n - mid);
    float d = minimo(dl, dr);
    Point franja[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - puntoMedio.x) < d)
            franja[j] = P[i], j++;
    return minimo(d, franjaCercana(franja, j, d));
}

float encontrarCercano(Point P[], int n) {
    qsort(P, n, sizeof(Point), compararX);
    return encontrarCercanoUtil(P, n);
}






int main() {
Point P[] = {
    {2, 3}, {12, 30}
};



    int n = sizeof(P) / sizeof(P[0]);

    // Variables para medir el tiempo
    LARGE_INTEGER start, end, frequency;
    double cpu_time_used;

    // Obtener la frecuencia del contador
    QueryPerformanceFrequency(&frequency);

    // Inicia la medición del tiempo
    QueryPerformanceCounter(&start);

    // Llama a la función para encontrar la distancia más pequeña
    float distancia = encontrarCercano(P, n);

    // Termina la medición del tiempo
    QueryPerformanceCounter(&end);

    // Calcula el tiempo utilizado en segundos
    cpu_time_used = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    // Imprime la distancia más pequeña y el tiempo utilizado
    printf("La distancia más pequeña es %f\n", distancia);
    printf("El tiempo para encontrar la distancia fue %f segundos\n", cpu_time_used);

    return 0;
}

