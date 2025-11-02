#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void repeat(int length, char symbol)
{
  if (length == 0)
    return;
  for (int i = 0; i < length; i++)
    printf("%c", symbol);
}

void title(char *text)
{
  printf("\n");
  repeat(20, '-');
  printf(" %s ", text);
  repeat(20, '-');
  printf("\n");
}

void ejerce1()
{
  int n;

  printf("Ingrese un numero entero: ");
  scanf("%d", &n);

  while (n > 0)
  {
    printf("%d\n", n);
    n -= 2;
  }
}

void ejerce2()
{
  int n;

  while (1)
  {
    int answer = 1, count = 1;

    printf("Ingrese el numero del cual se quiere saber su factorial: ");
    scanf("%d", &n);

    if (n < 0)
    {
      printf("\nNo puedes ingresar numeros negativos\n");
      continue;
    }

    if (n == 0)
    {
      printf("\nEl factorial de %d es: %d", n, 1);
    }
    else
    {
      while (count <= 5)
      {
        answer *= count;
        count++;
      }
      printf("\nEl factorial de %d es: %d", n, answer);
    }

    printf("\n");
    break;
  }
}

void ejerce3()
{
  int n;

  while (1)
  {
    printf("Ingrese un numero entero: ");
    scanf("%d", &n);

    if (n < 0)
    {
      printf("\nNo se aceptan numeros negativos\n");
      continue;
    }

    printf("\nLa conjetura ULAM para el numero %d es: ", n);

    while (n >= 1)
    {
      printf("\n%d", n);

      if (n == 1)
        break;

      if (n % 2 == 0)
      {
        n /= 2;
        continue;
      }
      n = n * 3 + 1;
    }

    printf("\n");
    break;
  }
}

void ejerce4()
{
  int n, d = 1, answer = 0;

  printf("Ingresa un numero entero: ");
  scanf("%d", &n);

  while (d <= n)
  {
    if (n % d == 0)
    {
      answer++;
      if (d == n)
        break;
    }
    d++;
  }

  if (answer == 2)
  {
    printf("%d es un numero primo", n);
  }
  else
  {
    printf("%d no es numero primo", n);
  }
}

void ejerce5()
{
  int n, i = 0, answer = 0, before = 0, after = 1;

  printf("Ingresa un numero entero: ");
  scanf("%d", &n);

  while (i < n)
  {
    if (i <= 1)
      printf("\n%d", i);
    else
    {
      answer = before + after;
      printf("\n%d", answer);
      before = after;
      after = answer;
    }
    i++;
  }
}

void ejerce6()
{
  int num, cont = 0, n;

  printf("Ingresa un numero entero: ");
  scanf("%d", &num);

  n = num;

  if (n == 0)
    cont = 1;
  else
    do
    {
      n /= 10;
      cont++;
    } while (n != 0);

  printf("El numero %d tiene %d digito%s.\n", num, cont, cont > 1 ? "s" : "");
}

void ejerce7()
{
  srand(time(NULL));
  int n, c = 1;

  const int m = rand() % 20 + 1;

  do
  {
    if (c == 6)
    {
      printf("Suerte para la proxima\n");
      break;
    }

    printf("Ingresa un numero entre 1 y 20: ");
    scanf("%d", &n);

    if (n == m)
    {
      printf("Felicidades lo lograste en %d intentos!\n", c);
      break;
    }
    printf("Tu numero es %s que el mio\n", n < m ? "menor" : "mayor");
    printf("Vuelve a intentarlo\n");

    c++;
  } while (c <= 6);
}

void ejerce9()
{
  int numero, digito;
  int pares = 0, impares = 0;

  printf("Ingresa un numero entero: ");
  scanf("%d", &numero);

  if (numero < 0)
    numero -= numero;

  do
  {
    digito = numero % 10;
    if (digito % 2 == 0)
      pares++;
    else
      impares++;
    numero /= 10;
  } while (numero > 0);

  printf("El numero tiene %d digitos pares y %d impares.\n", pares, impares);
}

