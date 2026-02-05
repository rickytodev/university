// Nombre: Ricardo Jeshua Vega Garcia
// Codigo: 225976394
// Materia: Programación Estructurada
// Seccion: D07
// Practica: 2.3 - Ciclo do While - Ejercicio 4
// Fecha entrega: 4 de febrero del 2026

#include <stdio.h>

int main()
{
    int N;
    int numeros[100];
    int i = 0, j;
    float suma = 0;
    float media;
    int moda = 0;
    int maxFrecuencia = 0;

    printf("Cuantos numeros desea ingresar: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("El numero de elementos debe ser mayor que cero.\n");
        return 1;
    }

    do
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
        i++;
    } while (i < N);

    media = suma / N;

    i = 0;
    do
    {
        int frecuencia = 0;
        j = 0;

        do
        {
            if (numeros[i] == numeros[j])
                frecuencia++;
            j++;
        } while (j < N);

        if (frecuencia > maxFrecuencia)
        {
            maxFrecuencia = frecuencia;
            moda = numeros[i];
        }

        i++;
    } while (i < N);

    printf("\nMedia: %.2f\n", media);
    if (maxFrecuencia > 1)
        printf("Moda: %d\n", moda);
    else
        printf("No hay moda\n");

    return 0;
}
