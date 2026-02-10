// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 4-Febrero-2026
// 2.6.- Ejercicios para reforzar con ciclos

#include <stdio.h>

int main()
{
    int n = 1, values[5], p1, p2, p3, i = 0, temp = 0, repeat = 1;

    while (n <= 5)
    {
        int number;
        printf("Ingresa un numero: ");
        scanf("%d", &number);
        values[n - 1] = number;
        n++;
    }

    while (i < 5)
    {
        const int value = values[i];

        if (temp == 0)
            temp = value;
        else if (value == temp)
            repeat++;
        else
        {
            temp = value;
            repeat = 1;
        }

        if (value > p1)
        {
            p3 = p2;
            p2 = p1;
            p1 = value;
        }
        else if (value > p2)
        {
            p3 = p2;
            p2 = value;
        }
        else if (value > p3)
        {
            p3 = value;
        }
        i++;
    }

    if (repeat == 5)
    {
        printf("Todos los numeros son iguales: %d\n", p1);
        return 0;
    }

    printf("El numero mayor es %d, el del medio es %d y el menor es %d\n", p1, p2, p3);

    return 0;
}