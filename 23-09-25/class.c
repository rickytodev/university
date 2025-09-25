/*
  [SCANF]
  Función que nos ayuda en la entrada de datos

  [SINTAXIS]s
  scanf("%type", &var) <- esta se usa en todos menos en cadenas
  scanf("%type", var) <- esta solo se usa en las cadenas

  [CLAVES]
  - Entero: int -> %d
  - Flotante: float -> %f
  - Caracter: char -> %c
  - Cadena: car[] -> %s
*/
#include <stdio.h>

int main()
{
  // definición de variables
  int edad;        // <- entero
  float estatura;  // <- flotante
  char letra;      // <- caracter
  char nombre[50]; // <- cadena

  // lectura de datos por medio de scanf()
  printf("\nIngresa una letra: ");
  scanf("%c", &letra);

  printf("Ingresa tu edad: ");
  scanf("%d", &edad);

  printf("Ingresa tu estatura en metros: ");
  scanf("%f", &estatura);

  printf("Ingresa tu nombre: ");
  scanf("%s", nombre);

  // salida en pantalla
  printf("\nTu nombre es: [%s] \nTu edad es: [%d] \nTu estatura es: [%.2f] \nLa letra que ingresaste es: [%c] \n\n", nombre, edad, estatura, letra);

  // promedio de 4 calificaciones
  float cal1, cal2, cal3, cal4;

  // entrada de datos

  // pedimos la primer calificación
  printf("Ingresa tu primera calificacion: ");
  scanf("%f", &cal1);

  // pedimos la segunda calificación
  printf("Ingresa tu segunda calificacion: ");
  scanf("%f", &cal2);

  // pedimos la tercera calificación
  printf("Ingresa tu tercera calificacion: ");
  scanf("%f", &cal3);

  // pedimos la cuarta calificación
  printf("Ingresa tu cuarta calificacion: ");
  scanf("%f", &cal4);

  // realizar operación para calcular el promedio
  const float operation = (cal1 + cal2 + cal3 + cal4) / 4;
  printf("Tu promedio es: %.2f\n\n", operation);

  // retornamos 0 para terminar la función main
  return 0;
}
