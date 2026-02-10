// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 4-Febrero-2026
// 2.6.- Ejercicios para reforzar con ciclos

#include <stdio.h>

int main()
{
    char character;
    int n, count = 1;

    printf("Ingresa un caracter: ");
    scanf("%c", &character);

    printf("Ingresa un numero: ");
    scanf("%d", &n);

    while (count <= n)
    {
        printf("%c ", character);
        count++;
    }

    return 0;
}