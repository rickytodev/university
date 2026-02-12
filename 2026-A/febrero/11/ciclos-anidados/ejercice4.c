// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// Ciclos Anidados para Reforzar

#include <stdio.h>

int main()
{
    int x, numero, i = 0, j, bits[32], contador;

    while (1)
    {
        printf("Cuantos numeros deseas convertir: ");
        scanf("%d", &x);

        if (x > 0)
            break;
        else
            printf("El numero debe ser mayor que cero. Intenta de nuevo.\n");
    }

    while (i < x)
    {
        printf("\nIngresa un numero: ");
        scanf("%d", &numero);

        contador = 0;
        int temp = numero;
        while (temp > 0)
        {
            bits[contador] = temp % 2;
            temp /= 2;
            contador++;
        }

        printf("Binario: ");

        j = contador - 1;

        while (j >= 0)
        {
            printf("%d", bits[j]);
            j--;
        }

        printf("\n");

        printf("Octal: %o\n", numero);
        printf("Hexadecimal: %X\n", numero);

        i++;
    }

    return 0;
}