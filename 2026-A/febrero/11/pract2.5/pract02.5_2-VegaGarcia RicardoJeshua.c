// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// 2.5.- Otros Ejercicios de Ciclos

#include <stdio.h>
#include <ctype.h>

#define MAX_CHARTERS 100

int main()
{
    int repeat = 0, i = 0;
    char frase[MAX_CHARTERS], caracter;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);

    while (i < MAX_CHARTERS)
    {
        if (tolower(caracter) == tolower(frase[i]))
            repeat++;
        i++;
    }

    printf("El caracter '%c' aparece %d veces en la frase.\n", caracter, repeat);

    return 0;
}