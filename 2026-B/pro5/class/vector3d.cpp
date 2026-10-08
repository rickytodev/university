#include "../helpers/vector3d.h"
#include <iostream>
#include <cmath>

using namespace std;

Vector3D::Vector3D() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3D::Vector3D(float x, float y, float z) {
    // usamos this porque los parametros se llaman igual que los atributos
    this->x = x;
    this->y = y;
    this->z = z;
}

// los getters devuelven una copia del atributo privado
float Vector3D::getX() { return x; }
float Vector3D::getY() { return y; }
float Vector3D::getZ() { return z; }

// los setters son el unico punto donde se modifican los atributos privados
void Vector3D::setX(float x) { this->x = x; }
void Vector3D::setY(float y) { this->y = y; }
void Vector3D::setZ(float z) { this->z = z; }

float Vector3D::magnitud() {
    return sqrt(x * x + y * y + z * z);
}

// suma como funcion miembro: this es el operando de la izquierda
Vector3D Vector3D::operator+(Vector3D other) {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

// resta como funcion miembro
Vector3D Vector3D::operator-(Vector3D other) {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

// producto como funcion amiga no miembro: multiplica componente por componente
// al ser amiga puede leer a.x, b.x, etc. aunque sean privados
Vector3D operator*(Vector3D a, Vector3D b) {
    return Vector3D(a.x * b.x, a.y * b.y, a.z * b.z);
}

// division como funcion amiga no miembro
// si el divisor es cero dejamos la componente en cero para no romper el programa
Vector3D operator/(Vector3D a, Vector3D b) {
    Vector3D resultado;

    if (b.x != 0.0) {
        resultado.x = a.x / b.x;
    } else {
        cout << "Aviso: division entre cero en la componente X, se deja en 0" << endl;
    }

    if (b.y != 0.0) {
        resultado.y = a.y / b.y;
    } else {
        cout << "Aviso: division entre cero en la componente Y, se deja en 0" << endl;
    }

    if (b.z != 0.0) {
        resultado.z = a.z / b.z;
    } else {
        cout << "Aviso: division entre cero en la componente Z, se deja en 0" << endl;
    }

    return resultado;
}

// operador de insercion: devuelve el stream por referencia para poder encadenar
// cout << v1 << v2 << endl;
ostream &operator<<(ostream &salida, Vector3D vector) {
    salida << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return salida;
}

// operador de extraccion: el vector va por referencia porque se va a modificar
istream &operator>>(istream &entrada, Vector3D &vector) {
    cout << "X: ";
    entrada >> vector.x;
    cout << "Y: ";
    entrada >> vector.y;
    cout << "Z: ";
    entrada >> vector.z;
    return entrada;
}
