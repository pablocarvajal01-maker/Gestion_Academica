#ifndef NODOALUMNO_H
#define NODOALUMNO_H

#include "Alumno.h"

struct NodoAlumno {
    Alumno* alumno;
    NodoAlumno* siguiente;

    NodoAlumno(Alumno* alumno) {
        this->alumno = alumno;
        this->siguiente = nullptr;
    }
};

#endif
