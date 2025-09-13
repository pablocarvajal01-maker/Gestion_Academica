#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

class Alumno;
class NodoAlumnoCurso {
public:
    Alumno* alumno;
    NodoAlumnoCurso* siguiente;
    NodoAlumnoCurso(Alumno* a) : alumno(a), siguiente(nullptr) {}
};
class ListaAlumnosCurso {
private:
    NodoAlumnoCurso* cabeza;
public:
    ListaAlumnosCurso() : cabeza(nullptr) {}
    ~ListaAlumnosCurso() {
        NodoAlumnoCurso* actual = cabeza;
        while(actual) {
            NodoAlumnoCurso* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    NodoAlumnoCurso* getCabeza(){return cabeza;}
    void agregar(Alumno* a) {
        NodoAlumnoCurso* nuevo = new NodoAlumnoCurso(a);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
    bool eliminar(int idAlumno);
};
class Curso {
private:
    string codigo;
    string nombre;
    string carrera;
    string profesor;
    int cupoMax;
    int cupoActual;
    ListaAlumnosCurso alumnos;

public:
    Curso(string codigo, string nombre, string carrera, string profesor, int cupoMax, int cupoActual);
    ~Curso();
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    string getCarrera() const { return carrera; }


    int getCupo() const { return cupoActual; }
    void setCupoActual(int incremento) { cupoActual += incremento; }
    void mostrarInfo() ;

    bool inscribirAlumno(Alumno* a);
    bool expulsarAlumno(int idAlumno);
};

#endif
