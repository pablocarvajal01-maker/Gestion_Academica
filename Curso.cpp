#include "Alumno.h"
#include "Curso.h"
#include <iostream>
using namespace std;

Curso::Curso(string codigo, string nombre, string carrera, string profesor, int cupoMax, int cupoActual) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->carrera = carrera;
    this->profesor = profesor;
    this->cupoMax = cupoMax;
    this->cupoActual = cupoActual;
}

Curso::~Curso() {
    cout << "-Curso eliminado: " << nombre << " " << carrera << endl;
}

void Curso::mostrarInfo() {
    cout << "-Curso: " << nombre
         << "\n-Codigo: " << codigo
         << "\n-Impartido por: " << profesor
         << "\n-Carrera: " << carrera
         << "\n-Cupos: " << cupoActual << " de " << cupoMax
         << endl;
}
bool Curso::inscribirAlumno(Alumno* a) {
    if (cupoActual >= cupoMax) {
        cout << "No hay cupo disponible para el alumno " << a->getName() << endl;
        return false;
    }
    alumnos.agregar(a);
    a->inscribirCurso(this);
    cupoActual++;
    return true;
}
bool Curso::expulsarAlumno(int idAlumno) {
    NodoAlumnoCurso* actual = alumnos.getCabeza();
    while(actual) {
        if(actual->alumno->getId() == idAlumno) {
            actual->alumno->expulsarCurso(codigo);
            break;
        }
        actual = actual->siguiente;
    }

    bool eliminado = alumnos.eliminar(idAlumno);
    if(eliminado) {
        cupoActual--;
        return true;
    }
    return false;
}
bool ListaAlumnosCurso::eliminar(int idAlumno) {
    NodoAlumnoCurso* actual = cabeza;
    NodoAlumnoCurso* anterior = nullptr;

    while(actual && actual->alumno->getId() != idAlumno) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if(!actual) return false;

    if(!anterior)
        cabeza = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
    return true;
}

