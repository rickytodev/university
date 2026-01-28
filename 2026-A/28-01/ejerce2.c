// Alumno: Ricardo Jeshua Vega Garcia
// Código: 225976304
// Nombre Actividad: if-else y anidación if-else
// Actividad: 2.1
// Fecha: 28 / Enero / 2026

#include <stdio.h>

int main()
{
    int day, month;

    printf("Ingresa el dia: ");
    scanf("%d", &day);

    printf("Ingresa el mes: ");
    scanf("%d", &month);

    if (month == 1)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Enero\n", day);
            printf("Estación: Invierno\n");
        }
        else
        {
            printf("Dia invalido para Enero\n");
        }
    }
    else if (month == 2)
    {
        if (day > 0 && day <= 28)
        {
            printf("Fecha: %d de Febrero\n", day);
            printf("Estación: Invierno\n");
        }
        else
        {
            printf("Dia invalido para Febrero\n");
        }
    }
    else if (month == 3)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Marzo\n", day);
            printf("Estación: Primavera\n");
        }
        else
        {
            printf("Dia invalido para Marzo\n");
        }
    }
    else if (month == 4)
    {
        if (day > 0 && day <= 30)
        {
            printf("Fecha: %d de Abril\n", day);
            printf("Estación: Primavera\n");
        }
        else
        {
            printf("Dia invalido para Abril\n");
        }
    }
    else if (month == 5)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Mayo\n", day);
            printf("Estación: Primavera\n");
        }
        else
        {
            printf("Dia invalido para Mayo\n");
        }
    }
    else if (month == 6)
    {
        if (day > 0 && day <= 30)
        {
            printf("Fecha: %d de Junio\n", day);
            printf("Estación: Verano\n");
        }
        else
        {
            printf("Dia invalido para Junio\n");
        }
    }
    else if (month == 7)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Julio\n", day);
            printf("Estación: Verano\n");
        }
        else
        {
            printf("Dia invalido para Julio\n");
        }
    }
    else if (month == 8)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Agosto\n", day);
            printf("Estación: Verano\n");
        }
        else
        {
            printf("Dia invalido para Agosto\n");
        }
    }
    else if (month == 9)
    {
        if (day > 0 && day <= 30)
        {
            printf("Fecha: %d de Septiembre\n", day);
            printf("Estación: Otoño\n");
        }
        else
        {
            printf("Dia invalido para Septiembre\n");
        }
    }
    else if (month == 10)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Octubre\n", day);
            printf("Estación: Otoño\n");
        }
        else
        {
            printf("Dia invalido para Octubre\n");
        }
    }
    else if (month == 11)
    {
        if (day > 0 && day <= 30)
        {
            printf("Fecha: %d de Noviembre\n", day);
            printf("Estación: Otoño\n");
        }
        else
        {
            printf("Dia invalido para Noviembre\n");
        }
    }
    else if (month == 12)
    {
        if (day > 0 && day <= 31)
        {
            printf("Fecha: %d de Diciembre\n", day);
            printf("Estación: Invierno\n");
        }
        else
        {
            printf("Dia invalido para Diciembre\n");
        }
    }
    else
    {
        printf("Mes invalido\n");
    }

    return 0;
}