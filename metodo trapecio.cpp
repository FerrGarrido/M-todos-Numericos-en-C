#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Función para calcular el valor de f(x)
float funcion(float x) {
    // Aquí se pueden colocar los valores de f(x) dados
    if (x == 1)
        return 1.000;
    else if (x == 2)
        return 0.500;
    else if (x == 3)
        return 0.333;
    else if (x == 4)
        return 0.250;
    else if (x == 5)
        return 0.200;
    else
        return 0; // Si x no coincide con ninguno de los valores dados
}

// Función para aplicar el método del trapecio
float metodoTrapecio(float a, float b) {
    float h = (b - a) / 4; // Dividimos el intervalo en 4 partes iguales
    float x0 = a;
    float x1 = a + h;
    float x2 = a + 2 * h;
    float x3 = a + 3 * h;
    float x4 = b;
    
    // Imprimir la tabla de valores de x y f(x)
    printf("x\tf(x)\n");
    printf("%.3f\t%.3f\n", x0, funcion(x0));
    printf("%.3f\t%.3f\n", x1, funcion(x1));
    printf("%.3f\t%.3f\n", x2, funcion(x2));
    printf("%.3f\t%.3f\n", x3, funcion(x3));
    printf("%.3f\t%.3f\n", x4, funcion(x4));
    
    // Sumamos los términos de la integral aproximada según la fórmula del método del trapecio
    float resultado = (h / 2) * (funcion(x0) + 2 * funcion(x1) + 2 * funcion(x2) + 2 * funcion(x3) + funcion(x4));
    
    // Imprimir el desarrollo
    printf("\nDesarrollo:\n");
    printf("Resultado = (%.3f / 2) * (%.3f + 2 * %.3f + 2 * %.3f + 2 * %.3f + %.3f)\n", h, funcion(x0), funcion(x1), funcion(x2), funcion(x3), funcion(x4));
    
    return resultado;
}

int main() {
    float a = 1; // Límite inferior de integración
    float b = 5; // Límite superior de integración
    float resultado = metodoTrapecio(a, b);
    printf("\nEl resultado de la integral aproximada es: %.3f\n", resultado);
    return 0;
}

