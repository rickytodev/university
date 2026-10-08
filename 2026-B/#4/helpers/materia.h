#ifndef MATERIA_H
#define MATERIA_H

#include <string>

using namespace std;

class Materia {
    private:
        // memoria estatica
        string nombre;
        int creditos;

        // memoria dinamica
        string *profesor;
        int *horas;

    public:
        Materia(string nombre, int creditos, string profesor, int horas);
        ~Materia();

        string getNombre();
        int getCreditos();
        string getProfesor();
        int getHoras();

        void setNombre(string nombre);
        void setCreditos(int creditos);
        void setProfesor(string profesor);
        void setHoras(int horas);

        void verDatos();
};

#endif
