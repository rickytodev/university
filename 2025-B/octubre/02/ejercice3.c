/*
Realice un programa que determine cuánto dinero ahorra una persona en un año si considera que cada semana ahorra 15% de su sueldo (considere que un año tiene 52 semanas). Debe de solicitarle al usuario cuanto ganá por semana y desplegar en pantalla el ahorro total que tendrá al año si ahorra el 15% de su salario semanal. EI programa debe usar una función sin paso de parámetros y con retorno de valores, se debe seguir la estructura base presentada a continuación.
*/

#include <stdio.h>

int proceso()
{
  // declara la variable sueldo
  int sueldo;

  // declaramos el total de las semanas del año
  const int weeks_years = 52;

  // pedimos al usuario su sueldo semanal
  printf("Ingrese su sueldo semanal: $");
  scanf("%d", &sueldo);

  // definimos cuanto es el ahorro
  const float ahorro = 0.15;

  // calculamos el ahorro total
  int total_ahorro = sueldo * ahorro * weeks_years;

  // retornamos el total del ahorro
  return total_ahorro;
}

int main()
{
  // desplegamos el resultado
  printf("Si ahorra un 15%% de su salario semanal durante un anio tendra ahorrado: $%d pesos\n", proceso());

  // finalizamos el programa
  return 0;
}