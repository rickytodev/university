#include <iostream>
#include "./helpers/vector3d.h"

using namespace std;

/*
    Actividad: sobrecarga de operadores

    La clase Vector3D tiene 3 atributos privados (x, y, z) con sus get y set.

    Operadores binarios:
        +  funcion miembro       suma componente a componente
        -  funcion miembro       resta componente a componente
        *  funcion amiga         producto componente a componente
        /  funcion amiga         division componente a componente

    Operadores de flujo:
        <<  funcion amiga        imprime el vector como (x, y, z)
        >>  funcion amiga        pide las tres componentes al usuario

    Los operadores de flujo no pueden ser funciones miembro porque el operando
    de la izquierda es el stream (cout / cin) y no un objeto Vector3D.
*/

int main() {
    // constructor vacio: deja el vector en (0, 0, 0)
    Vector3D vacio;

    cout << "--- Constructor vacio ---" << endl;
    cout << "vacio = " << vacio << endl;

    // constructor con parametros
    Vector3D a(6.0, 8.0, 10.0);
    Vector3D b(3.0, 2.0, 5.0);

    cout << endl << "--- Vectores iniciales ---" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // uso de los setters sobre el vector vacio
    vacio.setX(1.0);
    vacio.setY(2.0);
    vacio.setZ(3.0);

    cout << endl << "--- Setters y getters ---" << endl;
    cout << "despues de los setters: " << vacio << endl;
    cout << "getX() = " << vacio.getX() << endl;
    cout << "getY() = " << vacio.getY() << endl;
    cout << "getZ() = " << vacio.getZ() << endl;

    // operadores binarios
    cout << endl << "--- Operadores binarios ---" << endl;
    cout << "a + b = " << (a + b) << "   (funcion miembro)" << endl;
    cout << "a - b = " << (a - b) << "   (funcion miembro)" << endl;
    cout << "a * b = " << (a * b) << "   (funcion amiga)" << endl;
    cout << "a / b = " << (a / b) << "   (funcion amiga)" << endl;

    // los operadores devuelven un Vector3D, asi que se pueden encadenar
    Vector3D combinado = (a + b) - (b * b) / b;

    cout << endl << "--- Operaciones encadenadas ---" << endl;
    cout << "(a + b) - (b * b) / b = " << combinado << endl;
    cout << "magnitud del resultado = " << combinado.magnitud() << endl;

    // caso de division entre cero: el operador avisa y deja la componente en 0
    Vector3D ceros;

    cout << endl << "--- Division entre cero ---" << endl;

    // se calcula antes de imprimir para que los avisos no salgan a media linea
    Vector3D entreCeros = a / ceros;

    cout << "a / ceros = " << entreCeros << endl;

    // operador de extraccion: lee las tres componentes desde el teclado
    Vector3D leido;

    cout << endl << "--- Operador >> (captura) ---" << endl;
    cout << "Captura las componentes de un vector:" << endl;
    cin >> leido;

    cout << endl << "--- Resultados con el vector capturado ---" << endl;
    cout << "leido     = " << leido << endl;
    cout << "a + leido = " << (a + leido) << endl;
    cout << "a - leido = " << (a - leido) << endl;
    cout << "a * leido = " << (a * leido) << endl;
    cout << "a / leido = " << (a / leido) << endl;

    return 0;
}
