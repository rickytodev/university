/*
  Funciones Parte #1

  Sintaxis:

  type name_function(...parameters) {
    <code>
    return value;
  }

  ...parameters: { type name }

  Tipos de datos de retorno:
    - void: no retorna nada
    - int: retorna un entero
    - float: retorna un flotante -> boolean
    - char: retorna un caracter
*/
#include <stdio.h>

/*
  Variable Global

  Se declara por fuera de cualquier función y puede ser utilizada por cualquier función y también puede ser modificada en cualquier parte del código.
*/

int code = 225976304; // <- variable global

// función sin paso de parametros y sin retorno de valor
void saludar() // <- función saludo
{
  printf("Hola Mundo\n");
}

// función con paso de parametros y con retorno de valor
void saludo(char nombre[100])
{
  printf("Hola %s, espero que tengas un buen dia\n", nombre);
}

// función sin paso de parametros y con retorno de valores
int suma()
{
  int a, b;
  printf("Ingresa un numero entero: ");
  scanf("%d", &a);
  printf("Ingresa otro numero entero: ");
  scanf("%d", &b);
  return a + b;
}

// función con paso de parametros y con retorno de valores
int resta(int a, int b)
{
  return a - b;
}

// variables locales y globales
void ejemplo()
{
  char universidad[50] = "CUCEI"; // <- variable local
  printf("Mi centro universitario es: %s\n", universidad);
  printf("Mi codigo es: %d\n", code);
}

// function con parametros de distintos tipos de datos
void mensaje(int edad, float estatura, char letra, char nombre[])
{
  printf("Tu nombre es %s, tienes %d años, mides %.2f y tu letra es %c\n", nombre, edad, estatura, letra);
}

int main() // <- función madre (encargada de controlar el flujo del programa)
{
  saludar(); // <- llamado directo de la función saludar

  saludo("RicardoVega"); // <- llamado directo de la función saludo

  printf("La suma es: %d\n", suma());

  int resultado_resta = resta(45, 32); // <- llamado directo de la función resta
  printf("La resta es: %d\n", resultado_resta);

  ejemplo();
  printf("Mi codigo es: %d\n", code);

  code = 123456789; // <- modificando variable global
  ejemplo();
  printf("Mi codigo es: %d\n", code);

  mensaje(18, 1.78, 'B', "RicardoVega");

  // todo : Cuando se declara una función con varios parametros, solo se pueden poner las variables que están asignadas de manera correcta respetando el orden del tipo de dato.

  return 0;
}