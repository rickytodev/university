/*
  ! Ejercicio 8: Libre

  Solicitarle al usuario que ingrese una cantidad de centímetros o metros y posteriormente seleccione la opción de conversión de longitud al sistema inglés que requiera: yardas, pulgadas o pies. Al final imprimir el resultado.

  ? Nota: Para resolver este ejercicio usa la estructura selectiva de tu preferencia y las siguientes equivalencias:

    * 1 yarda = 1.09361 metros
    * 1 pie = 3.28084 metros
    * 1 pulgada = 39.3701 metros
*/

#include <stdio.h>

void transform_terminate(int amount, float convert, char *unity, int option)
{
  if (option == 1)
  {
    // mostramos el mensaje para los metros
    printf("\n%d metros equivalen a %.2f %s", amount, convert, unity);
  }
  else
  {
    // convertimos de nuevo a centímetros
    convert = convert / 100;
    amount = amount / 100;
    // mostramos el mensaje para los centímetros
    printf("\n%d centímetros equivalen a %.2f %s", amount, convert, unity);
  }
}

int main()
{
  float amount;
  int optUnity, optConvert, changes;

  printf("\n¿Qué unidad se desea trabajar? \n1. Metros \n2. Centímetros \n\n$ ");
  scanf("%d", &optUnity);

  printf("\nIngresa la cantidad en %s: ", optUnity == 1 ? "metros" : "centímetros");
  scanf("%f", &amount);

  printf("\nSelecciona una opción de conversión: \n1. Centímetros a Yardas \n2. Centímetros a Pies \n3. Centímetros a Pulgadas\n\n$ ");
  scanf("%d", &optConvert);

  if (optUnity < 1 || optUnity > 2)
  {
    printf("La opción de unidad a trabajar es invalida");
    return 0;
  }
  else if (optUnity == 2)
  {
    changes = amount * 100;
  }
  else
  {
    changes = amount;
  }

  switch (optConvert)
  {
  case 1:
    transform_terminate(changes, amount * 1.09361, "yardas", optUnity);
    break;
  case 2:
    transform_terminate(changes, amount * 3.28084, "pies", optUnity);
    break;
  case 3:
    transform_terminate(changes, amount * 39.3701, "pulgadas", optUnity);
    break;
  default:
    printf("La opción de conversión es invalida");
    break;
  }

  return 0;
}