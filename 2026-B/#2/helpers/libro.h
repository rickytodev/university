#ifndef LIBRO_H
#define LIBRO_H

#include <string>

using namespace std;

class Libro {
    private:
        int anio;
        int paginas;
        bool prestado;

    public:
        string titulo;
        string autor;

        Libro(string titulo, string autor, int anio, int paginas);

        void prestar();
        void devolver();
        void verDatos();
        int obtenerAnio();
        int obtenerPaginas();
        bool estaPrestado();

        void cambiarAnio(int anio);
        void cambiarPaginas(int paginas);
};

#endif

