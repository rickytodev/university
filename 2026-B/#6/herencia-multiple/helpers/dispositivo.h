#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

using namespace std;

// clase base: la punta superior del diamante
//
//            Dispositivo
//             /       \
//        Telefono    Camara
//             \       /
//            Smartphone
class Dispositivo {
    public:
        Dispositivo();
        Dispositivo(string, string);
        virtual ~Dispositivo();

        void encender();
        void apagar();
        virtual void verDatos();

        string getMarca();
        void setMarca(string);

        string getModelo();
        void setModelo(string);

        bool estaEncendido();

    protected:
        string marca;
        string modelo;
        bool encendido;
};

#endif
