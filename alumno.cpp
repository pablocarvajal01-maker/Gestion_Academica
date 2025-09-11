#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(string name,string apellido, string carrera,int yearDeIngreso,int id){
    this->name=name;
    this->apellido=apellido;
    this->carrera=carrera;
    this->yearDeIngreso=yearDeIngreso;
    this->id=id;

}
Alumno::~Alumno() {
    cout << "Alumno eliminado: " << name << " " << apellido << endl;
}

int Alumno::getId(){
    return id;
}
string Alumno::getName(){
    return name;
}
string Alumno::getApellido(){
    return apellido;
}
string Alumno::getCarrera(){
    return carrera;
}
void Alumno::mostrarAlumno(){
    cout<<"-Alumno: "<<name<<" "<<apellido<<"\n-Curso: "<<carrera<<"\n-Ingresado en: "<<yearDeIngreso<<"\nId: "<<id<<endl;
}
void Alumno::setCarrera(string nuevoProposito, int nuevoIngreso){
    carrera=nuevoProposito;
    if (nuevoIngreso<yearDeIngreso) {
        yearDeIngreso=nuevoIngreso;
    }
}