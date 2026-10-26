#ifndef GERENTE_H
#define GERENTE_H

#include "empleado.h"

#include <string>

using namespace std;

// herencia simple lineal: Gerente ES UN Empleado, que a su vez ES UNA Persona
class Gerente : public Empleado {
    public:
        Gerente();
        Gerente(string, int, string, float, string, float);
        ~Gerente();

        // sobreescritura de metodos heredados
        void presentarse();
        void verDatos();
        float calcularPagoAnual();

        // metodo nuevo, propio de Gerente
        void dirigirReunion();

        string getDepartamento();
        void setDepartamento(string);

        float getBono();
        void setBono(float);

    // ultima clase de la cadena: sus atributos pueden ser private
    private:
        string departamento;
        float bono;
};

#endif
