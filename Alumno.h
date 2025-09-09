#pragma once
#include <string>
using namespace std;

class Alumno{
    private:
        string nombre;
        string apellido;
        string carrera;
        string fechaDeIngreso;
        int id;
        
    public:
    //registro
    Alumno(string nombre,string apellido, string carrera,string fechaDeIngreso,int id); //contructor
    //busqueda
    int getId();//mostrar id
    string getNombre();//mostrar nombre y apellido del alumno
    string getCarrera();//mostrar carrera y cuando ingreso
    void mostrarAlumno();//mostrar toda la informacion del alumno
    //re registro
    void setCarrera();//cambiar carrera
    void eliminarAlumno();
    
    
}
