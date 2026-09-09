#include "./helpers/carro.h"
#include "./helpers/persona.h"
#include "./helpers/libro.h"

#include <iostream>

int main () {
    Persona persona("Ricardo", "Vega G", 19, 1.75);
    persona.hablar();

    Carro carro("Toyota", "Corolla", "Sedan", "Rojo", 2020);
    carro.encender();

    Libro libro("El Principito", "Antoine de Saint-Exupéry", 1943, 96);
    libro.verDatos();

    return 0;
}
