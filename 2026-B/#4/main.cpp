/*
    Actividad #4 - Clases con memoria estatica y dinamica

      1. 2 clases                              -> Estudiante y Materia
      2. Encapsuladas (private, get y set)     -> los 4 atributos son private
      3. 4 atributos: 2 estaticos y 2 punteros -> los punteros usan new y delete
      4. Usarlas en el main
*/

#include "./helpers/estudiante.h"
#include "./helpers/materia.h"

#include <iostream>

using namespace std;

int main() {
    // objetos en memoria estatica
    Estudiante estudiante("Ricardo Vega", 19, "Ingenieria en Computacion", 88.5);
    Materia materia("Programacion Orientada a Objetos", 8, "Jeshua Reynozo", 64);

    cout << "===== Datos iniciales =====" << endl;
    estudiante.verDatos();
    cout << endl;
    materia.verDatos();

    // los atributos son private, solo se leen con get
    cout << endl << "===== Leyendo con get =====" << endl;
    cout << "Promedio : " << estudiante.getPromedio() << endl;
    cout << "Profesor : " << materia.getProfesor() << endl;

    // y solo se cambian con set
    cout << endl << "===== Cambiando con set =====" << endl;
    estudiante.setEdad(20);
    estudiante.setPromedio(95.5);
    materia.setProfesor("Ana Lopez");
    materia.setHoras(80);

    estudiante.verDatos();
    cout << endl;
    materia.verDatos();

    // objeto en memoria dinamica: se usa -> en lugar de .
    cout << endl << "===== Objeto creado con new =====" << endl;
    Estudiante *estudiante2 = new Estudiante("Maria Perez", 21, "Medicina", 72.5);
    estudiante2->verDatos();

    estudiante2->setCarrera("Enfermeria");
    cout << "Carrera nueva : " << estudiante2->getCarrera() << endl;

    delete estudiante2;

    return 0;
}
