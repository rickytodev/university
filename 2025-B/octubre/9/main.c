#include <stdio.h>

int main()
{
  printf("\n\n--- Ejercicio 1 ---\n");

  int years_old, credential;

  printf("Ingresa tu edad: ");
  scanf("%d", &years_old);

  printf("Cuentas con tu credencial? \n[1] Si \n[2] No \n");
  scanf("%d", &credential);

  if (years_old >= 18 && credential == 1)
  {
    printf("Puedes votar");
  }

  printf("\n\n--- Ejercicio 2 ---\n");

  int int_number;

  printf("Ingresa un numero entero: ");
  scanf("%d", &int_number);

  if (int_number % 2 == 0)
  {
    printf("El numero es par");
  }
  else
  {
    printf("El numero es impar");
  }

  printf("\n\n--- Ejercicio 3 ---\n");

  int n_week;

  printf("Ingresa un numero del 1 al 7: ");
  scanf("%d", &n_week);

  switch (n_week)
  {
  case 1:
    printf("[L] Lunes");
    break;
  case 2:
    printf("[Ma] Martes");
    break;
  case 3:
    printf("[Mi] Miercoles");
    break;
  case 4:
    printf("[J] Jueves");
    break;
  case 5:
    printf("[V] Viernes");
    break;
  case 6:
    printf("[S] Sabado");
    break;
  case 7:
    printf("[D] Domingo");
    break;
  default:
    printf("Numero de semana invalido");
    break;
  }

  printf("\n\n--- Ejercicio 4 ---\n");

  int score, finish_score;

  printf("Ingresa tu calificacion de examen: ");
  scanf("%d", &score);

  printf("Ingresa tu promedio de bachillerato: ");
  scanf("%d", &finish_score);

  if (((score + finish_score) / 2) >= 85)
  {
    printf("Aspirante seleccionado");
  }
  else
  {
    printf("Aspirante no seleccionado");
  }

  printf("\n\n--- Ejercicio 5 ---\n");

  int amount, student;

  printf("Eres estudiante? \n[1] Si \n[2] No \n");
  scanf("%d", &student);

  const int price = 500;
  const int discount = price - (price * 0.35); // <- descuento del 35%

  if (student == 1)
  {
    printf("Inscripcion: $%d y Mensualidad: $%d", discount, discount * 30);
  }
  else
  {
    printf("Inscripcion: $%d y Mensualidad: $%d", price, price * 30);
  }

  printf("\n\n--- Ejercicio 6 ---\n");

  int month;

  printf("Ingresa un numero del 1 al 12: ");
  scanf("%d", &month);

  switch (month)
  {
  case 1:
    printf("El mes de Enero tiene 31 dias");
    break;
  case 2:
    printf("El mes de Febrero tiene 28 dias");
    break;
  case 3:
    printf("El mes de Marzo tiene 31 dias");
    break;
  case 4:
    printf("El mes de Abril tiene 30 dias");
    break;
  case 5:
    printf("El mes de Mayo tiene 31 dias");
    break;
  case 6:
    printf("El mes de Junio tiene 30 dias");
    break;
  case 7:
    printf("El mes de Julio tiene 31 dias");
    break;
  case 8:
    printf("El mes de Agosto tiene 31 dias");
    break;
  case 9:
    printf("El mes de Septiembre tiene 30 dias");
    break;
  case 10:
    printf("El mes de Octubre tiene 31 dias");
    break;
  case 11:
    printf("El mes de Noviembre tiene 30 dias");
    break;
  case 12:
    printf("El mes de Diciembre tiene 31 dias");
    break;
  default:
    printf("Numero de mes invalido");
    break;
  }

  return 0;
}