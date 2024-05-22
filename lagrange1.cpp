#include <stdio.h>

// Función para calcular el polinomio de Lagrange
double lagrange(int n, double xn[], double yn[], double x) {
    double result = 0.0;

    printf("\nValores del polinomio:\n");
    for (int i = 0; i < n; i++) {
        double term = yn[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - xn[j]) / (xn[i] - xn[j]);
            }
        }
        printf("%.2f\t", term); // Imprimir el valor de cada término del polinomio
        result += term;
    }

    return result;
}

int main() {
    // Datos de la tabla
    int n = 3;
    double xn[] = {1, 4, 6};
    double yn[] = {0, 1.39, 1.79};

    // Imprimir la tabla de valores inicial
    printf("Tabla de valores inicial:\n");
    printf("x\ty\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t%.2f\n", xn[i], yn[i]);
    }

    // Calcular y mostrar el polinomio interpolador de Lagrange de grado 3
    printf("\nPolinomio de Lagrange:\n");
    printf("(x - %.2f)(x - %.2f) / (%.2f - %.2f)(%.2f - %.2f) * %.2f + ", xn[1], xn[2], xn[0], xn[1], xn[0], xn[2], yn[0]);
    printf("(x - %.2f)(x - %.2f) / (%.2f - %.2f)(%.2f - %.2f) * %.2f + ", xn[0], xn[2], xn[1], xn[0], xn[1], xn[2], yn[1]);
    printf("(x - %.2f)(x - %.2f) / (%.2f - %.2f)(%.2f - %.2f) * %.2f\n", xn[0], xn[1], xn[2], xn[0], xn[2], xn[1], yn[2]);
    
    // Polinomio simplificado
    printf("\nPolinomio simplificado:\n");
    printf("(x^2 - 7x + 6) * (-0.2316) + (x^2 - 5x + 4) * (0.179)\n");
    printf("-0.0926x^2 + 0.766x -0.674");

    return 0;
}

