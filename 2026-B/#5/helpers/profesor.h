#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

using namespace std;

// declaracion adelantada: solo se guardan punteros, no objetos completos
class Alumno;
class Curso;

class Profesor {
    public:
        Profesor();
        Profesor(string, string);
        Profesor(string, string, int, Curso*, Alumno*);

        void impartirClase();
        void verDatos();

        string getNombre();
        void setNombre(string);

        string getCedula();
        void setCedula(string);

        int getAntiguedad();
        void setAntiguedad(int);

        Curso* getCurso();
        void setCurso(Curso*);

        Alumno* getMejorAlumno();
        void setMejorAlumno(Alumno*);

    private:
        string nombre;
        string cedula;
        int antiguedad;
        Curso *curso;
        Alumno *mejorAlumno;
};

#endif
