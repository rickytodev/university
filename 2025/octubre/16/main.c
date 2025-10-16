#include <stdio.h>

int main()
{
  // MARK: EJERCICIO 1

  float answer;

  while (answer != 0)
  {
    float n1, n2;

    printf("Ingresa el primer número: ");
    scanf("%f", &n1);

    printf("Ingresa el segundo número: ");
    scanf("%f", &n2);

    const float op = n1 * n2;

    printf("%.2f x %.2f = %.2f\n\n", n1, n2, op);
    answer = op;
  }

  // MARK: EJERCICIO 2

  int count = 1, total_students;
  int approved = 0, disapproved = 0;

  printf("Ingrese la cantidad de alumnos: ");
  scanf("%d", &total_students);

  while (count <= total_students)
  {
    int n;
    printf("Ingrese la calificación del alumno %d: ", count);
    scanf("%d", &n);

    if (n < 0 || n > 100)
    {
      printf("Calificación no válida, inténtelo de nuevo.\n");
    }
    else
    {
      if (n < 60)
      {
        disapproved++;
      }
      else
      {
        approved++;
      }
      count++;
    }
  }

  printf("En su clase hay %d alumnos, de los cuales %d están aprobados y %d reprobados\n", total_students, approved, disapproved);

  // MARK: EJERCICIO 3

  int plus_answer = 0, number = 2;

  do
  {
    printf("%d es número par\n", number);
    plus_answer += number;
    printf("La suma actual es %d\n\n", plus_answer);
    number += 2;
  } while (number <= 50);

  printf("\nSuma total = %d\n", plus_answer);

  // MARK: EJERCICIO 4

  int count_positive = 1;

  while (count_positive <= 10)
  {
    printf("| %d ", count_positive);
    count_positive++;
  }

  printf("|");

  return 0;
}