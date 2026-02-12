// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// Ciclos Anidados para Reforzar

#include <stdio.h>

int main()
{
    int n = 0;

    while (n < 26)
    {
        char character = 'A' + n;
        while (character <= 'Z')
        {
            printf(" %c%c ", character, character + 32);
            character++;
        }
        printf("\n");
        n++;
    }

    n = 0;

    while (n < 26)
    {
        char character = 'Z';
        int count = 0;

        while (count <= n)
        {
            printf(" %c%c ", character, character + 32);
            character--;
            count++;
        }
        printf("\n");
        n++;
    }

    return 0;
}