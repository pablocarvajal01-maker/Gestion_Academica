#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H
#include <vector>
#include "NodoAlumno.h"

class ListaAlumnos {
private:
    NodoAlumno* cabeza;

public:
    ListaAlumnos();
    ~ListaAlumnos();

    void agregar(Alumno* alumno);
    Alumno* buscarPorId(int id);
    bool buscarPorNombre(const vector<string> &palabras);
    void eliminar(int id);
    void mostrar();
};

#endif
