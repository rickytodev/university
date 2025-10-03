#include <stdio.h>
#include <math.h>

char *esVerdadero(int valor)
{
  return valor == 1 ? "true" : "false";
}

int main()
{
  // ejercicio 1
  printf("\n######### Ejercicio 1 #########\n\n");

  // vars
  int a = 14, b = 50;

  printf("Suma: %d\n", a + b);
  printf("Resta: %d\n", a - b);
  printf("Multiplicacion: %d\n", a * b);
  printf("Division: %d\n", a / b);
  printf("Modulo: %d\n", a % b);
  printf("a^3: %.2f\n", pow(a, 3));
  printf("b^3: %.2f\n", pow(b, 3));

  // ejercicio 2
  printf("\n######### Ejercicio 2 #########\n\n");

  printf("a = b: %d -> %s\n", a == b, esVerdadero(a == b));
  printf("a != b: %d -> %s\n", a != b, esVerdadero(a != b));
  printf("b > a: %d -> %s\n", b > a, esVerdadero(b > a));
  printf("b < a: %d -> %s\n", b < a, esVerdadero(b < a));
  printf("a >= b: %d -> %s\n", a >= b, esVerdadero(a >= b));
  printf("a <= b: %d -> %s\n", a <= b, esVerdadero(a <= b));

  // ejercicio 3
  printf("\n######### Ejercicio 3 #########\n\n");

  const int op_1 = !(a - 5 >= b + 9 && b != a);
  const int op_2 = (b * 5 < a / 3) || !(a == pow(b, 2));

  printf("Op_1: %d -> %s\n", op_1, esVerdadero(op_1));
  printf("Op_2: %d -> %s\n", op_2, esVerdadero(op_2));

  // ejercicio 4
  printf("\n######### Ejercicio 4 #########\n\n");

  // vars
  char name[50] = "Ricardo", university[50] = "UDG", career[50] = "ICOM";
  int age = 18, code = 225976304, semester = 1;

  printf("Hola mundo mi nombre es %s tengo %d anios, estudio en %s la carrera de %s, actualmente curso el semestre %d y mi codigo de alumno es %d.\n", name, age, university, career, semester, code);

  // ejercicio 5
  printf("\n######### Ejercicio 5 #########\n\n");

  // vars
  float c_lb = 100.00, c_cd = 15.5, c_pl = 2.35;
  int lb, cd, pl;

  printf("Ingrese la cantidad de libros: ");
  scanf("%d", &lb);

  printf("Ingrese la cantidad de cuadernos: ");
  scanf("%d", &cd);

  printf("Ingrese la cantidad de plumas: ");
  scanf("%d", &pl);

  // operations
  const float t_lb = lb * c_lb;
  const float t_cd = cd * c_cd;
  const float t_pl = pl * c_pl;

  printf("\nLa venta de libros fue de: $%.2f pesos\n", t_lb);
  printf("La venta de cuadernos fue de: $%.2f pesos\n", t_cd);
  printf("La venta de plumas fue de: $%.2f pesos\n", t_pl);
  printf("La venta total del día fue de: $%.2f pesos\n", t_lb + t_cd + t_pl);

  // ejercicio 6
  printf("\n######### Ejercicio 6 #########\n\n");

  // var
  int cantidad;

  printf("Ingrese la cantidad de pesos: ");
  scanf("%d", &cantidad);

  // operations
  int resto = cantidad;
  const int bll500 = resto / 500;
  resto %= 500;
  const int bll200 = resto / 200;
  resto %= 200;
  const int bll100 = resto / 100;
  resto %= 100;
  const int bll50 = resto / 50;
  resto %= 50;
  const int bll20 = resto / 20;
  resto %= 20;
  const int bll10 = resto / 10;
  resto %= 10;
  const int bll5 = resto / 5;
  resto %= 5;
  const int bll2 = resto / 2;
  resto %= 2;
  const int bll1 = resto;

  printf("\n%d billete(s) de $500 pesos\n", bll500);
  printf("%d billete(s) de $200 pesos\n", bll200);
  printf("%d billete(s) de $100 pesos\n", bll100);
  printf("%d billete(s) de $50 pesos\n", bll50);
  printf("%d billete(s) de $20 pesos\n", bll20);
  printf("%d moneda(s) de $10 pesos\n", bll10);
  printf("%d moneda(s) de $5 pesos\n", bll5);
  printf("%d moneda(s) de $2 pesos\n", bll2);
  printf("%d moneda(s) de $1 peso\n", bll1);

  // ejercicio 7
  printf("\n######### Ejercicio 7 #########\n\n");

  // vars
  int t_w, t_m;

  printf("Ingresa la cantidad de hombres: ");
  scanf("%d", &t_m);

  printf("Ingresa la cantidad de mujeres: ");
  scanf("%d", &t_w);

  // operations
  const int t = t_m + t_w;
  const float p_m = (t_m * 100.0) / t;
  const float p_w = (t_w * 100.0) / t;

  printf("\nEl grupo tiene un %.2f%% de hombres y un %.2f%% de mujeres.\n", p_m, p_w);

  // ejercicio 8
  printf("\n######### Ejercicio 8 #########\n\n");

  // vars
  float n1, n2, n3, p1, p2, p3;

  printf("Ingrese la primera calificacion: ");
  scanf("%f", &n1);

  printf("Ingrese el peso de la primera calificacion: ");
  scanf("%f", &p1);

  printf("Ingrese la segunda calificacion: ");
  scanf("%f", &n2);

  printf("Ingrese el peso de la segunda calificacion: ");
  scanf("%f", &p2);

  printf("Ingrese la tercera calificacion: ");
  scanf("%f", &n3);

  printf("Ingrese el peso de la tercera calificacion: ");
  scanf("%f", &p3);

  // operations
  const float p_total = ((n1 * p1) + (n2 * p2) + (n3 * p3)) / (p1 + p2 + p3);

  printf("\nEl promedio ponderado es: %.2f\n\n", p_total);

  return 0;
}