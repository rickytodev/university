#include "../helpers/alumno.h"
#include "../helpers/curso.h"
#include "../helpers/profesor.h"

#include <iostream>
#include <string>

using namespace std;

Alumno::Alumno() {
    nombre = "Sin nombre";
    matricula = "000000000";
    promedio = 0;
    curso = NULL;
    tutor = NULL;
}

Alumno::Alumno(string nombre, string matricula) {
    this->nombre = nombre;
    this->matricula = matricula;
    promedio = 0;
    curso = NULL;
    tutor = NULL;
}

Alumno::Alumno(string nombre, string matricula, float promedio, Curso *curso, Profesor *tutor) {
    this->nombre = nombre;
    this->matricula = matricula;
    this->promedio = promedio;
    this->curso = curso;
    this->tutor = tutor;
}

void Alumno::estudiar() {
    cout << nombre << " esta estudiando." << endl;
}

void Alumno::verDatos() {
    cout << "Alumno: " << nombre << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Promedio: " << promedio << endl;

    if (curso != NULL) {
        cout << "Curso: " << curso->getNombre() << endl;
    }

    if (tutor != NULL) {
        cout << "Tutor: " << tutor->getNombre() << endl;
    }
}

string Alumno::getNombre() {
    return nombre;
}

void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}

string Alumno::getMatricula() {
    return matricula;
}

void Alumno::setMatricula(string matricula) {
    this->matricula = matricula;
}

float Alumno::getPromedio() {
    return promedio;
}

void Alumno::setPromedio(float promedio) {
    this->promedio = promedio;
}

Curso* Alumno::getCurso() {
    return curso;
}

void Alumno::setCurso(Curso *curso) {
    this->curso = curso;
}

Profesor* Alumno::getTutor() {
    return tutor;
}

void Alumno::setTutor(Profesor *tutor) {
    this->tutor = tutor;
}
