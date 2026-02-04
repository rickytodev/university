// Ricardo Jeshua Vega Garcia
// 225976304
// Pactica 2.3 - Ciclo do While - Ejercicio 1

#include <stdio.h>

int main()
{
    int number, par = 0, impar = 0, total = 0;

    do
    {
        printf("Ingresa un número entero: ");
        scanf("%d", &number);

        if (number == 0)
            break;

        if (number % 2 == 0)
            par++;
        else
            impar++;

        total += number;
    } while (number != 0);

    printf("Cantidad de números pares: %d\n", par);
    printf("Cantidad de números impares: %d\n", impar);
    printf("Suma total de los números ingresados: %d\n", total);

    return 0;
}