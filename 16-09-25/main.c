/*
  Esto es un comentarios
  de multiples líneas y
  no afecta en la ejecución
*/

// Esto es un comentario de una sola linea

#include <stdio.h> // Liberia de funciones estandar
#include <math.h>  // Libreria de funciones matematicas

int main() // Función principal
// Inicio
{
  /*
    # Tipos de datos
    Entero -> int -> %d o i%
    Flotante -> float -> %f
    Carácter -> char -> %c
    Cadena -> char[] -> %s

    # Variables
    tipo_dato nombre_variable = valor_inicial;
  */

  printf("\n--- Variables ---\n\n");

  // Declaración dentro de las variables
  int entero = 12;
  float flotante = 15.96;
  char caracter = 'A';
  char cadena[15] = "Hola mundo";

  // Salida en pantalla mediante printf
  // \n -> salto de línea
  printf("Entero: %d\n", entero);
  printf("Flotante: %f\n", flotante);
  printf("Caracter: %c\n", caracter);
  printf("Cadena: %s\n\n", cadena);

  printf("--- Operaciones Aritmeticos ---\n\n");

  // Declaración de multiples variables
  int a = 16, b = 2, c;

  c = a + b; // Suma
  printf("Suma: %d\n", c);

  c = a - b; // Resta
  printf("Resta: %d\n", c);

  c = a * b; // Multiplicación
  printf("Multiplicacion: %d\n", c);

  c = a / b; // División
  printf("Division: %d\n", c);

  c = a % b; // Módulo o Residuo
  printf("Modulo: %d\n", c);

  c = pow(a, b); // Potencia
  printf("Potencia: %d\n\n", c);

  printf("--- Operaciones Relacionales o de Comparacion ---\n\n");

  printf("%d > %d = %d\n", a, b, a > b); // Mayor que

  printf("%d < %d = %d\n", a, b, a < b); // Menor que

  printf("%d >= %d = %d\n", a, b, a >= b); // Mayor o igual que

  printf("%d <= %d = %d\n", a, b, a <= b); // Menor o igual que

  printf("%d == %d = %d\n", a, b, a == b); // Igualdad

  printf("%d != %d = %d\n\n", a, b, a != b); // Desigualdad

  printf("--- Operaciones Logicas ---\n\n");

  c = a < b && a == 16; // AND
  printf("AND: %d\n", c);

  c = a < b || a == 16; // OR
  printf("OR: %d\n", c);

  c = !(a < b); // NOT
  printf("NOT: %d\n\n", c);

  printf("--- Operaciones de Asignacion ---\n\n");
  a += b; // Asignación simple
  printf("Asignacion: %d\n", a);

  a -= b; // Asignación de resta
  printf("Asignacion de Resta: %d\n", a);

  a *= b; // Asignación de multiplicación
  printf("Asignacion de Multiplicacion: %d\n", a);

  a /= b; // Asignación de división
  printf("Asignacion de Division: %d\n", a);

  a %= b; // Asignación de módulo
  printf("Asignacion de Modulo: %d\n\n", a);

  return 0; // Retornamos 0 cuando termina la función
}
// Fin