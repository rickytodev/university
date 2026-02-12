// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de entrega: 11-Febrero-2026
// 2.5.- Otros Ejercicios de Ciclos

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int flag = 1;

    while (flag)
    {
        int ammount, intereses, years;

        printf("-------------------------------------------------------\n\n");

        printf("Ingrese el monto a invertir: ");
        scanf("%d", &ammount);

        if (ammount < 0)
        {
            printf("El monto a invertir no puede ser negativo. Intente de nuevo.\n");
            continue;
        }

        printf("Ingrese la tasa de interes anual (1 al 100): ");
        scanf("%d", &intereses);

        if (intereses < 1 || intereses > 100)
        {
            printf("La tasa de interes anual debe estar entre 1 y 100. Intente de nuevo.\n");
            continue;
        }

        printf("Ingrese el numero de anios: ");
        scanf("%d", &years);

        if (years < 0)
        {
            printf("El numero de anios no puede ser negativo. Intente de nuevo.\n");
            continue;
        }

        int j = 1;
        const float porcentaje = intereses / 100.0f;
        float capital_final = 0;

        while (j <= years)
        {
            capital_final = ammount * powf((1.0f + porcentaje), (float)j);
            printf("Capital obtenido el anio %d: $%.2f\n", j, capital_final);
            j++;
        }

        printf("Capital total obtenido despues de %d anios: $%.2f\n\n", years, capital_final);

        char answer;

        while (1)
        {
            printf("Desea realizar otra operacion? (s/n): ");
            scanf(" %c", &answer);

            const char lAnswer = tolower(answer);

            if (lAnswer == 's')
                break;
            else if (lAnswer == 'n')
            {
                flag = 0;
                break;
            }
            else
                printf("Respuesta no valida. Por favor ingrese 's' para si o 'n' para no.\n");
        }

        printf("\n\n");
    }

    return 0;
}