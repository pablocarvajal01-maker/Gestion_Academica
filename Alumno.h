#pragma once
#include <string>
using namespace std;

class Alumno{
    private:
        string name;
        string apellido;
        string carrera;
        int yearDeIngreso;
        int id;
        
    public:
    //registro
    Alumno(string name,string apellido, string carrera,int yearDeIngreso,int id); //contructor
    //busqueda
    int getId();//mostrar id
    
    string getName();//mostrar nombre y apellido del alumno
    string getApellido();
    
    string getCarrera();//mostrar carrera y cuando ingreso
    
    void mostrarAlumno();//mostrar toda la informacion del alumno
    //re registro
    
    void setCarrera(string nuevoProposito,int nuevoIngreso);//cambiar carrera
    void eliminarAlumno();
    
    
};
