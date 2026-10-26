#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "telefono.h"
#include "camara.h"

#include <string>

using namespace std;

// herencia multiple: Smartphone ES UN Telefono y tambien ES UNA Camara
class Smartphone : public Telefono, public Camara {
    public:
        Smartphone();
        Smartphone(string, string, string, int, string);
        ~Smartphone();

        // Telefono y Camara redefinen verDatos(); si Smartphone no lo
        // redefine, la llamada seria ambigua y no compilaria
        void verDatos();

        void instalarApp(string);

        string getSistemaOperativo();
        void setSistemaOperativo(string);

    private:
        string sistemaOperativo;
        int appsInstaladas;
};

#endif
