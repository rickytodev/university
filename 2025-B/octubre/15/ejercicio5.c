/*
  ! Ejercicio 5: switch - case

  Realice un programa que lea un número entero (1-6) obtenido al lanzar un dado de seis caras e imprimir el número en letras de la cara opuesta. Recuerde que en las caras opuestas de un dado de seis caras están los números: 1-6, 2-5 y 3-4. Si el número del dado capturado es menor que 1 o mayor que 6, se mostrará el siguiente mensaje: “Un DADO no tiene ese número”. Utilizar una estructura switch - case para resolver el ejercicio.
*/

#include <stdio.h>

int main()
{
  int face;

  printf("Ingresa una cara del dado: ");
  scanf("%d", &face);

  switch (face)
  {
  case 1:
    printf("El número de la cara opuesta del dado es: 6");
    break;
  case 2:
    printf("El número de la cara opuesta del dado es: 5");
    break;
  case 3:
    printf("El número de la cara opuesta del dado es: 4");
    break;
  case 4:
    printf("El número de la cara opuesta del dado es: 3");
    break;
  case 5:
    printf("El número de la cara opuesta del dado es: 2");
    break;
  case 6:
    printf("El número de la cara opuesta del dado es: 1");
    break;
  default:
    printf("Un DADO no tiene ese número");
    break;
  }

  return 0;
}