#include <stdio.h>
#include <math.h>

int main()
{
  // ejercicio #1
  printf("\nEjercicio #1\n");

  // vars
  int code;
  float calf_1, calf_2, calf_3, calf_4, calf_5;
  char name[50];

  // inputs
  printf("\nIngresa tu nombre (sin espacios): ");
  scanf("%s", name);

  printf("Ingresa tu codigo de estudiante: ");
  scanf("%d", &code);

  printf("Ingresa tu primera calificacion: ");
  scanf("%f", &calf_1);

  printf("Ingresa tu segunda calificacion: ");
  scanf("%f", &calf_2);

  printf("Ingresa tu tercera calificacion: ");
  scanf("%f", &calf_3);

  printf("Ingresa tu cuarta calificacion: ");
  scanf("%f", &calf_4);

  printf("Ingresa tu quinta calificacion: ");
  scanf("%f", &calf_5);

  const float prom = (calf_1 + calf_2 + calf_3 + calf_4 + calf_5) / 5;

  printf("\nNombre: %s\nCodigo: %d\nPromedio: %.2f\n", name, code, prom);

  // ejercicio #2
  printf("\nEjercicio #2 (Autobuses la \"Curva Loca\")\n");

  // vars
  char origen[50], destino[50];
  float t_klm, c_klm;

  // inputs
  printf("\nIngresa tu origen: ");
  scanf("%s", origen);

  printf("Ingresa tu destino: ");
  scanf("%s", destino);

  printf("Ingresa el total de kilometros: ");
  scanf("%f", &t_klm);

  printf("Ingresa el costo por kilometro: ");
  scanf("%f", &c_klm);

  // agregamos el IVA al boleto (1.16)
  const float c_ticket = (t_klm * c_klm) * 1.16;

  printf("Origen: %s\nDestino: %s\nKilometros: %.2f\nCosto por Kilometro: %.2f\nCosto Total (+IVA): %.2f\n\n", origen, destino, t_klm, c_klm, c_ticket);

  // ejercicio #3
  printf("\nEjercicio #3\n");

  // vars
  float t_klm_to_mll;

  // input
  printf("\nIngresa el total de kilometros a convertir a millas: ");
  scanf("%f", &t_klm_to_mll);

  const float kml_mll = t_klm_to_mll / 1.609;

  printf("\n%.2f kilometros equivalen a: %.2f millas\n", t_klm_to_mll, kml_mll);

  // ejercicio #4
  printf("\nEjercicio #4\n");

  // vars
  float p_orig, d_pro;

  // input
  printf("\nIngresa el precio original del producto: ");
  scanf("%f", &p_orig);

  printf("Ingresa el descuento del producto: ");
  scanf("%f", &d_pro);

  const float total_substract_d = p_orig - ((p_orig * d_pro) / 100);

  printf("\nEl precio total con descuento es: $%2.f pesos\n", total_substract_d);

  // ejercicio #5
  printf("\nEjercicio #5\n");

  printf("\nOp_1 = %.2f\n", 30 / 5.0 + 2 * pow(3, 2) - 7 * 9);
  printf("Op_2 = %.2f\n", (7 * 4 + (18 - 9) / 3.0 + pow(2, 4)) / 2.0);
  printf("Op_3 = %.2f\n", 12 % 3 + pow(4, 2) * (7 * (1 - (7 + 2) / 9.0)) + 8);
  printf("Op_4 = %d\n", 6 * ((!((8 / 4) >= 2) || (9 > 9)) && ((5 >= 18 / 3) || (1 + 4 >= 7 / 2))) + 10);
  printf("Op_5 = %d\n", (7 + 3 * 2) > 12 && 8 / 2 == 4);
  printf("Op_6 = %d\n", 8 + 7 % 5 % 3 * 2);
  printf("Op_7 = %d\n", (pow(5, 2) - 16 % 11) <= 20 || 18 / 3 != 7);
  printf("Op_8 = %d\n", (!(10 == 10 || 5 > 3)) && 15 - 10 < 5);
  printf("Op_9 = %d\n", !(17 >= pow(6, 2) || (13 - 7 * 3 % 2 != 4 * 5 % 2)));

  return 0;
}