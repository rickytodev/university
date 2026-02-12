// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// Ciclos Anidados para Reforzar

#include <stdio.h>

int main()
{

    int i_range, e_range, potencia;

    while (1)
    {
        printf("Ingresa el numero inicial del rango: ");
        scanf("%d", &i_range);

        printf("Ingresa el numero final del rango: ");
        scanf("%d", &e_range);

        printf("Ingresa la potencia: ");
        scanf("%d", &potencia);

        if (i_range < e_range)
            break;
        else
            printf("El numero inicial del rango debe ser menor al numero final del rango. Intenta de nuevo.\n");
    }

    int i = i_range;

    while (i <= e_range)
    {
        int result = 1;
        int count = 0;

        while (count < potencia)
        {
            result *= i;
            count++;
        }

        printf("%d elevado a la %d es: %d\n", i, potencia, result);
        i++;
    }

    return 0;
}