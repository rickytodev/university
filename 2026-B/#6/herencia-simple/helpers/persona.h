#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

// clase base: es la raiz de la jerarquia Persona -> Empleado -> Gerente
class Persona {
    public:
        Persona();
        Persona(string, int, string);

        // destructor virtual: al hacer delete desde un Persona* se ejecutan
        // tambien los destructores de las clases derivadas
        virtual ~Persona();

        // virtual: las clases hijas pueden redefinirlo (sobreescritura)
        virtual void presentarse();
        virtual void verDatos();

        // no es virtual: se hereda tal cual
        void caminar();

        string getNombre();
        void setNombre(string);

        int getEdad();
        void setEdad(int);

        string getCurp();
        void setCurp(string);

    // protected: las clases derivadas si pueden usarlos directamente,
    // pero desde fuera (main) siguen ocultos
    protected:
        string nombre;
        int edad;

    // private: ni siquiera las clases derivadas pueden verlo, solo por get/set
    private:
        string curp;
};

#endif
