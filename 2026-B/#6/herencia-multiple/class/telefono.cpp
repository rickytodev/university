#include "../helpers/telefono.h"

#include <iostream>
#include <string>

using namespace std;

Telefono::Telefono() {
    numero = "0000000000";
    cout << "[Constructor] Telefono" << endl;
}

// cuando se crea un Telefono solo, esta llamada a Dispositivo si se usa;
// cuando se crea un Smartphone, se ignora (la hace Smartphone)
Telefono::Telefono(string marca, string modelo, string numero): Dispositivo(marca, modelo) {
    this->numero = numero;
    cout << "[Constructor] Telefono: " << numero << endl;
}

Telefono::~Telefono() {
    cout << "[Destructor] Telefono: " << numero << endl;
}

void Telefono::llamar(string destino) {
    if (!encendido) {
        cout << "No se puede llamar: el telefono esta apagado." << endl;
        return;
    }

    cout << "Llamando de " << numero << " a " << destino << "..." << endl;
}

void Telefono::verDatos() {
    Dispositivo::verDatos();
    cout << "Numero: " << numero << endl;
}

string Telefono::getNumero() {
    return numero;
}

void Telefono::setNumero(string numero) {
    this->numero = numero;
}
