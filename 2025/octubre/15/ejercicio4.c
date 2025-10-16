/*
  ! Ejercicio 4: Función sin paso de parámetros y estructura switch - case

  Realice el siguiente menú con la estructura switch - case que le permita al usuario convertir un valor de temperatura:

    * 1. De Celsius °C a Farenheit °F
    * 2. De Celsius °C a Kelvin °K
    * 3. De Farenheit °F a Celsius °C
    * 4. De Kelvin °K a Celsius °C

  Por cada opción defina una función sin paso de parámetros que solicite la temperatura e imprima la respectiva conversión. Recuerde que las conversiones se dan de la siguiente forma:

    * °C = (°F − 32) × 5 / 9
    * °F = (°C × 9 / 5) + 32
    * °C = °K − 273.15
    * °K = °C + 273.15
*/

#include <stdio.h>

void celsius_farenheit()
{
  int n;
  printf("Ingresa los °C: ");
  scanf("%d", &n);
  const float op = (n * 9 / 5) + 32;
  printf("%d °C equivalen a %.2f °F\n", n, op);
}

void celsius_kelvin()
{
  int n;
  printf("Ingresa los °C: ");
  scanf("%d", &n);
  const float op = n + 273.15;
  printf("%d °C equivalen a %.2f °K\n", n, op);
}

void farenheit_celsius()
{
  int n;
  printf("Ingresa los °F: ");
  scanf("%d", &n);
  const float op = (n - 32) * 5 / 9;
  printf("%d °F equivalen a %.2f °C\n", n, op);
}

void kelvin_celsius()
{
  int n;
  printf("Ingresa los °K: ");
  scanf("%d", &n);
  const float op = n - 273.15;
  printf("%d °K equivalen a %.2f °C\n", n, op);
}

int main()
{
  printf("¡Bienvenido!\n\n"
         "1. De Celsius °C a Farenheit °F\n"
         "2. De Celsius °C a Kelvin °K\n"
         "3. De Farenheit °F a Celsius °C\n"
         "4. De Kelvin °K a Celsius °C\n");

  int option;

  printf("\nSelecciona una opción: ");
  scanf("%d", &option);
  printf("\n");

  switch (option)
  {
  case 1:
    celsius_farenheit();
    break;
  case 2:
    celsius_kelvin();
    break;
  case 3:
    farenheit_celsius();
    break;
  case 4:
    kelvin_celsius();
    break;
  default:
    printf("[ERROR] Opción no existente");
    break;
  }

  return 0;
}