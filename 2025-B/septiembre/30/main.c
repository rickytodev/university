/*
  @alumno Ricardo Jeshua Vega García
  @alumno Carlos Felipe Villanueva Reynozo
*/

// librería de para entrada y salida de datos
#include <stdio.h>

// función para imprimir resultados
// char [x] -> cadena de texto que recibe el nombre del parámetro
// int total -> entero que recibe el valor del parámetro
void salida(char x[50], int total)
{
  // impresión de resultados
  printf("El total de %s es: %d\n", x, total);
}

// función para realizar el proceso
// int cantidad -> entero que recibe la cantidad de dias
int proceso(int cantidad)
{
  // definimos las constantes y realizamos la operaciones dentro de ellas
  const int years = cantidad / 365;                      // <- años
  const int months = (cantidad - years * 365) / 30;      // <- meses
  const int days = cantidad - years * 365 - months * 30; // <- dias

  // imprimir resultado en la terminal
  printf("\n%d dias equivalen a:\n", cantidad);
  salida("1 anio(s)", years);
  salida("1 mes(es)", months);
  salida("1 dia(s)", days);
}

// función principal
void main()
{
  // definición de variables
  int value;

  // pedimos al usuario que ingrese una cantidad de dias
  printf("Ingresa una cantidad de dias: ");

  // guardamos el datos
  scanf("%d", &value);

  // llamamos a la función de operación y le pasamos los parámetros
  proceso(value);
}