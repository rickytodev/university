// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 9-Febrero-2026
// 2.6.- Ejercicios para reforzar con ciclos

#include <stdio.h>

int main()
{
    int count = 0, product = 1, n;

    while (n != 0)
    {
        printf("Ingresa un numero: ");
        scanf("%d", &n);

        if (n != 0)
        {
            product *= n;
            count++;
        }
    }

    printf("Cantidad de numeros ingresados: %d\n", count);
    printf("Producto de los numeros: %d\n", product);

    return 0;
}