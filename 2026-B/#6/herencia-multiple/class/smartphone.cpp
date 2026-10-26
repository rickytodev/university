#include "../helpers/smartphone.h"

#include <iostream>
#include <string>

using namespace std;

Smartphone::Smartphone() {
    sistemaOperativo = "Sin sistema";
    appsInstaladas = 0;
    cout << "[Constructor] Smartphone" << endl;
}

// con herencia virtual, la clase MAS derivada es la que construye a la base
// comun (Dispositivo); despues se construyen los padres en el orden en que
// se declararon: primero Telefono, luego Camara
Smartphone::Smartphone(string marca, string modelo, string numero, int megapixeles, string sistemaOperativo): Dispositivo(marca, modelo),
      Telefono(marca, modelo, numero),
      Camara(marca, modelo, megapixeles) {
    this->sistemaOperativo = sistemaOperativo;
    appsInstaladas = 0;
    cout << "[Constructor] Smartphone: " << sistemaOperativo << endl;
}

Smartphone::~Smartphone() {
    cout << "[Destructor] Smartphone: " << sistemaOperativo << endl;
}

void Smartphone::verDatos() {
    // se llama una sola vez a Dispositivo y luego se agregan
    // los datos propios de cada padre sin repetir marca y modelo
    Dispositivo::verDatos();
    cout << "Numero: " << numero << endl;
    cout << "Megapixeles: " << megapixeles << endl;
    cout << "Fotos tomadas: " << fotosTomadas << endl;
    cout << "Sistema operativo: " << sistemaOperativo << endl;
    cout << "Apps instaladas: " << appsInstaladas << endl;
}

void Smartphone::instalarApp(string app) {
    // 'encendido' viene de Dispositivo: gracias a la herencia virtual
    // solo existe una copia y no hay ambiguedad
    if (!encendido) {
        cout << "No se puede instalar " << app << ": el smartphone esta apagado." << endl;
        return;
    }

    appsInstaladas++;
    cout << app << " instalada en " << sistemaOperativo << "." << endl;
}

string Smartphone::getSistemaOperativo() {
    return sistemaOperativo;
}

void Smartphone::setSistemaOperativo(string sistemaOperativo) {
    this->sistemaOperativo = sistemaOperativo;
}
