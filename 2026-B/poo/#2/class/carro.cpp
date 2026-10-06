#include "../helpers/carro.h"
#include <iostream>
#include <string>

using namespace std;

Carro::Carro(string marca, string modelo, string tipo, string color, int anio) {
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->color = color;
    this->anio = anio;
}

void Carro::encender() {
    cout << "El " << this->marca << " " << this->modelo << " se enciende." << endl;
}

void Carro::apagar() {
    cout << "El " << this->marca << " " << this->modelo << " se apaga." << endl;
}

void Carro::acelerar() {
    cout << "El " << this->marca << " " << this->modelo << " está acelerando." << endl;
}

void Carro::verDatos() {
    cout << "Marca: " << this->marca << endl;
    cout << "modelo: " << this->modelo << endl;
    cout << "Tipo: " << this->tipo << endl;
    cout << "Color: " << this->color << endl;
    cout << "Año: " << this->anio << endl;
}

string Carro::obtenerColor() {
    return this->color;
}

int Carro::obtenerAnio() {
    return this->anio;
}

void Carro::cambiarColor(string color) {
    this->color = color;
}

void Carro::cambiarAnio(int anio) {
    this->anio = anio;
}
