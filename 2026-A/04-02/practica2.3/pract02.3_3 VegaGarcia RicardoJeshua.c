// Programación Estructurada
// D07
// Ricardo Jeshua Vega Garcia
// 225976304
// Pactica 2.3 - Ciclo do While - Ejercicio 3
// Fecha de entrega: 4-Febrero-2026

#include <stdio.h>

int main()
{
    int count = 1;
    const int n = 5;

    do
    {
        printf(" %d ", count * n);
        count++;
    } while (count < 1001);
}