#include <iostream>
#include <string>
#include "./helpers/persona.h"

using namespace std;

int main() {
    // pointers
    int a = 6;
    int *ptr = &a;
    int *ptr2 = new int(6);

    cout << "Valor de a: "<< a << endl;
    cout << "Valor de ptr: "<< *ptr << endl;
    cout << "Valor de ptr2: "<< *ptr2 << endl;
    cout << "Direccion de a: "<< &a << endl;
    cout << "Direccion de ptr: "<< ptr << endl;
    cout << "Direccion de ptr2: "<< ptr2 << endl;

    // vectors
    int vec[5] = {45, 12, 56, 8, 9};

    for (int i = 0; i < 5; i++) {
        cout << *(vec + i) << endl;
    }

    // clases con punteros

    Persona *persona = new Persona();

    cout << "Nombre: " << persona->nombre << endl;
    cout << "Edad: " << persona->getEdad() << endl;

    persona->nombre = "Pedro";
    persona->setEdad(25);

    cout << "Nombre: " << persona->nombre << endl;
    cout << "Edad: " << persona->getEdad() << endl;

    Persona *persona2 = new Persona("Maria", 30);

    cout << "Nombre: " << persona2->nombre << endl;
    cout << "Edad: " << persona2->getEdad() << endl;


    // puntero sobre puntero
    int **ptr3 = &ptr2;  // ptr3 apunta a ptr2, que apunta a un int

    cout << "Valor de ptr3: " << **ptr3 << endl;  // imprime el valor al que apunta ptr2

    return 0;
}
