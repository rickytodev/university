#ifndef CAMARA_H
#define CAMARA_H

#include "dispositivo.h"

#include <string>

using namespace std;

// herencia virtual, igual que en Telefono
class Camara : virtual public Dispositivo {
    public:
        Camara();
        Camara(string, string, int);
        ~Camara();

        void tomarFoto();
        void verDatos();

        int getMegapixeles();
        void setMegapixeles(int);

        int getFotosTomadas();

    protected:
        int megapixeles;
        int fotosTomadas;
};

#endif
