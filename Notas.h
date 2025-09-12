#ifndef NOTAS_H
#define NOTAS_H

class Curso;

class Notas {
private:
    Curso* curso;
    float nota;

public:
    Notas(Curso* c, float n = 0) : curso(c), nota(n) {}
    void setNota(float n) { nota = n; }
    float getNota() const { return nota; }
    Curso* getCurso() const { return curso; }
};

class NodoNotas {
public:
    Notas* nota;
    NodoNotas* siguiente;
    NodoNotas(Notas* n) : nota(n), siguiente(nullptr) {}
    ~NodoNotas() { delete nota; }  // Se libera la nota al eliminar el nodo
};

class ListaNotas {
private:
    NodoNotas* cabeza;

public:
    ListaNotas() : cabeza(nullptr) {}
    ~ListaNotas() {
        NodoNotas* actual = cabeza;
        while(actual) {
            NodoNotas* temp = actual;
            actual = actual->siguiente;
            delete temp;  // Esto elimina el nodo y la nota contenida
        }
    }

    void agregar(Notas* n) {
        NodoNotas* nuevo = new NodoNotas(n);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    Notas* buscarPorCurso(Curso* c) {
        NodoNotas* actual = cabeza;
        while(actual) {
            if(actual->nota->getCurso() == c)
                return actual->nota;
            actual = actual->siguiente;
        }
        return nullptr;
    }
};


#endif
