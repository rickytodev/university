#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string.h>

using namespace std;

class Estudiante {
    private:
        // memoria estatica
        string nombre;
        int edad;

        // memoria dinamica
        string *carrera;
        float *promedio;

    public:
        Estudiante(string nombre, int edad, string carrera, float promedio);
        ~Estudiante();

        string getNombre();
        int getEdad();
        string getCarrera();
        float getPromedio();

        void setNombre(string nombre);
        void setEdad(int edad);
        void setCarrera(string carrera);
        void setPromedio(float promedio);

        void verDatos();
};

#endif
