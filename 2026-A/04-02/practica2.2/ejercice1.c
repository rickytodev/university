// Ricardo Jeshua Vega Garcia
// 225976304
// Pactica 2.2 - Ciclo While - Ejercicio 1

#include <stdio.h>

int main()
{
    int flag = 0, select, count;

    while (!flag)
    {
        printf("Ejercicio Ciclo While\n");
        printf("1.Múltiplos de 2\n2.Múltiplos de 3\n3.Múltiplos de 5\n4.Multiplos de 7\n5.Múltiplos de 11\n6.Salir\n");

        printf("Seleccione una opción: ");
        scanf("%d", &select);

        count = 1;

        switch (select)
        {
        case 1:
            while (count <= 100)
            {
                printf(" %d ", count * 2);
                count++;
            }
            break;
        case 2:
            while (count <= 100)
            {
                printf(" %d ", count * 3);
                count++;
            }
            break;
        case 3:
            while (count <= 100)
            {
                printf(" %d ", count * 5);
                count++;
            }
            break;
        case 4:
            while (count <= 100)
            {
                printf(" %d ", count * 7);
                count++;
            }
            break;
        case 5:
            while (count <= 100)
            {
                printf(" %d ", count * 11);
                count++;
            }
            break;

        case 6:
            flag = 1;
            break;

        default:
            printf("Opción no válida\n");
            break;
        }
    }

    return 0;
}
