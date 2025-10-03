/*
Calcule el descuento de un producto, pida al usuario que ingrese el nombre del producto, la cantidad de producto que requiere, el precio por unidad y el porcentaje de descuento. Imprima en pantalla el nombre del producto, la cantidad de producto que lleva, el precio total antes del descuento, y el precio final con descuento. El programa debe usar al menos dos funciones con paso de parámetros que se llamen entre sí mismas, para este ejercicio no habrá estructura base.
*/

#include <stdio.h>

int main()
{
  // definimos las variables
  char product_name[50];
  int quantity, discount;
  float price_unit;

  // pedimos al usuario los datos
  printf("Ingrese el nombre del producto: ");
  scanf("%s", product_name);

  printf("Ingrese la cantidad de productos a llevar: ");
  scanf("%d", &quantity);

  printf("Ingrese el precio por unidad: $");
  scanf("%f", &price_unit);

  printf("Ingrese el porcentaje de descuento (sin %%): ");
  scanf("%d", &discount);

  // realizamos los cálculos
  float total_price = quantity * price_unit;
  float discount_amount = total_price * (discount / 100.0);
  float price_with_discount = total_price - discount_amount;

  // imprimimos los resultados
  printf("El precio de %d piezas de %s sin descuento es: $%.2f\n", quantity, product_name, total_price);

  printf("El precio total con %d%% de descuento es: $%.2f\n", discount, price_with_discount);

  // finalizamos la función
  return 0;
}