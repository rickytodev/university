#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
    private:
        int edad;
        float altura;

    public:
        string nombre;
        string apellido;

        Persona(string nombre, string apellido, int edad, float altura);

        void hablar();
        void verDatos();
        int obtenerEdad();
        float obtenerAltura();

        void cambiarEdad(int edad);
        void cambiarAltura(float altura);
};

#endif
