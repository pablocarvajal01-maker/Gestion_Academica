#ifndef ALUMNO_H
#define ALUMNO_H
#include "Curso.h"
#include <string>
using namespace std;


class ListaNotas;


class NodoCursoAlumno {
public:
    Curso* curso;
    NodoCursoAlumno* siguiente;
    NodoCursoAlumno(Curso* c) : curso(c), siguiente(nullptr) {}
    ~NodoCursoAlumno() {
    }

};

class ListaCursosAlumno {
protected:
    NodoCursoAlumno* cabeza;
public:
    ListaCursosAlumno() : cabeza(nullptr) {}
    ~ListaCursosAlumno() {
        NodoCursoAlumno* actual = cabeza;
        while(actual) {
            NodoCursoAlumno* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    NodoCursoAlumno* getCabeza() { return cabeza; }

    void agregar(Curso* c) {
        NodoCursoAlumno* nuevo = new NodoCursoAlumno(c);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    bool eliminar(string codigoCurso) {
        NodoCursoAlumno* actual = cabeza;
        NodoCursoAlumno* anterior = nullptr;
        while(actual && actual->curso->getCodigo() != codigoCurso) {
            anterior = actual;
            actual = actual->siguiente;
        }
        if(!actual) return false;
        if(!anterior) cabeza = actual->siguiente;
        else anterior->siguiente = actual->siguiente;
        delete actual;
        return true;
    }
};


class NodoAlumnoCurso;
class ListaAlumnosCurso;

class Alumno {
private:
    string name;
    string apellido;
    string carrera;
    int yearDeIngreso;
    int id;
    ListaCursosAlumno cursos;
    class ListaNotas* notas;

public:
    Alumno(string name,string apellido, string carrera,int yearDeIngreso,int id);
    ~Alumno();
    int getId();
    string getName() ;
    string getApellido() ;
    string getCarrera() ;
    void mostrarAlumno() ;
    void setCarrera(string nuevoProposito,int nuevoIngreso) ;
    void eliminarAlumno() ;
    void inscribirCurso(Curso* c) { cursos.agregar(c); }
    void expulsarCurso(string codigoCurso) { cursos.eliminar(codigoCurso); }
    void agregarNota(Curso* c, float valor) ;
    void modificarNota(Curso* c, float valor) ;
};

#endif
