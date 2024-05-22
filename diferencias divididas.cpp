#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición de la estructura para el polinomio
struct Polinomio {
    double *coeficientes;
    int grado;
};

// Función para calcular el polinomio interpolante mediante diferencias divididas de Newton
struct Polinomio diferenciasDivididas(double *xi, double *fi, int n) {
    // Inicialización del polinomio
    struct Polinomio polinomio;
    polinomio.grado = n - 1;
    polinomio.coeficientes = (double *)malloc((n) * sizeof(double));

    // Cálculo de las diferencias divididas
    double *dDividida = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        dDividida[i] = fi[i];
    }

    // Proceso de las diferencias divididas
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            dDividida[i] = (dDividida[i] - dDividida[i - 1]) / (xi[i] - xi[i - j]);
        }
    }

    // Construcción del polinomio
    for (int i = 0; i < n; i++) {
        polinomio.coeficientes[i] = dDividida[i];
    }

    free(dDividida);

    return polinomio;
}

// Función para evaluar el polinomio en un punto dado
double evaluarPolinomio(struct Polinomio polinomio, double x) {
    double resultado = polinomio.coeficientes[polinomio.grado];
    for (int i = polinomio.grado - 1; i >= 0; i--) {
        resultado = resultado * (x - polinomio.coeficientes[i]) + polinomio.coeficientes[i];
    }
    return resultado;
}

int main() {
    // Datos de prueba
    double xi[] = {3.2, 3.8, 4.2, 4.5};
    double fi[] = {5.12, 6.42, 7.25, 6.85};
    int n = sizeof(xi) / sizeof(xi[0]);

    // Cálculo del polinomio interpolante
    struct Polinomio polinomio = diferenciasDivididas(xi, fi, n);

    // Evaluación del polinomio en algunos puntos
    printf("Polinomio evaluado en x = 4.0: %.4f\n", evaluarPolinomio(polinomio, 4.0));
    printf("Polinomio evaluado en x = 4.7: %.4f\n", evaluarPolinomio(polinomio, 4.7));

    // Liberar memoria asignada al polinomio
    free(polinomio.coeficientes);

    return 0;
}

