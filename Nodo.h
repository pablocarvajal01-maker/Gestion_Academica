#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

#include "Alumno.h"
#include "Curso.h"
#include <string>
using namespace std;


class NodoAlumno {
private:
    Alumno* alumno;
    NodoAlumno* siguiente;
public:
    NodoAlumno(Alumno* a) : alumno(a), siguiente(nullptr) {}
    ~NodoAlumno() {
        delete alumno;
    }
    Alumno* getAlumno() const { return alumno; }
    NodoAlumno* getSiguiente() const { return siguiente; }
    void setAlumno(Alumno* a) { alumno = a; }
    void setSiguiente(NodoAlumno* sig) { siguiente = sig; }
};



class ListaAlumnos {
private:
    NodoAlumno* cabeza;

public:
    ListaAlumnos();
    ~ListaAlumnos();

    void agregar(Alumno* alumno);
    Alumno* buscarPorId(int id);
    bool buscarPorNombre(string palabras[], int cantidad);
    void eliminar(int id);
    void mostrar();
    NodoAlumno* getTop() { return cabeza; }
};

class NodoCurso {
private:
    Curso* curso;
    NodoCurso* siguiente;

public:
    NodoCurso(Curso* curso) {
        this->curso = curso;
        this->siguiente = nullptr;
    }

    ~NodoCurso() {
        delete curso;
    }

    Curso* getCurso() const { return curso; }
    NodoCurso* getSiguiente() const { return siguiente; }
    void setSiguiente(NodoCurso* sig) { siguiente = sig; }
};


class ListaCursos {
private:
    NodoCurso* cabeza;

public:
    ListaCursos();
    ~ListaCursos();

    void agregar(Curso* curso);
    Curso* buscarPorCodigo(string codigo);
    bool eliminar(string codigo);
    void mostrar();
};



#endif
