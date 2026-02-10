/*
Un ciclista parte de su ciudad de origen a las 13 horas : 32 minutos : 55 segundos. EI tiempo de viaje hasta llegar a la ciudad de destino es de 4785 segundos. Escribir un algoritmo que determine la hora de llegada del ciclista a la ciudad de destino. EI programa debe usar una función con paso de parámetros y sin retorno de valores, se debe seguir la estructura base presentada a continuación.
*/

#include <stdio.h>

void proceso(int h, int m, int s)
{
  // definimos las horas de llegada
  const int travel_seconds = 4785;

  // convertimos todo a segundos
  const int hSeconds = h * 3600;
  const int mSeconds = m * 60;

  // sumamos todo
  int op = travel_seconds + hSeconds + mSeconds + s;

  // convertimos a horas, minutos y segundos
  int fHours = op / 3600;
  op %= 3600;
  int fMinutes = op / 60;
  op %= 60;
  int fSeconds = op;

  // imprimimos el resultado
  printf("Llegada %d:%d:%d", fHours, fMinutes, fSeconds);
}

int main()
{
  // definimos las variables para guardar la hora, minutos y segundos
  int hours = 13, minutes = 32, seconds = 55;

  // llamamos a la función de operación y le pasamos los parámetros
  proceso(hours, minutes, seconds);

  // finalizamos la función
  return 0;
}