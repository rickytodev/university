/*
  1. Muestra todas las letras del abecedario de la Z a la A.

  2. Muestra todas las letras del abecedario de la A a la Z exceptuando las curvas C,O,S,U,Q  -> Utilice la instrucción continue.

  3. Muestre las letras del abecedario tomando como criterio de paro el haber encontrado 3 letras curvas -> Utilice la instrucción break.

  4. Muestre las letras del abecedario dependiendo de un rango establecido por el usuario. El debe decidir en qué letra quiere iniciar y terminar.
*/

#include <stdio.h>

int main()
{
  // ejemplo 1
  printf("Ejemplo 1 - Abecedario invertido\n");
  for (int i = 0; i < 26; i++)
  {
    printf("%c ", 'Z' - i);
  }

  // ejemplo 2
  printf("\n\nEjemplo 2 -  Abecedario sin letras curvas\n");
  for (int i = 0; i < 26; i++)
  {
    const char letter = 'A' + i;

    switch (letter)
    {
    case 'C':
    case 'O':
    case 'S':
    case 'U':
    case 'Q':
      continue;
    default:
      printf("%c ", letter);
      break;
    }
  }

  // ejemplo 3
  printf("\n\nEjemplo 3 - Abecedario con paro en 3 letras curvas\n");
  int count = 0;

  for (int i = 0; i < 26; i++)
  {
    const char letter = 'A' + i;

    if (count == 3)
      continue;

    switch (letter)
    {
    case 'C':
    case 'O':
    case 'S':
    case 'U':
    case 'Q':
      count++;
      continue;
    default:
      printf("%c ", letter);
      break;
    }
  }

  // ejemplo 4
  printf("\n\nEjemplo 4 - Abecedario en rango definido por el usuario\n");

  int render_answer = 0, init = 0, end = 0;

  printf("Los numeros que puedes ingresar son del 1 al 26, donde 1 es A y 26 es Z\n\n");

  while (1)
  {
    if (init > 0 && end > 0 && init > end)
    {
      printf("\n[ERROR] El número de la letra inicial no puede ser mayor al de la letra final\n\n");

      // regresamos los valores a su estado inicial
      init = 0;
      end = 0;
      render_answer = 0;

      continue;
    }

    if (render_answer == 1)
    {
      printf("\n---------------------------------------------------\n");

      for (int i = init - 1; i < end; i++)
      {
        printf("%c ", 'A' + i);
      }

      printf("\n---------------------------------------------------\n\n");

      // regresamos los valores a su estado inicial
      render_answer = 0;
      init = 0;
      end = 0;

      continue;
    }

    if (init > 0)
    {
      printf("Ingresa el número de la letra final: ");
      scanf("%d", &end);

      if (end > 26 || end < 0)
      {
        printf("\n[ERROR] Los datos ingresados no son correctos\n\n");
        end = 0;
      }
      else
      {
        render_answer = 1;
      }
    }
    else
    {
      printf("Ingresa el número de la letra inicial: ");
      scanf("%d", &init);

      if (init > 26 || init < 0)
      {
        printf("\n[ERROR] Los datos ingresados no son correctos\n\n");
        init = 0;
      }
    }
  }

  return 0;
}