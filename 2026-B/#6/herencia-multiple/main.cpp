#include "./helpers/dispositivo.h"
#include "./helpers/telefono.h"
#include "./helpers/camara.h"
#include "./helpers/smartphone.h"

#include <iostream>

using namespace std;

int main () {
    // cada clase del diamante por separado
    cout << "--- Clases intermedias por separado ---" << endl;
    Telefono telefono("Nokia", "3310", "3312345678");
    cout << endl;
    Camara camara("Canon", "EOS R50", 24);

    // orden de construccion en el diamante:
    // Dispositivo (una sola vez) -> Telefono -> Camara -> Smartphone
    cout << endl << "--- Orden de constructores en el diamante ---" << endl;
    Smartphone smartphone("Samsung", "Galaxy S25", "3398765432", 200, "Android");

    cout << endl << "--- Constructor vacio ---" << endl;
    Smartphone smartphoneVacio;

    // herencia multiple: Smartphone tiene los metodos de sus dos padres
    // y los del abuelo
    cout << endl << "--- Metodos heredados de los tres niveles ---" << endl;
    smartphone.llamar("3311112222");    // de Telefono (apagado)
    smartphone.encender();              // de Dispositivo
    smartphone.llamar("3311112222");    // de Telefono
    smartphone.tomarFoto();             // de Camara
    smartphone.tomarFoto();
    smartphone.instalarApp("WhatsApp"); // propio de Smartphone
    smartphone.instalarApp("Spotify");

    cout << endl << "--- Datos de cada clase ---" << endl;
    telefono.verDatos();
    cout << endl;
    camara.verDatos();
    cout << endl;
    smartphone.verDatos();

    // operador de ambito: se elige la version de un padre especifico
    cout << endl << "--- Operador de ambito (::) ---" << endl;
    cout << "[Telefono::verDatos]" << endl;
    smartphone.Telefono::verDatos();
    cout << endl << "[Camara::verDatos]" << endl;
    smartphone.Camara::verDatos();

    // herencia virtual: solo existe UNA copia de Dispositivo.
    // si se cambia la marca desde el lado de Telefono, el lado de Camara
    // ve el mismo cambio porque es el mismo atributo
    cout << endl << "--- Una sola copia de Dispositivo ---" << endl;
    smartphone.Telefono::setMarca("Samsung Electronics");
    cout << "Marca vista desde Telefono: " << smartphone.Telefono::getMarca() << endl;
    cout << "Marca vista desde Camara:   " << smartphone.Camara::getMarca() << endl;
    cout << "Marca sin ambito:           " << smartphone.getMarca() << endl;

    // la direccion de la parte Dispositivo es la misma por ambos caminos
    Dispositivo *porTelefono = (Telefono *) &smartphone;
    Dispositivo *porCamara = (Camara *) &smartphone;
    cout << "Dispositivo por Telefono: " << porTelefono << endl;
    cout << "Dispositivo por Camara:   " << porCamara << endl;

    // sin 'virtual' en Telefono y Camara habria DOS copias de Dispositivo y:
    //   smartphone.getMarca();             -> error: ambiguo
    //   Dispositivo *d = &smartphone;      -> error: ambiguo
    // solo se podria usar smartphone.Telefono::getMarca() o Camara::getMarca()

    // polimorfismo: punteros a los padres o al abuelo apuntando al smartphone
    cout << endl << "--- Polimorfismo ---" << endl;
    Telefono *comoTelefono = &smartphone;
    Camara *comoCamara = &smartphone;
    comoTelefono->llamar("911");
    comoCamara->tomarFoto();

    Dispositivo *dispositivos[3] = { &telefono, &camara, &smartphone };

    for (int i = 0; i < 3; i++) {
        cout << endl;
        dispositivos[i]->verDatos();
    }

    // memoria dinamica: el destructor virtual de Dispositivo garantiza que
    // se destruyan las cuatro partes, en orden inverso a la construccion
    cout << endl << "--- Destructor virtual ---" << endl;
    Dispositivo *dinamico = new Smartphone("Apple", "iPhone 17", "3355550000", 48, "iOS");
    cout << endl;
    delete dinamico;

    cout << endl << "--- Fin del programa (orden de destructores) ---" << endl;

    return 0;
}
