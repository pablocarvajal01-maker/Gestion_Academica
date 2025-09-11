#include <iostream>
#include <ostream>
#include "Alumno.h"
using namespace std;

void menuAlumno () {
    int opcion;
    while (opcion!=4) {
        cout<<"\tMANEJO ALUMNADO\n1)Crear Alumnos.\n2)Buscar Alumnos.\n3)Eliminar Alumno.\n4)Salir.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                crearAlumno();
                break;
            case 2:
                buscarAlumno();
                break;
            case 3:
                eliminarAlumno();
                break;
            case 4:
                salida();
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
        }

    }
}
void menuCursos () {
    int opcion;
    while (opcion!=4) {
        cout<<"\tMANEJO CURSOS\n1)Crear Curso.\n2)Buscar Curso.\n3)Eliminar Curso.\n4)Salir.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                crearCurso();
                break;
            case 2:
                buscarCurso();
                break;
            case 3:
                eliminarCurso();
                break;
            case 4:
                salida();
                break;
            default:
            cout<<"Opcion Invalida"<<endl;
            break;
        }
    }
}
void menuInscripcion () {
    int opcion;
    while (opcion!=3) {
        cout<<"\tINSCRIPCION DE CURSOS\n1)Inscribir Alumno a un Curso.\n2)Eliminar Alumno de un Curso.\n3)Salir.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                inscribirAlumno();
                break;
            case 2:
                expulsarAlumno();
                break;
            case 3:
                salida();
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
        }
    }
}
void menuNotas() {
    int opcion;
    while (opcion!=3) {
        cout<<"\tMANEJO DE NOTAS\n1)Inscribir notas.\n2)Modificar Notas.\n3)Salir.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                inscribirNotas();
                break;
            case 2:
                modificarNotas();
                break;
            case 3:
                salida();
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
        }
        }
    }
void menuReportes () {
    int opcion;
    while (opcion!=0) {
        cout<<"\tMANEJO ALUMNADO\n1)Obtener Alumnos. (Busqueda por carrera)\n2)Obtener Curso. (Busqueda por alumno) \n3)Calcular Promedio de Estudiante por Curso.\n4)Calcular Promedio General de Estudiante.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                reporteAlumnos();
                break;
            case 2:
                reporteCurso();
                break;
            case 3:
                promedioCurso();
                break;
            case 4:
                promedioGeneral();
                break;
            default:
                cout<<"Opcion Invalida"<<endl;
                break;
        }
    }
}
void menuPrincipal () {

    int opcion;
    while (opcion!=6) {
        cout<<"\tMENU PRINCIPAL\n1)Manejo de Alumnos.\n2)Manejo de Cursos.\n3)Manejo de Inscripciones.\n4)Manejo de Notas. \n5)Consultas y Reportes.\n6)Salir.";
        cin>>opcion;
        switch (opcion) {
            case 1:
                menuAlumno();
                break;
            case 2:
                menuCursos();
                break;
            case 3:
                menuInscripcion();
                break;
            case 4:
                menuNotas();
                break;
            case 5:
                menuReportes();
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }
}
int main() {

    menuPrincipal();

    return 0;
}
