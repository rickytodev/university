// Nombre: Ricardo Jeshua Vega Garcia
// Codigo: 225976394
// Materia: Programación Estructurada
// Seccion: D07
// Practica: 2.3 - Ciclo do While - Ejercicio 2
// Fecha entrega: 4 de febrero del 2026

#include <stdio.h>

int main()
{
    int n1, n2, option;

    do
    {
        printf("MENU\n1.- suma\n2.- resta\n3.- multiplicación\n4.- división\n5.- Salir\n");
        printf("\nSelecciona una opccion: ");
        scanf("%d", &option);

        printf("Ingresa el primer número: ");
        scanf("%d", &n1);

        printf("Ingresa el segundo número: ");
        scanf("%d", &n2);

        if (option == 0)
            break;

        switch (option)
        {
        case 1:
            printf("La suma es: %d\n\n", n1 + n2);
            break;
        case 2:
            printf("La resta es: %d\n\n", n1 - n2);
            break;
        case 3:
            printf("La multiplicación es: %d\n\n", n1 * n2);
            break;
        case 4:
            printf("La división es: %.2f\n\n", (float)n1 / n2);
            break;
        default:
            printf("Valor no valido\n\n");
            break;
        }

    } while (option != 5);

    return 0;
}