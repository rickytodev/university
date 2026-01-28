#include <stdio.h>

void space(int length, char symbol)
{
  if (length == 0)
    return;

  for (int i = 0; i < length; i++)
  {
    printf("%c", symbol);
  }
}

void tree(int length, int invert)
{
  for (int i = 0; i < length; i++)
  {
    space(invert == 1 ? i : length - i - 1, ' ');
    for (int j = 0; invert == 1 ? j < length - i : j <= i; j++)
      printf("%c ", '*');
    if (i + 1 != length)
      printf("\n");
  }
}

int main()
{
  while (1)
  {
    int length, invert;

    printf("\nIngresa la altura del árbol: ");
    scanf("%d", &length);

    printf("\n¿Invertido? (0: No, 1: Sí, 2: Los dos): ");
    scanf("%d", &invert);

    if (length <= 0 || (invert != 0 && invert != 1 && invert != 2))
    {
      printf("\n[ERROR] Dato no valido\n");
      continue;
    }

    printf("\n");

    if (invert == 2)
    {
      tree(length, 1);
      printf("\n");
      tree(length, 0);
    }
    else
      tree(length, invert);

    printf("\n");
  }

  return 0;
}