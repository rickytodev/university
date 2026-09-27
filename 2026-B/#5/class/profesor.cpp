#include "../helpers/profesor.h"
#include "../helpers/alumno.h"
#include "../helpers/curso.h"

#include <iostream>
#include <string>

using namespace std;

Profesor::Profesor() {
    nombre = "Sin nombre";
    cedula = "00000000";
    antiguedad = 0;
    curso = NULL;
    mejorAlumno = NULL;
}

Profesor::Profesor(string nombre, string cedula) {
    this->nombre = nombre;
    this->cedula = cedula;
    antiguedad = 0;
    curso = NULL;
    mejorAlumno = NULL;
}

Profesor::Profesor(string nombre, string cedula, int antiguedad, Curso *curso, Alumno *mejorAlumno) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->antiguedad = antiguedad;
    this->curso = curso;
    this->mejorAlumno = mejorAlumno;
}

void Profesor::impartirClase() {
    cout << "El profesor " << nombre << " esta impartiendo su clase." << endl;
}

void Profesor::verDatos() {
    cout << "Profesor: " << nombre << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Antiguedad: " << antiguedad << " anios" << endl;

    if (curso != NULL) {
        cout << "Curso: " << curso->getNombre() << endl;
    }

    if (mejorAlumno != NULL) {
        cout << "Mejor alumno: " << mejorAlumno->getNombre() << endl;
    }
}

string Profesor::getNombre() {
    return nombre;
}

void Profesor::setNombre(string nombre) {
    this->nombre = nombre;
}

string Profesor::getCedula() {
    return cedula;
}

void Profesor::setCedula(string cedula) {
    this->cedula = cedula;
}

int Profesor::getAntiguedad() {
    return antiguedad;
}

void Profesor::setAntiguedad(int antiguedad) {
    this->antiguedad = antiguedad;
}

Curso* Profesor::getCurso() {
    return curso;
}

void Profesor::setCurso(Curso *curso) {
    this->curso = curso;
}

Alumno* Profesor::getMejorAlumno() {
    return mejorAlumno;
}

void Profesor::setMejorAlumno(Alumno *mejorAlumno) {
    this->mejorAlumno = mejorAlumno;
}
