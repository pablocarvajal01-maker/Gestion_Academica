#include <iostream>
#include "Nodo.h"
using namespace std;

ListaCursos::ListaCursos() { cabeza = nullptr; }

ListaCursos::~ListaCursos() {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        NodoCurso* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void ListaCursos::agregar(Curso* curso) {
    NodoCurso* nuevo = new NodoCurso(curso);
    nuevo->setSiguiente(cabeza);
    cabeza = nuevo;
}

Curso* ListaCursos::buscarPorCodigo(string codigo) {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getCurso()->getCodigo() == codigo)
            return actual->getCurso();
        actual = actual->getSiguiente();
    }
    return nullptr;
}

bool ListaCursos::eliminar(string codigo) {
    NodoCurso* actual = cabeza;
    NodoCurso* anterior = nullptr;


    while (actual != nullptr && actual->getCurso()->getCodigo() != codigo) {
        anterior = actual;
        actual = actual->getSiguiente();
    }


    if (actual == nullptr) return false;

    if (anterior == nullptr) {

        cabeza = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual;
    return true;
}



void ListaCursos::mostrar() {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        actual->getCurso()->mostrarInfo();
        cout << "~~~~~~~~~~~~~~~~~++~~~~~~~~~~~~~" << endl;
        actual = actual->getSiguiente();
    }
}
