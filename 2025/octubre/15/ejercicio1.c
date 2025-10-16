/*
  ! Ejercicio 1: if - else

  Solicite al usuario que ingrese 2 números e imprimirlos en forma ascendente y descendente. Utilice una sola estructura if - else para resolverlo.
*/

#include <stdio.h>

int main()
{
  int n1, n2;

  printf("Ingresa un número entero: ");
  scanf("%d", &n1);

  printf("Ingresa otro número entero: ");
  scanf("%d", &n2);

  if (n1 < n2)
  {
    printf("\nNúmeros en orden ascendente: %d, %d\n", n1, n2);
    printf("Números en orden descendente: %d, %d\n", n2, n1);
  }
  else
  {
    printf("\nNúmeros en orden ascendente: %d, %d\n", n2, n1);
    printf("Números en orden descendente: %d, %d\n", n1, n2);
  }

  return 0;
}