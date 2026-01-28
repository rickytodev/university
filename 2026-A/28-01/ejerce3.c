// Alumno: Ricardo Jeshua Vega Garcia
// Código: 225976304
// Nombre Actividad: if-else y anidación if-else
// Actividad: 2.1
// Fecha: 28 / Enero / 2026

#include <stdio.h>

int main()
{
    int m1, m2, m3, m4, m5;

    printf("Ingresa la calificación de Calculo: ");
    scanf("%d", &m1);

    printf("Ingresa la calificación de Programación: ");
    scanf("%d", &m2);

    printf("Ingresa la calificación de Algebra: ");
    scanf("%d", &m3);

    printf("Ingresa la calificación de Matemáticas Discretas: ");
    scanf("%d", &m4);

    printf("Ingresa la calificación de Física: ");
    scanf("%d", &m5);

    if (m1 < 0 || m1 > 100 ||
        m2 < 0 || m2 > 100 ||
        m3 < 0 || m3 > 100 ||
        m4 < 0 || m4 > 100 ||
        m5 < 0 || m5 > 100)
    {
        printf("Error: Las calificaciones deben estar entre 0 y 100.\n");
        return 0;
    }

    const int promedio = (m1 + m2 + m3 + m4 + m5) / 5;

    if (promedio < 60)
    {
        printf("Reprobaste el semestre, tu promedio es de %d/100", promedio);
    }

    if (promedio >= 60 && promedio < 79)
    {
        printf("Tu promedio es regular, tu promedio es de %d/100", promedio);
    }

    if (promedio >= 80 && promedio <= 90)
    {
        printf("Tu promedio es bueno, puedes conseguir una beca, tu promedio es de %d/100", promedio);
    }

    if (promedio > 90)
    {
        printf("Sigue así y podrás salir con excelencia, tu promedio es de %d/100", promedio);
    }

    return 0;
}