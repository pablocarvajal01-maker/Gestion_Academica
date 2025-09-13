#ifndef NOTAS_H
#define NOTAS_H

class Curso;

class NodoValor {
public:
    float valor;
    NodoValor* siguiente;
    NodoValor(float v) : valor(v), siguiente(0) {}
};

class Notas {
private:
    Curso* curso;
    NodoValor* cabeza;

public:
    Notas(Curso* c) : curso(c), cabeza(0) {}
    ~Notas() {
        NodoValor* actual = cabeza;
        while(actual) {
            NodoValor* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    Curso* getCurso() const { return curso; }


    NodoValor* getInicio() const { return cabeza; }

    void agregarNota(float v) {
        NodoValor* nuevo = new NodoValor(v);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    float promedio() const {
        if (!cabeza) return 0;
        int cantidad = 0;
        float suma = 0;
        NodoValor* actual = cabeza;
        while(actual) {
            suma += actual->valor;
            cantidad++;
            actual = actual->siguiente;
        }
        return (cantidad > 0) ? suma / cantidad : 0;
    }
};

class NodoNotas {
public:
    Notas* notas;
    NodoNotas* siguiente;
    NodoNotas(Notas* n) : notas(n), siguiente(0) {}
    ~NodoNotas() { delete notas; }
};

class ListaNotas {
private:
    NodoNotas* cabeza;

public:
    ListaNotas() : cabeza(0) {}
    ~ListaNotas() {
        NodoNotas* actual = cabeza;
        while(actual) {
            NodoNotas* temp = actual;
            actual = actual->siguiente;
            delete temp;
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
            if (actual->notas->getCurso() == c)
                return actual->notas;
            actual = actual->siguiente;
        }
        return 0;
    }

    NodoNotas* getInicio() { return cabeza; }
};

#endif
