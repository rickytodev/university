/*
  ! Ejercicio 3: if - else (anidado)

  Realice un programa que solicite la edad (Dato de tipo entero) de una persona y determine si es niño, adolescente, adulto o anciano, según el siguiente rango de edades:

    * 0 a 12 años imprimir Es niño
    * 13 a 17 años imprimir Es adolescente
    * 18 a 80 años imprimir Es adulto
    * Mayor que 80 imprimir Es anciano

  ? Nota: Utilice una estructura if - else anidada para realizar este ejercicio. Tome en cuenta los casos en los que el usuario puede ingresar un dato que no es válido (edad negativa -5 años o edad muy grande 200 años).
*/

#include <stdio.h>

int main()
{
  int age;

  printf("Ingresa tu edad: ");
  scanf("%d", &age);

  if (age >= 0)
  {
    if (age <= 12)
    {
      printf("\nEs niño");
    }
    else
    {
      if (age <= 17)
      {
        printf("\nEs adolescente");
      }
      else
      {
        if (age <= 80)
        {
          printf("\nEs adulto");
        }
        else
        {
          if (age <= 100)
          {
            printf("\nEs anciano");
          }
          else
          {
            printf("\nEdad no válida");
          }
        }
      }
    }
  }
  else
  {
    printf("\nEdad no válida");
  }

  return 0;
}