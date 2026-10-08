#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
    public:
        string nombre;
        Persona();
        Persona(string);
        Persona(string, int);

        void hablar(string);
        void caminar();
        void reproducir(bool);

        int getEdad();
        void setEdad(int);

        float getAltura();
        void setAltura(float);

    private:
        int edad;
        float altura;
};

#endif
