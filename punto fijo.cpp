#include <stdio.h>
#include<math.h>

// Definir la funci�n f(x)
double funcion(double x) {
  return (x * x * x) + (4 * x * x) - 10;
}

// Implementar el m�todo del punto fijo
double metodoPuntoFijo(double x0, double tol, int maxIteraciones) {
  double xn = x0;
  double error;

  for (int i = 0; i < maxIteraciones; i++) {
    double xn1 = xn - (funcion(xn) / (8 * xn + 3 * (xn * xn)));

    error = fabs(xn1 - xn);

    printf("Iteraci�n %d: x = %.4f, error = %.4f\n", i + 1, xn1, error);

    if (error < tol) {
      return xn1;
    }

    xn = xn1; // Actualizar xn con xn1
  }

  printf("No se converge en el n�mero m�ximo de iteraciones.\n");
  return xn;
}

int main() {
  // Definir par�metros
  double x0 = 1.5;   // Valor inicial
  double tol = 1e-5;   // Tolerancia

  // Solicitar al usuario el n�mero m�ximo de iteraciones
  int maxIteraciones;
  printf("Ingrese el n�mero m�ximo de iteraciones: ");
  scanf("%d", &maxIteraciones);

  // Aplicar el m�todo del punto fijo
  double raiz = metodoPuntoFijo(x0, tol, maxIteraciones);

  // Mostrar el resultado con 4 decimales
  printf("Ra�z aproximada: %.4f\n", raiz);

  return 0;
}

