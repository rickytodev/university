/*
  ! Ejercicio 6: Anidamiento

  Leer un número entero e imprimir si es: Cero, positivo o negativo; Par o impar (Cuando sea positivo); Múltiplo de 7 o no múltiplo de 7 (Cuando sea impar).

  ? Nota: Para resolver este ejercicio haga uso de anidamiento de estructuras selectivas.
*/

#include <stdio.h>

int main()
{
  int n;

  printf("Ingresa un número entero: ");
  scanf("%d", &n);

  if (n > 0)
  {
    if (n % 2 == 0)
    {
      if (n % 7 == 0)
      {
        printf("%d es un número positivo, es par y es múltiplo de 7", n);
      }
      else
      {
        printf("%d es un número positivo, es par y no es múltiplo de 7", n);
      }
    }
    else
    {
      if (n % 7 == 0)
      {
        printf("%d es un número positivo, es impar y es múltiplo de 7", n);
      }
      else
      {
        printf("%d es un número positivo, es impar y no es múltiplo de 7", n);
      }
    }
  }
  else
  {
    if (n % 2 == 0)
    {
      if (n % 7 == 0)
      {
        printf("%d es un número negativo, es par y es múltiplo de 7", n);
      }
      else
      {
        printf("%d es un número negativo, es par y no es múltiplo de 7", n);
      }
    }
    else
    {
      if (n % 7 == 0)
      {
        printf("%d es un número negativo, es impar y es múltiplo de 7", n);
      }
      else
      {
        printf("%d es un número negativo, es impar y no es múltiplo de 7", n);
      }
    }
  }

  return 0;
}