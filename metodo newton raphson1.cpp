#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

// Definici�n de la funci�n y su derivada
double f(double x) {
    return x*x*x - 2*x + 1;
}

double f_prime(double x) {
    return 3*x*x - 2;
}

// M�todo de Newton-Raphson
double newtonRaphson(double x0, int max_iterations) {
    double x = x0;
    double x_next = x0;
    int i;

    for (i = 0; i < max_iterations; i++) {
        double fx = f(x);
        double fpx = f_prime(x);

        if (fabs(fpx) < EPSILON) {
            printf("La derivada se ha vuelto demasiado peque�a, salida del bucle.\n");
            break;
        }

        x_next = x - (fx / fpx);

        // Comprobar si estamos cerca de una ra�z repetida
        if (fabs(x_next - x) < EPSILON) {
            printf("Se alcanz� la convergencia lara�z.\n");
            break;
        }
        
        printf("Iteraci�n %d: x = %.8f\n", i + 1, x_next);
        x = x_next;
    }

    return x_next;
}

int main() {
    double x0;
    int max_iterations;

    printf("Ingrese el valor inicial x0: ");
    scanf("%lf", &x0);

    printf("Ingrese el n�mero m�ximo de iteraciones: ");
    scanf("%d", &max_iterations);

    printf("\nIteraciones del m�todo de Newton-Raphson:\n");
    double root = newtonRaphson(x0, max_iterations);

    printf("\nLa ra�z aproximada es: %.8f\n", root);

    return 0;
}

