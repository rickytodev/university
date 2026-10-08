#include "../helpers/curso.h"
#include "../helpers/alumno.h"
#include "../helpers/profesor.h"

#include <iostream>
#include <string>

using namespace std;

Curso::Curso() {
    nombre = "Sin nombre";
    creditos = 0;
    aula = "Sin aula";
    profesor = NULL;
    representante = NULL;
}

Curso::Curso(string nombre, int creditos) {
    this->nombre = nombre;
    this->creditos = creditos;
    aula = "Sin aula";
    profesor = NULL;
    representante = NULL;
}

Curso::Curso(string nombre, int creditos, string aula, Profesor *profesor, Alumno *representante) {
    this->nombre = nombre;
    this->creditos = creditos;
    this->aula = aula;
    this->profesor = profesor;
    this->representante = representante;
}

void Curso::iniciarCurso() {
    cout << "Inicia el curso de " << nombre << " en el aula " << aula << "." << endl;
}

void Curso::verDatos() {
    cout << "Curso: " << nombre << endl;
    cout << "Creditos: " << creditos << endl;
    cout << "Aula: " << aula << endl;

    if (profesor != NULL) {
        cout << "Profesor: " << profesor->getNombre() << endl;
    }

    if (representante != NULL) {
        cout << "Representante: " << representante->getNombre() << endl;
    }
}

string Curso::getNombre() {
    return nombre;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

int Curso::getCreditos() {
    return creditos;
}

void Curso::setCreditos(int creditos) {
    this->creditos = creditos;
}

string Curso::getAula() {
    return aula;
}

void Curso::setAula(string aula) {
    this->aula = aula;
}

Profesor* Curso::getProfesor() {
    return profesor;
}

void Curso::setProfesor(Profesor *profesor) {
    this->profesor = profesor;
}

Alumno* Curso::getRepresentante() {
    return representante;
}

void Curso::setRepresentante(Alumno *representante) {
    this->representante = representante;
}
