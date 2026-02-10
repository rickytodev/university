// Ricardo Jeshua Vega Garcia
// 225976304
// Pactica 2.2 - Ciclo While - Ejercicio 2

#include <stdio.h>

int main()
{
    int number, divisors = 0, i = 1;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &number);

    if (number <= 1)
    {
        printf("El número no es primo.\n");
        return 0;
    }

    while (i <= number)
    {
        if (number % i == 0)
            divisors++;
        i++;
    }

    if (divisors == 2)
        printf("El número es primo.\n");
    else
        printf("El número no es primo.\n");

    return 0;
}
