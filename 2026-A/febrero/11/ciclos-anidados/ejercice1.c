// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// Ciclos Anidados para Reforzar

#include <stdio.h>

int main()
{
    int n, n_tables, current_table = 0, current_multiplier = 1;

    printf("Cuantas tablas de multiplicar quieres? ");
    scanf("%d", &n_tables);

    printf("Hasta que numero quieres multiplicar las tablas? ");
    scanf("%d", &n);

    printf("\n\n");

    while (current_table < n_tables)
    {
        int count_multiplier = 1;
        while (count_multiplier <= n)
        {
            printf("%d x %d = %d\n", current_multiplier, count_multiplier, current_multiplier * count_multiplier);
            count_multiplier++;
        }

        current_multiplier++;
        current_table++;
        printf("\n\n");
    }

    return 0;
}