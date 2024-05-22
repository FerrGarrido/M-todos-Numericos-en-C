#include <stdio.h>

double funcion(double x) {
    return 1/x; // Definici�n de la funci�n f(x) = 1/x
}

double simpson_3_8(double a, double b, int n) {
    double h = (b - a) / n;
    double suma = funcion(a) + funcion(b);
    double suma_parcial = suma;
    double resultado_parcial = (3 * h / 8) * suma;
    double x;

    printf("i\txi\t\tf(xi)\t\tci*f(xi)\t\tSuma parcial\n");
    printf("--------------------------------------------------------\n");

    for (int i = 1; i < n; i++) {
        x = a + i * h;
        double ci = (i % 3 == 0) ? 2 : 3; // Coeficiente ci

        double fx = funcion(x);
        double cifx = ci * fx;
        suma += cifx;
        resultado_parcial += (3 * h / 8) * cifx;

        printf("%d\t%lf\t%lf\t%lf\t%lf\n", i, x, fx, cifx, resultado_parcial);
    }

    printf("--------------------------------------------------------\n");
    printf("Resultado final de la aproximaci�n: %lf\n", resultado_parcial);
    return resultado_parcial;
}

int main() {
    int n = 6; // Cantidad de intervalos
    double a = 1.0; // L�mite inferior
    double b = 5.0; // L�mite superior
    double integral;

    printf("Intervalo de integraci�n: [%lf, %lf]\n", a, b);
    integral = simpson_3_8(a, b, n);
    printf("\nAproximaci�n de la integral: %lf\n", integral);

    return 0;
}
/*<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simpson 3/8</title>
</head>
<body>
    <table id="simpsonTabla">
        <thead>
            <tr>
                <th>i</th>
                <th>xi</th>
                <th>f(xi)</th>
                <th>ci*f(xi)</th>
                <th>Suma parcial</th>
            </tr>
        </thead>
        <tbody></tbody>
    </table>

    <script>
        function funcion(x) {
            return 1/x; // Definici�n de la funci�n f(x) = 1/x
        }

        function simpsontresoctavos(a, b, n) {
            let h = (b - a) / n;
            let suma = funcion(a) + funcion(b);
            let suma_parcial = suma;
            let resultado_parcial = (3 * h / 8) * suma;
            let x;

            let tableBody = document.getElementById('simpsonTabla').getElementsByTagName('tbody')[0];
            
            for (let i = 1; i < n; i++) {
                x = a + i * h;
                let ci = (i % 3 === 0) ? 2 : 3; // Coeficiente ci

                let fx = funcion(x);
                let cifx = ci * fx;
                suma += cifx;
                resultado_parcial += (3 * h / 8) * cifx;

                let newRow = tableBody.insertRow();
                newRow.innerHTML = `<td>${i}</td><td>${x}</td><td>${fx}</td><td>${cifx}</td><td>${resultado_parcial}</td>`;
            }

            console.log("Resultado final de la aproximaci�n:", resultado_parcial);
            return resultado_parcial;
        }

        // Llamada a la funci�n con los par�metros deseados
        let a = 1.0; // L�mite inferior
        let b = 5.0; // L�mite superior
        let n = 6; // Cantidad de intervalos
        let integral = simpsontresoctavos(a, b, n);
        console.log("Aproximaci�n de la integral:", integral);
    </script>
</body>
</html>
*/

