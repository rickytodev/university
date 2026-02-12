// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// 2.5.- Otros Ejercicios de Ciclos

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tarifa = 150.0, totalPago = 0.0;
    int totalEmpleados = 0, flag = 1;

    while (flag)
    {
        int numEmpleados;

        printf("\nIngrese numero de empleados: ");
        scanf("%d", &numEmpleados);

        for (int i = 0; i < numEmpleados; i++)
        {
            printf("\nEmpleado %d:\n", i + 1);
            float horas = 0.0;

            for (int dia = 1; dia <= 7; dia++)
            {
                float horasxdia;
                printf("  Horas dia %d: ", dia);
                scanf("%f", &horasxdia);
                horas += horasxdia;
            }

            float sueldo = horas * tarifa;
            printf("  Sueldo: $%.2f\n", sueldo);

            totalEmpleados++;
            totalPago += sueldo;
        }

        printf("\n--- RESUMEN ---\n");
        printf("Total empleados: %d\n", totalEmpleados);
        printf("Total pagado: $%.2f\n", totalPago);

        printf("\nflag? (1=Si, 0=No): ");
        scanf("%d", &flag);
    }

    printf("\nPrograma finalizado.\n");
    return 0;
}
