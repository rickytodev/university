#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  printf("Ejercicio 1\n");

  for (int i = 0; i < 10; i++)
  {
    int random = rand() % 101;
    printf("Número aleatorio %d: %d\n", i + 1, random);
  }

  printf("\n\nEjercicio 2\n");

  srand(time(NULL));

  for (int i = 0; i < 10; i++)
  {
    int random = rand() % 101;
    printf("El numero %d es %s\n", random, random % 2 == 0 ? "Par" : "Impar");
  }

  printf("\n\nEjercicio 3\n");

  int n;

  printf("Ingrese un numero entero: ");
  scanf("%d", &n);

  const int operation = n == 0 ? n - 1 : n > 0 ? n * 2
                                               : n + 3;

  printf("%d", operation);

  return 0;
}