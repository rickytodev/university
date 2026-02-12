// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// Ciclos Anidados para Reforzar

#include <stdio.h>

int main()
{
    int iRange, eRange;

    while (1)
    {
        printf("Ingresa inicio del rango: ");
        scanf("%d", &iRange);

        printf("Ingresa fin del rango: ");
        scanf("%d", &eRange);

        if (iRange < eRange)
            break;
        else
            printf("El inicio del rango debe ser menor que el fin del rango. Intenta de nuevo.\n");
    }

    int i = iRange;

    while (i <= eRange)
    {
        int j = 1, k = 1;

        while (j <= i)
        {
            k *= j;
            j++;
        }

        printf("El factorial de %d es %d\n", i, k);
        i++;
    }

    return 0;
}