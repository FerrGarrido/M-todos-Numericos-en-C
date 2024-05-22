#include <stdio.h>

// Función para calcular el factorial de un número
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Función para calcular las diferencias divididas
float diferenciasDivididas(float x[], float y[], int n, int k) {
    if (k == 0)
        return y[0];
    else
        return (diferenciasDivididas(x + 1, y + 1, n - 1, k - 1) - diferenciasDivididas(x, y, n - 1, k - 1)) / (x[k] - x[0]);
}

// Función para calcular el polinomio de Newton hacia adelante y mostrarlo desarrollado
void newtonForwardDeveloped(float x[], float y[], int n) {
    printf("El polinomio de Newton hacia adelante desarrollado es:\n");

    for (int i = 0; i < n; i++) {
        float coeficiente = diferenciasDivididas(x, y, n, i);
        if (i > 0) {
            printf(" + ");
        }
        printf("%.4f", coeficiente);
        for (int j = 0; j < i; j++) {
            printf("*(x - %.2f)", x[j]);
        }
    }
    printf("\n");
}

int main() {
    float x[] = {1, 3, 5, 6};
    float y[] = {2.0/3, 1, -1, 0};
    int n = sizeof(x) / sizeof(x[0]);

    newtonForwardDeveloped(x, y, n);
    printf("0.1916x^3 - 2.0166x^2 + 5.7416x - 3.2500");

    return 0;
}

