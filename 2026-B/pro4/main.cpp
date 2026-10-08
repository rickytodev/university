#include <string>
#include <iostream>
#include "./helpers/person.h"
#include "./helpers/work.h"

using namespace std;

/*
    1) ¿Para que sirve la palabra reservada friend?
        Sirve para que una función o clase tenga acceso a los miembros privados y protegidos de otra clase, aunque no pertenezca a ella.

    2) Existen dos formas de hacer la sobrecarga de operadores, explique cada una de ellas
        a) ¿Como sobrecarga de operador miembro?
            Se realiza dentro de la clase y tiene acceso a los miembros privados y protegidos. Normalmente se pasa un solo argumento, ya que el primer operando es implícitamente el objeto que llama al operador.

        b) ¿Como sobrecarga de operador amigo?
            Se declara como `friend` dentro de la clase, pero se implementa fuera de ella. Tiene acceso a los miembros privados y protegidos de la clase. Normalmente recibe dos argumentos, ya que ninguno de los operandos es implícitamente el objeto que llama al operador.

    3) Como conclusión existe una ventaja en hacer desarrollo de operadores, si/no, justifique su respuesta.
        Si, ya que permite definir el comportamiento de los operadores para tipos de datos definidos por el usuario, lo que hace que el código sea más intuitivo y fácil de leer. Esto permite que los objetos puedan interactuar de manera más natural, similar a los tipos de datos primitivos, mejorando la legibilidad y mantenibilidad del código.
*/

int main() {
    // constructor vacio
    Person vacio;

    cout << "--- Constructor vacio ---" << endl;
    vacio.viewData();

    // primera sobrecarga del constructor: solo el nickname
    Person soloNickname("lia07");

    cout << endl << "--- Constructor con un parametro ---" << endl;
    soloNickname.viewData();

    // segunda sobrecarga del constructor: fullname, age, weight y nickname
    // estas son las dos instancias con las que se hace la suma y la resta
    Person persona1("Ricardo Vega", 28, 78.5, "ricardo_vega");
    Person persona2("Ana Torres", 24, 62.3, "ana24");

    // el trabajo es una clase, al asignarlo se copian el rol y el salario
    persona1.assignWork(Work("Desarrollador Backend", 6, 32500.0));
    persona2.assignWork(Work("Analista de Datos", 3, 21000.0));

    cout << endl << "--- Persona 1 ---" << endl;
    persona1.viewData();

    cout << endl << "--- Persona 2 ---" << endl;
    persona2.viewData();

    // suma con el operador miembro: une los nicknames de las dos personas
    Person suma = persona1 + persona2;

    cout << endl << "--- Suma (operador miembro) ---" << endl;
    cout << "persona1 + persona2 = " << suma.nickname << endl;
    suma.viewData();

    // resta con el operador amigo: se queda con el nickname mas corto
    Person resta = persona1 - persona2;

    cout << endl << "--- Resta (operador amigo) ---" << endl;
    cout << "persona1 - persona2 = " << resta.nickname << endl;
    resta.viewData();

    return 0;
}
