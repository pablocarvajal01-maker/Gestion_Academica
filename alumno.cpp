#include "Alumno.h"
#include "Notas.h"
#include <iostream>
using namespace std;

Alumno::Alumno(string name, string apellido, string carrera, int yearDeIngreso, int id) {
    this->name = name;
    this->apellido = apellido;
    this->carrera = carrera;
    this->yearDeIngreso = yearDeIngreso;
    this->id = id;
    this->notas = new ListaNotas();
}

Alumno::~Alumno() {
    delete notas;
    cout << "Alumno eliminado: " << name << " " << apellido << endl;
}

int Alumno::getId() { return id; }
string Alumno::getName() { return name; }
string Alumno::getApellido() { return apellido; }
string Alumno::getCarrera() { return carrera; }

void Alumno::mostrarAlumno() {

    cout <<"---------------------------------\n"<<"-Alumno: " << name << " " << apellido<< "\n-Carrera: " << carrera<< "\n-Ingresado en: " << yearDeIngreso<< "\n-Id: " << id <<"------------------------------------"<< endl;
}

void Alumno::setCarrera(string nuevoProposito, int nuevoIngreso) {
    carrera = nuevoProposito;
    if (nuevoIngreso < yearDeIngreso) {
        yearDeIngreso = nuevoIngreso;
    }
}

void Alumno::eliminarAlumno() {
    NodoCursoAlumno* curso = cursos.getCabeza();
    while(curso) {
        expulsarCurso(curso->curso->getCodigo());
        curso = cursos.getCabeza();
    }
}

void Alumno::agregarNota(Curso* c, float valor) {
    if (!notas) return;
    Notas* n = notas->buscarPorCurso(c);
    if (!n) {
        n = new Notas(c);
        notas->agregar(n);
    }
    n->agregarNota(valor);
}

void Alumno::modificarNota(Curso* c, float valor) {
    if (!notas) return;
    Notas* n = notas->buscarPorCurso(c);
    if (!n) {
        n = new Notas(c);
        notas->agregar(n);
        n->agregarNota(valor);
        return;
    }


    NodoValor* actual = n->getInicio();
    if (!actual) {
        n->agregarNota(valor);
        return;
    }


    while (actual->siguiente) {
        actual = actual->siguiente;
    }

    actual->valor = valor;
}



float Alumno::promedioCursoAlumno(Curso* c) {
    Notas* n = notas->buscarPorCurso(c);
    if (!n) return 0;
    return n->promedio();
}

float Alumno::promedioGeneralAlumno() {
    if (!notas) return 0;
    NodoNotas* actual = notas->getInicio();
    float suma = 0;
    int cantidad = 0;
    while(actual) {
        suma += actual->notas->promedio();
        cantidad++;
        actual = actual->siguiente;
    }
    return (cantidad > 0) ? suma / cantidad : 0;
}
