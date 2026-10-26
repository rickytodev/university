#include "./helpers/persona.h"
#include "./helpers/empleado.h"
#include "./helpers/gerente.h"

#include <iostream>

using namespace std;

int main () {
    // orden de construccion: siempre de la clase base hacia la derivada
    cout << "--- Orden de constructores ---" << endl;
    Persona persona("Luis Ramirez", 20, "RALL060101HJCMSS01");
    cout << endl;
    Empleado empleado("Ana Torres", 28, "TOAA980202MJCRNN02", "Programadora", 25000);
    cout << endl;
    Gerente gerente("Ricardo Vega", 35, "VERR910303HJCGCC03", 45000, "Sistemas", 60000);

    // constructores vacios: tambien llaman al constructor vacio del padre
    cout << endl << "--- Constructores vacios ---" << endl;
    Gerente gerenteVacio;

    // cada clase muestra sus datos y los de sus padres
    cout << endl << "--- Datos de cada clase ---" << endl;
    persona.verDatos();
    cout << endl;
    empleado.verDatos();
    cout << endl;
    gerente.verDatos();

    // herencia: Gerente usa metodos que nunca definio
    cout << endl << "--- Metodos heredados ---" << endl;
    gerente.caminar();     // definido en Persona
    gerente.trabajar();    // definido en Empleado
    gerente.setEdad(36);   // set de Persona
    cout << "Nueva edad del gerente: " << gerente.getEdad() << endl;
    cout << "Puesto del gerente: " << gerente.getPuesto() << endl;

    // metodos propios: solo existen en la clase que los define
    cout << endl << "--- Metodos propios ---" << endl;
    empleado.trabajar();
    gerente.dirigirReunion();
    // persona.trabajar();       -> error: Persona no tiene 'trabajar'
    // empleado.dirigirReunion();-> error: Empleado no tiene 'dirigirReunion'

    // sobreescritura: el mismo metodo se comporta distinto en cada clase
    cout << endl << "--- Sobreescritura ---" << endl;
    persona.presentarse();
    empleado.presentarse();
    gerente.presentarse();

    cout << "Pago anual del empleado: $" << empleado.calcularPagoAnual() << endl;
    cout << "Pago anual del gerente:  $" << gerente.calcularPagoAnual() << endl;

    // operador de ambito: se llama a la version de un padre especifico
    cout << endl << "--- Operador de ambito (::) ---" << endl;
    gerente.Persona::presentarse();
    gerente.Empleado::presentarse();
    cout << "Pago anual sin bono: $" << gerente.Empleado::calcularPagoAnual() << endl;

    // encapsulamiento: protected y private siguen ocultos desde fuera
    // gerente.nombre = "X";        -> error: 'nombre' es protected
    // gerente.bono = 0;            -> error: 'bono' es private
    cout << endl << "--- Encapsulamiento ---" << endl;
    cout << "CURP del gerente (private en Persona): " << gerente.getCurp() << endl;

    // polimorfismo: un puntero a la clase base puede apuntar a cualquier hija
    // y, al ser virtual, se ejecuta el metodo del objeto real
    cout << endl << "--- Polimorfismo ---" << endl;
    Persona *personas[3] = { &persona, &empleado, &gerente };

    for (int i = 0; i < 3; i++) {
        personas[i]->presentarse();
    }

    // memoria dinamica + destructor virtual: delete sobre un Persona*
    // ejecuta los destructores de Gerente, Empleado y Persona
    cout << endl << "--- Destructor virtual ---" << endl;
    Persona *dinamico = new Gerente("Maria Lopez", 40, "LOMM860404MJCPRR04", 50000, "Ventas", 70000);
    dinamico->presentarse();
    delete dinamico;

    // al terminar main se destruyen los objetos estaticos en orden inverso:
    // de la clase derivada hacia la base
    cout << endl << "--- Fin del programa (orden de destructores) ---" << endl;

    return 0;
}
