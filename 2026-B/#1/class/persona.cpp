#include "../helpers/persona.h"
#include <iostream>
#include <string>

using namespace std;

Persona::Persona(){
    nombre = "Juan";
    edad=0;
    altura=1.7;
}

Persona::Persona(string nombre){
    this->nombre = nombre;
};

Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
    altura = 1.7;
};

void Persona::hablar(string mensaje){
    cout << nombre << "estoy hablando: " << mensaje << endl;
}

void Persona::caminar(){
    cout << nombre << " caminando..." << endl;
}

void Persona::reproducir(bool band){
    cout << nombre << " se reprodujo: " << band << endl;
}

int Persona::getEdad() {
    return edad;
};

void Persona::setEdad(int edad) {
    this->edad = edad;
};

float Persona::getAltura() {
    return altura;
};

void Persona::setAltura(float altura) {
    this->altura = altura;
};
