#include <stdio.h>

typedef struct {
    double x, y;
} Punto;

void triangulacion(Punto poligono[], int n) {
    if (n < 3) {
        printf("No es posible triangular menos de 3 puntos.\n");
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        printf("Triángulo: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n",
            poligono[0].x, poligono[0].y,
            poligono[i].x, poligono[i].y,
            poligono[i+1].x, poligono[i+1].y);
    }
}

int main() {
    Punto poligono[] = {{0,0}, {4,0}, {4,3}, {0,3}};
    int n = sizeof(poligono) / sizeof(poligono[0]);

    triangulacion(poligono, n);

    return 0;
}