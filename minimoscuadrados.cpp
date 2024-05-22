#include <stdio.h>

// Función para calcular los coeficientes de la línea recta (m y b) usando el método de mínimos cuadrados
void calcularMinimosCuadrados(double x[], double y[], int n, double *m, double *b) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Calcular sumatorias y sumas intermedias
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Imprimir las sumas
    printf("Suma de xi: %.2f\n", sumX);
    printf("Suma de yi: %.2f\n", sumY);
    printf("Suma de xi^2: %.2f\n", sumX2);
    printf("Suma de xiyi: %.2f\n\n", sumXY);

    // Calcular m (pendiente)
    *m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    printf("m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX)\n");
    printf("  = (%d * %.2f - %.2f * %.2f) / (%d * %.2f - %.2f * %.2f)\n", n, sumXY, sumX, sumY, n, sumX2, sumX, sumX);
    printf("  = %.2f\n\n", *m);

    // Calcular b (intercepto)
    *b = (sumY - (*m) * sumX) / n;
    printf("b = (sumY - (m * sumX)) / n\n");
    printf("  = (%.2f - (%.2f * %.2f)) / %d\n", sumY, *m, sumX, n);
    printf("  = %.2f\n", *b);
}

int main() {
    // Datos
    double x[] = {1, 3, 4, 6, 8, 9};
    double y[] = {1, 2, 4, 4, 5, 7};
    int n = sizeof(x) / sizeof(x[0]);

    // Imprimir la tabla de valores
    printf("n\t xi\t yi\t xi^2\t xiyi\n");
    for (int i = 0; i < n; i++) {
        double xi = x[i];
        double yi = y[i];
        double xi2 = xi * xi;
        double xiyi = xi * yi;
        printf("%d\t %.2f\t %.2f\t %.2f\t %.2f\n", i + 1, xi, yi, xi2, xiyi);
    }
    printf("\n");

    // Coeficientes de la línea recta (m y b)
    double m, b;
    calcularMinimosCuadrados(x, y, n, &m, &b);

    // Imprimir la ecuación de la línea recta (y = mx + b)
    printf("\nLa ecuación de la línea recta es: y = %.2fx + %.2f\n", m, b);

    return 0;
}

