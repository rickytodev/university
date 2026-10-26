#include "../helpers/empleado.h"

#include <iostream>
#include <string>

using namespace std;

// si no se indica, se llama automaticamente al constructor vacio de Persona
Empleado::Empleado() {
    puesto = "Sin puesto";
    salario = 0;
    cout << "[Constructor] Empleado" << endl;
}

// lista de inicializacion: primero se construye la parte de Persona
Empleado::Empleado(string nombre, int edad, string curp, string puesto, float salario): Persona(nombre, edad, curp) {
    this->puesto = puesto;
    this->salario = salario;
    cout << "[Constructor] Empleado: " << nombre << endl;
}

Empleado::~Empleado() {
    cout << "[Destructor] Empleado: " << nombre << endl;
}

void Empleado::presentarse() {
    // 'nombre' es protected en Persona, por eso se puede usar aqui directamente
    cout << "Hola, soy " << nombre << " y trabajo como " << puesto << "." << endl;
}

void Empleado::verDatos() {
    // operador de ambito: se reutiliza el metodo de la clase padre
    Persona::verDatos();
    cout << "Puesto: " << puesto << endl;
    cout << "Salario mensual: $" << salario << endl;

    // 'curp' es private en Persona: aqui no se puede usar 'curp',
    // solo getCurp()
}

void Empleado::trabajar() {
    cout << nombre << " esta trabajando como " << puesto << "." << endl;
}

float Empleado::calcularPagoAnual() {
    return salario * 12;
}

string Empleado::getPuesto() {
    return puesto;
}

void Empleado::setPuesto(string puesto) {
    this->puesto = puesto;
}

float Empleado::getSalario() {
    return salario;
}

void Empleado::setSalario(float salario) {
    this->salario = salario;
}
