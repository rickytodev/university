#include "../helpers/materia.h"

#include <iostream>
#include <string>

using namespace std;

Materia::Materia(string nombre, int creditos, string profesor, int horas) {
    // memoria estatica
    this->nombre = nombre;
    this->creditos = creditos;

    // memoria dinamica: se reserva con new
    this->profesor = new string(profesor);
    this->horas = new int(horas);
}

Materia::~Materia() {
    // se libera la memoria reservada con new
    delete profesor;
    delete horas;
}

string Materia::getNombre() {
    return nombre;
}

int Materia::getCreditos() {
    return creditos;
}

string Materia::getProfesor() {
    return *profesor;
}

int Materia::getHoras() {
    return *horas;
}

void Materia::setNombre(string nombre) {
    this->nombre = nombre;
}

void Materia::setCreditos(int creditos) {
    this->creditos = creditos;
}

void Materia::setProfesor(string profesor) {
    *this->profesor = profesor;
}

void Materia::setHoras(int horas) {
    *this->horas = horas;
}

void Materia::verDatos() {
    cout << "Nombre   : " << nombre << endl;
    cout << "Creditos : " << creditos << endl;
    cout << "Profesor : " << *profesor << endl;
    cout << "Horas    : " << *horas << endl;
}
