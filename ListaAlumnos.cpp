
#include <iostream>

#include "Nodo.h"

using namespace std;

ListaAlumnos::ListaAlumnos() { cabeza = nullptr; }

ListaAlumnos::~ListaAlumnos() {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        NodoAlumno* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}


void ListaAlumnos::agregar(Alumno* alumno) {
    NodoAlumno* nuevo = new NodoAlumno(alumno);
    nuevo->setSiguiente(cabeza);
    cabeza = nuevo;
}

bool ListaAlumnos::buscarPorNombre(string palabras[], int cantidad) {
    NodoAlumno* actual = cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        string nombreAlumno = actual->getAlumno()->getName();
        string apellidoAlumno = actual->getAlumno()->getApellido();


        for (int i = 0; i < cantidad; i++) {
            if (palabras[i] == nombreAlumno || palabras[i] == apellidoAlumno) {
                actual->getAlumno()->mostrarAlumno();
                encontrado = true;
                break;
            }
        }

        actual = actual->getSiguiente();
    }

    return encontrado;
}

Alumno* ListaAlumnos::buscarPorId(int id) {
    NodoAlumno* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getAlumno()->getId() == id)
            return actual->getAlumno();
        actual = actual->getSiguiente();
    }
    return nullptr;
}

void ListaAlumnos::eliminar(int id) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* anterior = nullptr;

    while (actual != nullptr && actual->getAlumno()->getId() != id) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr)
        return;

    if (anterior == nullptr) {
        cabeza = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual->getAlumno();
    delete actual;
}

void ListaAlumnos::mostrar() {
    NodoAlumno* actual = cabeza;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    while (actual != nullptr) {
        actual->getAlumno()->mostrarAlumno();
        actual = actual->getSiguiente();
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
}
