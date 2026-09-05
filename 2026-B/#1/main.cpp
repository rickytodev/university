#include <iostream>
#include <string>
#include "helpers/persona.h"

using namespace std;

int main() {
    Persona per1("John", 12);
    Persona per2;

    cout << per1.nombre << endl;
    cout << per1.getEdad() << endl;

    per1.setEdad(20);
    cout << per1.getEdad() << endl;

    per1.hablar("Hola, como estas?");
    per2.hablar("Bien, gracias!");

    return 0;
}
