// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 4-Febrero-2026
// 2.6.- Ejercicios para reforzar con ciclos

#include <stdio.h>

int main()
{
    int before = 0, after = 1, large, i = 0;

    printf("Ingresa el largo de la serie de Fibonacci: ");
    scanf("%d", &large);

    while (i < large)
    {
        if (before <= after)
        {
            const int op = before + after;
            printf("%d + %d = %d\n", before, after, op);
            before = op;
        }
        else
        {
            const int op = before + after;
            printf("%d + %d = %d\n", before, after, op);
            after = before;
            before = op;
        }
        i++;
    }

    return 0;
}