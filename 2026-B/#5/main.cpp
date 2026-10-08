#include "./helpers/alumno.h"
#include "./helpers/curso.h"
#include "./helpers/profesor.h"

#include <iostream>

using namespace std;

int main () {
    // constructor vacio
    Alumno alumno1;
    Profesor profesor1;
    Curso curso1;

    cout << "--- Constructor vacio ---" << endl;
    alumno1.verDatos();
    cout << endl;
    profesor1.verDatos();
    cout << endl;
    curso1.verDatos();

    // constructor con dos parametros
    Alumno alumno2("Ricardo Vega", "220123456");
    Profesor profesor2("Jeshua Reynozo", "12345678");
    Curso curso2("Estructuras de Datos", 10);

    cout << endl << "--- Constructor con dos parametros ---" << endl;
    alumno2.verDatos();
    cout << endl;
    profesor2.verDatos();
    cout << endl;
    curso2.verDatos();

    // constructor completo: recibe los atributos de tipo clase
    Alumno alumno3("Ana Torres", "220987654", 92.5, &curso2, &profesor2);
    Profesor profesor3("Maria Lopez", "87654321", 12, &curso2, &alumno3);
    Curso curso3("Programacion Orientada a Objetos", 8, "Aula 101", &profesor3, &alumno3);

    cout << endl << "--- Constructor completo ---" << endl;
    alumno3.verDatos();
    cout << endl;
    profesor3.verDatos();
    cout << endl;
    curso3.verDatos();

    // encapsulamiento: los atributos son privados, solo se entra por get y set
    // alumno2.promedio = 100;   -> error: 'promedio' es privado

    cout << endl << "--- Metodos set ---" << endl;
    alumno2.setPromedio(88.5);
    alumno2.setCurso(&curso3);
    alumno2.setTutor(&profesor3);
    alumno2.verDatos();

    cout << endl << "--- Metodos get ---" << endl;
    cout << "Nombre: " << alumno2.getNombre() << endl;
    cout << "Promedio: " << alumno2.getPromedio() << endl;

    // los get de los atributos de tipo clase devuelven un puntero
    Curso *cursoDelAlumno = alumno2.getCurso();
    cout << "Curso: " << cursoDelAlumno->getNombre() << endl;

    Profesor *tutorDelAlumno = alumno2.getTutor();
    cout << "Tutor: " << tutorDelAlumno->getNombre() << endl;

    // metodos propios de cada clase
    cout << endl << "--- Metodos de cada clase ---" << endl;
    alumno2.estudiar();
    profesor3.impartirClase();
    curso3.iniciarCurso();

    return 0;
}
