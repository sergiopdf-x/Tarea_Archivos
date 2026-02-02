#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Publicacion {
protected:
    string codigo, titulo;
    int anio;
    bool prestado;

public:
    Publicacion(string c, string t, int a)
        : codigo(c), titulo(t), anio(a), prestado(false) {}

    void prestar() { prestado = true; }
    void devolver() { prestado = false; }

    string info() {
        return codigo + " " + titulo + " " + to_string(anio) +
               (prestado ? " Prestado" : " Disponible");
    }

    bool estaPrestado() { return prestado; }
};

int main() {
    Publicacion libro("L01", "C++ Basico", 2020);
    libro.prestar();

    ofstream prestados("LibrosPrestados.txt");
    ofstream stock("LibrosEnStock.txt");

    if (libro.estaPrestado())
        prestados << libro.info();
    else
        stock << libro.info();

    prestados.close();
    stock.close();
    return 0;
}
