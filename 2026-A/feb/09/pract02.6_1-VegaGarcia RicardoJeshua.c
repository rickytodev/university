// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 4-Febrero-2026
// 2.6.- Ejercicios para reforzar con ciclos

#include <stdio.h>

int main()
{
    int character = 65;

    while (character <= 90)
    {
        const char upperLetter = character;
        const char lowerLetter = character + 32;

        printf("%c%c ", upperLetter, lowerLetter);

        if (character == 78)
            printf("%c%c ", 165, 164);

        character++;
    }

    return 0;
}