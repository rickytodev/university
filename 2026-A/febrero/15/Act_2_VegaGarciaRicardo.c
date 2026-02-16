// Ricardo Jeshua Vega Garcia
// 225976304
// Fecha de creacion: 14/02/2026

#include <stdio.h>

int main()
{
    int i = 1, students = 0, flag = 1, promedio = 0;

    while (students < 3 || students > 10)
    {
        printf("Ingresa la cantidad de estudiantes (3-10):\n$ ");
        scanf("%d", &students);
        while (getchar() != '\n')
            ;

        if (students < 3 || students > 10)
            printf("La cantidad de estudiantes no es valida, ingrese un valor entre 3 y 10\n\n");
    }

    while (i <= students && flag != 2)
    {
        promedio = -1;

        while (promedio < 0 || promedio > 10)
        {
            printf("\nIngresa el promedio del 0 al 10 del estudiante #%d:\n$ ", i);
            scanf("%d", &promedio);
            while (getchar() != '\n')
                ;

            if (promedio < 0 || promedio > 10)
                printf("El promedio no es valido, ingrese un valor entre 0 y 10\n\n");
        }

        if (promedio >= 9)
            printf("El estudiante #%d va Excelente\n", i);
        else if (promedio >= 7)
            printf("El estudiante #%d va Bien\n", i);
        else if (promedio >= 5)
            printf("El estudiante #%d va Regular\n", i);
        else
            printf("El estudiante #%d va Reprobando\n", i);

        i++;

        if (i <= students)
        {
            flag = 0;

            while (flag != 1 && flag != 2)
            {
                printf("\nDesea continuar calificando estudiantes:\n1. Si\n2. No\n$ ");
                scanf("%d", &flag);
                while (getchar() != '\n')
                    ;

                if (flag != 1 && flag != 2)
                    printf("Accion ingresada no correcta\n\n");
            }
        }
    }

    printf("\nPrograma terminado.\n");

    return 0;
}