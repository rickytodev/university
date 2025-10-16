/*
  ! Ejercicio 2: Función con paso de parámetros y estructura if-else

  Solicite un año e imprima si es año bisiesto o no. Recuerde que un año es bisiesto en el calendario Gregoriano, si es divisible entre 4 y no divisible entre 100; también se considera que un año es bisiesto si es divisible entre 400.

  ? Nota: El programa debe usar una función con paso de parámetros y sin retorno de valores, que reciba como parámetro el año y calcule si es bisiesto o no con una estructura selectiva. Se debe seguir la estructura base presentada a continuación.
*/
#include <stdio.h>

void year_bissextile(int year)
{
  if (year % 4 == 0 || year % 400 == 0)
  {
    printf("\nEl año %d es bisiesto\n", year);
  }
  else
  {
    printf("\nEl año %d no es bisiesto\n", year);
  }
}

int main()
{
  int year;

  printf("Introduzca el año: ");
  scanf("%d", &year);

  year_bissextile(year);

  return 0;
}