#ifndef CURSO_H
#define CURSO_H

#include <string>

using namespace std;

// declaracion adelantada: solo se guardan punteros, no objetos completos
class Alumno;
class Profesor;

class Curso {
    public:
        Curso();
        Curso(string, int);
        Curso(string, int, string, Profesor*, Alumno*);

        void iniciarCurso();
        void verDatos();

        string getNombre();
        void setNombre(string);

        int getCreditos();
        void setCreditos(int);

        string getAula();
        void setAula(string);

        Profesor* getProfesor();
        void setProfesor(Profesor*);

        Alumno* getRepresentante();
        void setRepresentante(Alumno*);

    private:
        string nombre;
        int creditos;
        string aula;
        Profesor *profesor;
        Alumno *representante;
};

#endif
