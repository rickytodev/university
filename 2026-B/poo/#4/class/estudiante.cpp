#include "../helpers/estudiante.h"

#include <iostream>
#include <string>

using namespace std;

Estudiante::Estudiante(string nombre, int edad, string carrera, float promedio) {
    // memoria estatica
    this->nombre = nombre;
    this->edad = edad;

    // memoria dinamica: se reserva con new
    this->carrera = new string(carrera);
    this->promedio = new float(promedio);
}

Estudiante::~Estudiante() {
    // se libera la memoria reservada con new
    delete carrera;
    delete promedio;
}

string Estudiante::getNombre() {
    return nombre;
}

int Estudiante::getEdad() {
    return edad;
}

string Estudiante::getCarrera() {
    return *carrera;
}

float Estudiante::getPromedio() {
    return *promedio;
}

void Estudiante::setNombre(string nombre) {
    this->nombre = nombre;
}

void Estudiante::setEdad(int edad) {
    this->edad = edad;
}

void Estudiante::setCarrera(string carrera) {
    *this->carrera = carrera;
}

void Estudiante::setPromedio(float promedio) {
    *this->promedio = promedio;
}

void Estudiante::verDatos() {
    cout << "Nombre   : " << nombre << endl;
    cout << "Edad     : " << edad << endl;
    cout << "Carrera  : " << *carrera << endl;
    cout << "Promedio : " << *promedio << endl;
}
