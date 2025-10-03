/*
  Realice un programa que le solicite al usuario una cantidad de pesos y los convierta a Euros. Se tomará la equivalencia de 1 Euro = $21.45 pesos. Despliegue en pantalla los resultados.
  El programa debe usar una función con paso de parámetros y con retorno de valores, se debe seguir la estructura base presentada a continuación.
*/

#include <stdio.h>

int proceso(int n)
{
  // definimos el valor del euro
  const float euros = 21.45;

  // realizamos la operación
  const float operation = n * euros;

  // retornamos el valor
  return operation;
}

int main()
{
  // definimos la variables para guardar los pesos a convertir
  int money;

  // solicitamos al usuario la cantidad de pesos a convertir
  printf("Cantidad de pesos: $");
  scanf("%d", &money);

  // imprimimos el resultado
  printf("$%d, equivalen a: €%.2f\n", money, proceso(money));

  // terminamos la función main
  return 0;
}