#ifndef TELEFONO_H
#define TELEFONO_H

#include "dispositivo.h"

#include <string>

using namespace std;

// herencia virtual: si otra clase hereda de Telefono y de Camara,
// ambas compartiran UNA sola copia de Dispositivo
class Telefono : virtual public Dispositivo {
    public:
        Telefono();
        Telefono(string, string, string);
        ~Telefono();

        void llamar(string);
        void verDatos();

        string getNumero();
        void setNumero(string);

    protected:
        string numero;
};

#endif
