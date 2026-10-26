#include "../helpers/gerente.h"

#include <iostream>
#include <string>

using namespace std;

Gerente::Gerente() {
    departamento = "Sin departamento";
    bono = 0;
    cout << "[Constructor] Gerente" << endl;
}

// Gerente solo llama al constructor de su padre directo (Empleado),
// y Empleado se encarga de llamar al de Persona
Gerente::Gerente(string nombre, int edad, string curp, float salario, string departamento, float bono): Empleado(nombre, edad, curp, "Gerente", salario) {
    this->departamento = departamento;
    this->bono = bono;
    cout << "[Constructor] Gerente: " << nombre << endl;
}

Gerente::~Gerente() {
    cout << "[Destructor] Gerente: " << nombre << endl;
}

void Gerente::presentarse() {
    cout << "Hola, soy " << nombre << ", gerente del departamento de " << departamento << "." << endl;
}

void Gerente::verDatos() {
    // reutiliza Empleado::verDatos(), que a su vez reutiliza Persona::verDatos()
    Empleado::verDatos();
    cout << "Departamento: " << departamento << endl;
    cout << "Bono anual: $" << bono << endl;
}

float Gerente::calcularPagoAnual() {
    // se aprovecha el calculo del padre y se le suma el bono
    return Empleado::calcularPagoAnual() + bono;
}

void Gerente::dirigirReunion() {
    // 'nombre' viene de Persona y 'puesto' de Empleado, ambos protected
    cout << nombre << " (" << puesto << ") esta dirigiendo una reunion de " << departamento << "." << endl;
}

string Gerente::getDepartamento() {
    return departamento;
}

void Gerente::setDepartamento(string departamento) {
    this->departamento = departamento;
}

float Gerente::getBono() {
    return bono;
}

void Gerente::setBono(float bono) {
    this->bono = bono;
}
