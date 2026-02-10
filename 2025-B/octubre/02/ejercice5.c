/*
Tomando como base el ejercicio de la Actividad 10 y el ejercicio 6 de la Práctica 1. Realice un algoritmo que le solicite al usuario la cantidad de pesos y determine a cuantos billetes de 500, 200, 100, 50, 20 pesos y a cuantas monedas de 10, 5, 2, y 1, peso(s) equivale esa cantidad. El programa debe seguir la estructura base para el manejo de funciones presentada a continuación. No se puede hacer uso de ninguna estructura de control o tipo de dato estructurado, ni punteros.
*/

#include <stdio.h>

// tengo que usar el puntero de type para poder hacer que la función sea reutilizable y nada mas pasar el tipo de denominación
void salida(int total, int denomination, char type[50])
{
  printf("%d %s(s) de %d pesos\n", total, type, denomination);
}

void proceso(int n)
{
  // definimos la variable de residuo
  int remainder = n;
  // obtenemos los billetes
  const int b500 = remainder / 500;
  remainder %= 500;
  const int b200 = remainder / 200;
  remainder %= 200;
  const int b100 = remainder / 100;
  remainder %= 100;
  const int b50 = remainder / 50;
  remainder %= 50;
  const int b20 = remainder / 20;
  remainder %= 20;

  // obtenemos las monedas
  const int m10 = remainder / 10;
  remainder %= 10;
  const int m5 = remainder / 5;
  remainder %= 5;
  const int m2 = remainder / 2;
  remainder %= 2;
  const int m1 = remainder / 1;

  /*
  Uso la variable [remainder] para manejar el residuo sin tener que realizar tantas operaciones ya que con eso cada división que se obtenga, será el total de billetes y después de eso saco el [MOD] para obtener el residuo y lo reasignamos al [remainder] para que siga la misma secuencia en cada iteración
  */

  // imprimimos los resultados
  salida(b500, 500, "billete");
  salida(b200, 200, "billete");
  salida(b100, 100, "billete");
  salida(b50, 50, "billete");
  salida(b20, 20, "billete");
  salida(m10, 10, "moneda");
  salida(m5, 5, "moneda");
  salida(m2, 2, "moneda");
  salida(m1, 1, "moneda");
}

int main()
{
  // definimos las variables
  int amount;

  // pedimos la cantidad de pesos
  printf("Ingrese la cantidad de pesos: ");
  scanf("%d", &amount);

  // imprimimos un texto informativo
  printf("\n$%d pesos equivalen a:\n", amount);

  // llamamos a la función de proceso
  proceso(amount);

  // finalizamos el programa
  return 0;
}