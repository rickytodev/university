#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

using namespace std;

class Vector3D {
    public:
        Vector3D();
        Vector3D(float x, float y, float z);

        // getters: unica forma de leer los atributos privados desde afuera
        float getX();
        float getY();
        float getZ();

        // setters: unica forma de escribir los atributos privados desde afuera
        void setX(float x);
        void setY(float y);
        void setZ(float z);

        float magnitud();

        // operadores binarios como funciones miembro
        // el primer operando es implicito (this), por eso solo reciben un parametro
        Vector3D operator+(Vector3D other);
        Vector3D operator-(Vector3D other);

        // operadores binarios como funciones amigas no miembro
        // reciben los dos operandos porque no pertenecen a la clase
        friend Vector3D operator*(Vector3D a, Vector3D b);
        friend Vector3D operator/(Vector3D a, Vector3D b);

        // operadores de flujo, siempre van como funciones amigas no miembro
        // porque el operando izquierdo es el stream, no el objeto
        friend ostream &operator<<(ostream &salida, Vector3D vector);
        friend istream &operator>>(istream &entrada, Vector3D &vector);
    private:
        float x;
        float y;
        float z;
};

#endif
