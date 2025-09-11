#include "ListaAlumnos.h"
#include <iostream>
#include <vector>
using namespace std;

ListaAlumnos::ListaAlumnos() { cabeza = nullptr; }

ListaAlumnos::~ListaAlumnos() {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        NodoAlumno* temp = actual;
        actual = actual->siguiente;
        delete temp->alumno;
        delete temp;
    }
}

void ListaAlumnos::agregar(Alumno* alumno) {
    NodoAlumno* nuevo = new NodoAlumno(alumno);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}
bool ListaAlumnos::buscarPorNombre(const vector<string> &palabras) {
    NodoAlumno* actual = cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        string nombreAlumno = actual->alumno->getName();
        string apellidoAlumno = actual->alumno->getApellido();

        // Recorremos todas las palabras ingresadas
        for (const auto &p : palabras) {
            if (p == nombreAlumno || p == apellidoAlumno) {
                actual->alumno->mostrarAlumno();
                encontrado = true;
                break; // una coincidencia basta, no necesitamos revisar más palabras para este alumno
            }
        }

        actual = actual->siguiente;
    }

    return encontrado;
}




Alumno* ListaAlumnos::buscarPorId(int id) {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        if (actual->alumno->getId() == id)
            return actual->alumno;
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaAlumnos::eliminar(int id) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* anterior = nullptr;

    while (actual != nullptr && actual->alumno->getId() != id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr)
        return;

    if (anterior == nullptr) {
        cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual->alumno;
    delete actual;
}

void ListaAlumnos::mostrar() {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        actual->alumno->mostrarAlumno();
        actual = actual->siguiente;
    }
}
