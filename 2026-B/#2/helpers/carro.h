#ifndef CARRO_H
#define CARRO_H

#include <string>

using namespace std;

class Carro {
    private:
        string color;
        int anio;

    public:
        string marca;
        string modelo;
        string tipo;

        Carro(string marca, string modelo, string tipo, string color, int anio);

        void encender();
        void apagar();
        void acelerar();
        void verDatos();
        string obtenerColor();
        int obtenerAnio();

        void cambiarColor(string color);
        void cambiarAnio(int year);
};

#endif