void ejerce8()
{
  int a, b, div = 1, m, answer;

  printf("Ingresa el valor de [a]: ");
  scanf("%d", &a);

  printf("Ingresa el valor de [b]: ");
  scanf("%d", &b);

  if (a < b)
    m = b;
  else
    m = a;

  do
  {
    if (a % div == 0 && b % div == 0)
      answer = div;
    div++;
  } while (div < m);

  printf("El MCD entre %d y %d es: %d", a, b, answer);
}

void ejerce10()
{
  int n, div = 1;

  printf("Ingresa un numero entero: ");
  scanf("%d", &n);

  printf("\nLos divisores de %d son: \n", n);

  do
  {
    if (n % div == 0)
      printf("%d ", div);
    div++;
  } while (div <= n);
}

void n_prims(int init, int end)
{
  int count = 0, n = 0;

  for (int i = init; i < end; i++)
  {
    for (int j = 1; j < i + 1; j++)
    {
      if (i % j == 0)
      {
        count++;
      }
    }

    if (n == 20)
      break;

    if (count == 2)
    {
      printf("%s%d", n > 0 ? ", " : "", i);
      n++;
    }

    count = 0;
  }
}

void ejerce11()
{
  printf("Los primeros 20 numeros primos son: \n\n");
  n_prims(0, 200);
}

void ejerce12()
{
  int a, b;

  printf("Ingrese el primer numero: ");
  scanf("%d", &a);

  printf("Ingrese el segundo numero: ");
  scanf("%d", &b);

  printf("\nLos numeros primos entre %d y %d son: \n\n", a, b);
  n_prims(a, b);
}

void ejerce13()
{
  srand(time(NULL));
  int plus = 0, approved = 0, reproved = 0, max = 0, min = 0;

  for (int i = 0; i < 24; i++)
  {
    const int n = rand() % 100;

    plus += n;

    printf("%s%d|", i == 0 ? "|" : "", n);

    if (n > 60)
      approved++;
    else
      reproved++;

    if (max == 0 && min == 0)
    {
      max = n;
      min = n;
    }
    else
    {
      if (n > max)
        max = n;
      if (n < min)
        min = n;
    }
  }

  printf("\n\nEn el grupo de 24 alumnos se tiene que: \n\n");
  printf("La calificacion promedio del grupo fue de %d", plus / 24);
  printf("\nHay %d alumnos aprobados y %d reprobados", approved, reproved);
  printf("\nLa calificacion mas alta fue %d y la menor %d", max, min);
}

void ejerce14()
{
  int n;

  printf("Ingresa la cantidad de filas: ");
  scanf("%d", &n);

  printf("\nEl triangulo rectangulo de %d filas\n\n", n);

  for (int i = 1; i <= n; i++)
  {
    repeat(n - i, ' ');
    for (int j = 1; j < i + 1; j++)
    {
      printf("%d ", j);
    }
    printf("\n");
  }
}

void ejerce15()
{
  int n, answer = 0, count = 0;

  printf("Ingrese la cantidad de terminos: ");
  scanf("%d", &n);

  printf("\nLa serie para %d terminos es:\n\n", n);
  for (int i = 0; i < n; i++)
  {
    const int op = count * 10 + 1;
    count = op;
    answer += count;
    printf("%s%d", i > 0 ? " + " : "", op);
  }

  printf("\n\nLa suma total es: %d", answer);
}

int main()
{
  title("Ejercicio 1");
  ejerce1();

  title("Ejercicio 2");
  ejerce2();

  title("Ejercicio 3");
  ejerce3();

  title("Ejercicio 4");
  ejerce4();

  title("Ejercicio 5");
  ejerce5();

  title("Ejercicio 6");
  ejerce6();

  title("Ejercicio 7");
  ejerce7();

  title("Ejercicio 8");
  ejerce8();

  title("Ejercicio 9");
  ejerce9();

  title("Ejercicio 10");
  ejerce10();

  title("Ejercicio 11");
  ejerce11();

  title("Ejercicio 12");
  ejerce12();

  title("Ejercicio 13");
  ejerce13();

  title("Ejercicio 14");
  ejerce14();

  title("Ejercicio 15");
  ejerce15();

  return 0;
}