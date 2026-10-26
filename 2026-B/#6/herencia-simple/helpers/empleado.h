#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"

#include <string>

using namespace std;

// herencia simple: Empleado ES UNA Persona
class Empleado : public Persona {
    public:
        Empleado();
        Empleado(string, int, string, string, float);
        ~Empleado();

        // sobreescritura de los metodos de Persona
        void presentarse();
        void verDatos();

        // metodos nuevos, propios de Empleado
        void trabajar();
        virtual float calcularPagoAnual();

        string getPuesto();
        void setPuesto(string);

        float getSalario();
        void setSalario(float);

    protected:
        string puesto;
        float salario;
};

#endif
