#include "../helpers/camara.h"

#include <iostream>
#include <string>

using namespace std;

Camara::Camara() {
    megapixeles = 0;
    fotosTomadas = 0;
    cout << "[Constructor] Camara" << endl;
}

Camara::Camara(string marca, string modelo, int megapixeles): Dispositivo(marca, modelo) {
    this->megapixeles = megapixeles;
    fotosTomadas = 0;
    cout << "[Constructor] Camara: " << megapixeles << " MP" << endl;
}

Camara::~Camara() {
    cout << "[Destructor] Camara: " << megapixeles << " MP" << endl;
}

void Camara::tomarFoto() {
    if (!encendido) {
        cout << "No se puede tomar la foto: la camara esta apagada." << endl;
        return;
    }

    fotosTomadas++;
    cout << "Foto #" << fotosTomadas << " tomada a " << megapixeles << " MP." << endl;
}

void Camara::verDatos() {
    Dispositivo::verDatos();
    cout << "Megapixeles: " << megapixeles << endl;
    cout << "Fotos tomadas: " << fotosTomadas << endl;
}

int Camara::getMegapixeles() {
    return megapixeles;
}

void Camara::setMegapixeles(int megapixeles) {
    this->megapixeles = megapixeles;
}

int Camara::getFotosTomadas() {
    return fotosTomadas;
}
