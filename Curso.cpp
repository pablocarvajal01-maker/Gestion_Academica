#include "Alumno.h"
#include <iostream>
using namespace std;

Curso::Curso(string codigo, string nombre, string carrera, string profesor,int cupoMax,int cupoActual) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->carrera = carrera;
    this->profesor = profesor;
    this->cupoMax = cupoMax;
    this ->cupoActual = cupoActual;
}
Curso::~Curso() {
    cout << "Curso eliminado: " << nombre<< " " << carrera << endl;
}
string Curso::getCodigo() {
    return codigo;
}
string Curso::getNombre() {
    return nombre;
}
string Curso::getCarrera() {
    return carrera;
}
void Curso::getCupo() {
    cout<<"Curso "<<nombre<<": "<<cupoActual<<" de"<<cupoMax<<endl;
}
void Curso::setCupoActual(int valor) {
    cupoActual = this->cupoActual+valor;
}
void Curso::mostrarInfo() {
    cout<<"-Curso: "<<nombre<<"\n-Codigo: "<<codigo<<"\n-Impartido por: "<<profesor<<"\nCarrera: "<<carrera<<"\nCupos: "<<cupoActual<<" de "<<cupoMax<<endl;
}

