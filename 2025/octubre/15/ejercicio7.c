/*
  ! Ejercicio 7: if - else

  Solicitarle al usuario que ingrese 5 números e imprimir el max y el min de ellos. Utilice la estructura if - else para resolverlo.

  ? Nota: Recuerde que puede manejar una sobreescritura de variable, para actualizar cual valor es el min y cual el max. NO utilizar ninguna función de ordenamiento (MIN, MAX, etc.), ni otras estructuras (for, while, etc.), ni tipos de dato ordenados (vectores, matrices, etc.).
*/

#include <stdio.h>

int main()
{
  int n1, n2, n3, n4, n5, min, max;

  printf("Ingresa el primer número: ");
  scanf("%d", &n1);

  printf("Ingresa el segundo número: ");
  scanf("%d", &n2);

  printf("Ingresa el tercer número: ");
  scanf("%d", &n3);

  printf("Ingresa el cuarto número: ");
  scanf("%d", &n4);

  printf("Ingresa el quinto número: ");
  scanf("%d", &n5);

  max = n1;
  min = n1;

  if (n2 > max)
    max = n2;
  else
    min = n2 < min ? n2 : min;

  if (n3 > max)
    max = n3;
  else
    min = n3 < min ? n3 : min;

  if (n4 > max)
    max = n4;
  else
    min = n4 < min ? n4 : min;

  if (n5 > max)
    max = n5;
  else
    min = n5 < min ? n5 : min;

  printf("\nEl número mayor es %d y el menor es %d\n", max, min);

  return 0;
}