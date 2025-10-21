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

  int finish;

  while (finish)
  {

    int init, end;

    printf("\nIngresa el número de la letra inicial (A=1, B=2, ..., Z=26): ");
    scanf("%d", &init);

    if (init > 26 || init < 0)
    {
      printf("Los datos ingresados no son correctos\n");
      continue;
    }

    printf("Ingresa el número de la letra final (A=1, B=2, ..., Z=26): ");
    scanf("%d", &end);

    if (end > 26 || end < 0)
    {
      printf("Los datos ingresados no son correctos\n");
      continue;
    }

    if (init > end)
    {
      printf("No se puede realizar el conteo, la letra inicial es mayor que la letra final\n");
      continue;
    }

    for (int i = init - 1; i < end; i++)
    {
      printf("%c ", 'A' + i);
    }

    printf("\n");
  }

  return 0;
}