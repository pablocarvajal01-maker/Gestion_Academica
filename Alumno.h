#ifndef ALUMNO_H
#define ALUMNO_H
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
    ~Alumno();//destructor
    //busqueda
    int getId();

    string getName();
    string getApellido();

    string getCarrera();

    void mostrarAlumno();

    void setCarrera(string nuevoProposito,int nuevoIngreso);//cambiar carrera
    void eliminarAlumno();


};
class Curso {
private:
    string codigo;
    string nombre;
    string carrera;
    string profesor;
    int cupoMax;
    int cupoActual;

public:
    Curso(string codigo, string nombre, string carrera, string profesor, int cupoMax, int cupoActual);
    ~Curso();

    string getCodigo();
    string getNombre();
    string getCarrera();
    void getCupo();
    void setCupoActual(int valor);
    void mostrarInfo();
};
#endif
