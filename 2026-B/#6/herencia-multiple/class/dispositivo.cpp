#include "../helpers/dispositivo.h"

#include <iostream>
#include <string>

using namespace std;

Dispositivo::Dispositivo() {
    marca = "Generico";
    modelo = "Sin modelo";
    encendido = false;
    cout << "[Constructor] Dispositivo" << endl;
}

Dispositivo::Dispositivo(string marca, string modelo) {
    this->marca = marca;
    this->modelo = modelo;
    encendido = false;
    cout << "[Constructor] Dispositivo: " << marca << " " << modelo << endl;
}

Dispositivo::~Dispositivo() {
    cout << "[Destructor] Dispositivo: " << marca << " " << modelo << endl;
}

void Dispositivo::encender() {
    encendido = true;
    cout << marca << " " << modelo << " encendido." << endl;
}

void Dispositivo::apagar() {
    encendido = false;
    cout << marca << " " << modelo << " apagado." << endl;
}

void Dispositivo::verDatos() {
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Encendido: " << (encendido ? "si" : "no") << endl;
}

string Dispositivo::getMarca() {
    return marca;
}

void Dispositivo::setMarca(string marca) {
    this->marca = marca;
}

string Dispositivo::getModelo() {
    return modelo;
}

void Dispositivo::setModelo(string modelo) {
    this->modelo = modelo;
}

bool Dispositivo::estaEncendido() {
    return encendido;
}
