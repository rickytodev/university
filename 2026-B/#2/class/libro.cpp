#include "../helpers/libro.h"
#include <iostream>
#include <string>

using namespace std;

Libro::Libro(string titulo, string autor, int anio, int paginas) {
    this->titulo = titulo;
    this->autor = autor;
    this->anio = anio;
    this->paginas = paginas;
    this->prestado = false;
}

void Libro::prestar() {
    this->prestado = true;
}

void Libro::devolver() {
    this->prestado = false;
}

void Libro::verDatos() {
    cout << "Título: " << this->titulo << endl;
    cout << "Autor: " << this->autor << endl;
    cout << "Año: " << this->anio << endl;
    cout << "Páginas: " << this->paginas << endl;
    cout << "Prestado: " << (this->prestado ? "Sí" : "No") << endl;
}

int Libro::obtenerAnio() {
    return this->anio;
}

int Libro::obtenerPaginas() {
    return this->paginas;
}

bool Libro::estaPrestado() {
    return this->prestado;
}

void Libro::cambiarAnio(int anio) {
    this->anio = anio;
}

void Libro::cambiarPaginas(int paginas) {
    this->paginas = paginas;
}
