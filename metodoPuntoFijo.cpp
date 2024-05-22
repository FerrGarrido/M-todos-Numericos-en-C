#include <stdio.h>
#include <math.h>

// Definir las funciones f(x) y g(y)
double funcion_x(double xn, double yn) {
  return 0.5 * (-pow(yn, 2) + 6);
}

double funcion_y(double xn, double yn) {
  return 0.5 * (-pow(xn, 2) + pow(yn, 2));
}

// Implementar el método del punto fijo
void metodoPuntoFijo(double x0, double y0, double tol, int maxIteraciones) {
  double xn = x0;
  double yn = y0;
  double error_x, error_y;

  for (int i = 0; i < maxIteraciones; i++) {
    double xn1 = funcion_x(xn, yn);
    double yn1 = funcion_y(xn, yn);

    error_x = fabs(xn1 - xn);
    error_y = fabs(yn1 - yn);

    printf("Iteración %d: x = %.4f, y = %.4f, error_x = %.4f, error_y = %.4f\n", i + 1, xn1, yn1, error_x, error_y);

    if (error_x < tol && error_y < tol) {
      printf("Convergencia alcanzada.\n");
      return;
    }

    xn = xn1;
    yn = yn1;
  }

  printf("No se converge en el número máximo de iteraciones.\n");
}

int main() {
  // Definir parámetros
  double x0 = 1;   // Valor inicial para x
  double y0 = 1;   // Valor inicial para y
  double tol = 1e-5;   // Tolerancia

  // Solicitar al usuario el número máximo de iteraciones
  int maxIteraciones;
  printf("Ingrese el número máximo de iteraciones: ");
  scanf("%d", &maxIteraciones);

  // Aplicar el método del punto fijo
  metodoPuntoFijo(x0, y0, tol, maxIteraciones);

  return 0;
}

