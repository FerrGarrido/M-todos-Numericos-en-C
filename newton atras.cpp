#include <stdio.h>

// Función para calcular las diferencias divididas
float diferencias_divididas(int n, float x[], float y[]) {
    float matriz[n][n];
    int i, j;

    // Inicialización de la matriz con los valores de y
    for (i = 0; i < n; i++)
        matriz[i][0] = y[i];

    // Calcular las diferencias divididas
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            matriz[i][j] = (matriz[i+1][j-1] - matriz[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // La primera entrada de la diagonal de la matriz representa la diferencia dividida de orden cero
    return matriz[0][0];
}

// Función para imprimir el polinomio interpolante desarrollado
void imprimir_polinomio(int n, float x[], float y[]) {
    printf("El polinomio interpolante desarrollado es:\n");
    printf("P(x) = ");

    // Imprimir el término independiente
    printf("%.6f ", y[0]);

    // Imprimir los términos con las diferencias divididas
    for (int i = 1; i < n; i++) {
        printf("+ %.6f", diferencias_divididas(i + 1, x, y));

        // Imprimir los términos (x - x0)(x - x1)...(x - xi-1)
        for (int j = 0; j < i; j++) {
            printf("*(x - %.2f)", x[j]);
        }
    }
    printf("\n");
}

int main() {
    float x[] = {1, 3, 5, 6};
    float y[] = {2.0/3, 1, -1, 0};
    int n = sizeof(x) / sizeof(x[0]); // Calcular el tamaño del arreglo

    // Imprimir el polinomio interpolante desarrollado
    imprimir_polinomio(n, x, y);

    return 0;
}

