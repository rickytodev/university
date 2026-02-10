// Alumno: Ricardo Jeshua Vega Garcia
// Código: 225976304
// Nombre Actividad: if-else y anidación if-else
// Actividad: 2.1
// Fecha: 28 / Enero / 2026

#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Ingresa el valor de (a): ");
    scanf("%d", &a);

    printf("Ingresa el valor de (b): ");
    scanf("%d", &b);

    printf("Ingresa el valor de (c): ");
    scanf("%d", &c);

    if (a == b && b == c && a == c)
    {
        printf("Los tres numeros son iguales: %d\n", a);
    }
    else if (a > b)
    {
        if (a > c)
        {
            if (b > c)
            {
                printf("Mayor (a): %d, Intermedio (b): %d, Menor (c): %d\n", a, b, c);
            }
            else
            {
                printf("Mayor (a): %d, Intermedio (c): %d, Menor (b): %d\n", a, c, b);
            }
        }
        else
        {
            printf("Mayor (c): %d, Intermedio (a): %d, Menor (b): %d\n", c, a, b);
        }
    }
    else
    {
        if (b > c)
        {
            if (a > c)
            {
                printf("Mayor (b): %d, Intermedio (a): %d, Menor (c): %d\n", b, a, c);
            }
            else
            {
                printf("Mayor (b): %d, Intermedio (c): %d, Menor (a): %d\n", b, c, a);
            }
        }
        else
        {
            printf("Mayor (c): %d, Intermedio (b): %d, Menor (a): %d\n", c, b, a);
        }
    }

    return 0;
}