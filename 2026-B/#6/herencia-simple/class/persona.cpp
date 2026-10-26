#include "../helpers/persona.h"

#include <iostream>
#include <string>

using namespace std;

Persona::Persona() {
    nombre = "Sin nombre";
    edad = 0;
    curp = "SIN CURP";
    cout << "[Constructor] Persona" << endl;
}

Persona::Persona(string nombre, int edad, string curp) {
    this->nombre = nombre;
    this->edad = edad;
    this->curp = curp;
    cout << "[Constructor] Persona: " << nombre << endl;
}

Persona::~Persona() {
    cout << "[Destructor] Persona: " << nombre << endl;
}

void Persona::presentarse() {
    cout << "Hola, soy " << nombre << "." << endl;
}

void Persona::verDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "CURP: " << curp << endl;
}

void Persona::caminar() {
    cout << nombre << " esta caminando." << endl;
}

string Persona::getNombre() {
    return nombre;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

int Persona::getEdad() {
    return edad;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

string Persona::getCurp() {
    return curp;
}

void Persona::setCurp(string curp) {
    this->curp = curp;
}
