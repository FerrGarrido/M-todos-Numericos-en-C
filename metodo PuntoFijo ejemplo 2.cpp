#include <stdio.h>
#include <math.h>

#define TOL 0.0001

double f1(double x, double y) {
    return sqrt(y * y - 2 * y);
}

double f2(double x, double y) {
    return sqrt(6 - 2 * x);
}

void puntoFijo(double x0, double y0, int max_iter) {
    double x = x0, y = y0, x_prev, y_prev;
    int iter = 0;
    
    printf("Iteración  x           y\n");
    printf("========================\n");
    
    do {
        x_prev = x;
        y_prev = y;
        x = f1(x_prev, y_prev);
        y = f2(x_prev, y_prev);
        iter++;
        printf("%8d  %.6f  %.6f\n", iter, x, y);
    } while (iter < max_iter);
}

int main() {
    double x0 = 1.0, y0 = 1.0;
    int max_iter;
    
    printf("Ingrese el número máximo de iteraciones a mostrar: ");
    scanf("%d", &max_iter);
    
    printf("\nValores iniciales: x0 = %.1f, y0 = %.1f\n", x0, y0);
    puntoFijo(x0, y0, max_iter);
    
    return 0;
}

