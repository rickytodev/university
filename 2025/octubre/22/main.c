#include <stdio.h>

int main()
{

  // ejercicio 1
  printf("Ejercicio 1\n\n");

  /*
    Imprimir los números del uno al cien excepto los múltiplos de 7
  */

  for (int i = 0; i < 101; i++)
  {
    if (i % 7 == 0)
      continue;
    printf("%d ", i);
  }

  // ejercicio 2
  printf("\n\nEjercicio 2\n\n");

  /*
    Leer un número entero positivo y averiguar si es perfecto. Un número es perfecto cuando es igual a la suma de sus divisores excepto él mismo (Primeros tres números perfectos: 6, 28, 496).
  */

  int n, suma = 0;

  printf("Ingrese un número entero positivo: ");
  scanf("%d", &n);

  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      suma += i;
    }
  }

  if (suma == n)
  {
    printf("\nEl número %d es perfecto.\n", n);
  }
  else
  {
    printf("\nEl número %d no es perfecto.\n", n);
  }

  // ejercicio 3

  printf("\nEjercicio 3\n\n");

  /*
    Imprimir el abecedario en forma inversa es decir de la ‘z’ a la ‘a’ y luego vaya eliminando de una letra en una empezando por la ‘z’ hasta que quede la ‘a’: (Anidamiento de for)
  */

  for (int i = 0; i < 26; i++)
  {
    for (int j = 26 - i; j > 0; j--)
    {
      printf("%c ", 'a' + j - 1);
    }
    printf("\n");
  }

  return 0;
}