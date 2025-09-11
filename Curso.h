#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

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

#endif