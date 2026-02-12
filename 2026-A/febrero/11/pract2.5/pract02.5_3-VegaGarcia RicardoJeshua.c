// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// 2.5.- Otros Ejercicios de Ciclos

#include <stdio.h>

int main()
{
    int factorial = 1, n = 0;
    double e = 0.0; // <- double tiene un espacio de 64 bits

    while (n < 20)
    {
        if (n > 0)
            factorial *= n;
        e += 1.0 / (n > 0 ? factorial : 1);
        n++;
    }

    printf("El valor de e es: %.10f\n", e);
    return 0;
}