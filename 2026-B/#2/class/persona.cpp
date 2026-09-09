#include "../helpers/persona.h"
#include <iostream>
#include <string>

using namespace std;

Persona::Persona(string nombre, string apellido, int edad, float altura) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->altura = altura;
}

void Persona::hablar() {
    cout << "Hola, mi nombre es " << this->nombre << " " << this->apellido << "." << endl;
}

void Persona::verDatos() {
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellido << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Altura: " << this->altura << endl;
}

int Persona::obtenerEdad() {
    return this->edad;
}

float Persona::obtenerAltura() {
    return this->altura;
}

void Persona::cambiarEdad(int edad) {
    this->edad = edad;
}

void Persona::cambiarAltura(float altura) {
    this->altura = altura;
}
