#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

// declaracion adelantada: solo se guardan punteros, no objetos completos
class Curso;
class Profesor;

class Alumno {
    public:
        Alumno();
        Alumno(string, string);
        Alumno(string, string, float, Curso*, Profesor*);

        void estudiar();
        void verDatos();

        string getNombre();
        void setNombre(string);

        string getMatricula();
        void setMatricula(string);

        float getPromedio();
        void setPromedio(float);

        Curso* getCurso();
        void setCurso(Curso*);

        Profesor* getTutor();
        void setTutor(Profesor*);

    private:
        string nombre;
        string matricula;
        float promedio;
        Curso *curso;
        Profesor *tutor;
};

#endif
