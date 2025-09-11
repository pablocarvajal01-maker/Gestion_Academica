#include <iostream>
#include <ostream>
#include <sstream>
#include <limits>
#include "Alumno.h"
#include "ListaAlumnos.h"
using namespace std;
int static id;
ListaAlumnos listaAlumnos;

void salida() {
    cout<<"Volviendo al menu anterior"<<endl;
}
void errorMenu(int &opcion) {
    while (true) {
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor ingrese un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}


void crearAlumno() {
    string nombre, apellido, carrera,linea;
    int ingreso;

    cout << " Ingrese nombre: ";
    getline(cin, linea);

    istringstream nomCompleto(linea);
    nomCompleto >> nombre;
    if (!(nomCompleto >> apellido)) {
        apellido = "";
    } else {
        cout << "Apellido detectado automaticamente: " << apellido << endl;
    }

    if (apellido.empty()) {
        cout << "Ingrese apellido: ";
        getline(cin, apellido);
    }

    cout << "Ingrese carrera: ";
    getline(cin, carrera);

    cout << "Ingrese año de ingreso: ";
    while (!(cin >> ingreso)) { // validación de número
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un año válido: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    id++;

    Alumno* nuevo= new Alumno(nombre,apellido,carrera,ingreso,id);
    listaAlumnos.agregar(nuevo);
    cout << "Alumno creado: \n"<<endl;
    listaAlumnos.mostrar();

}
void buscarId(){
    int id;
    bool foundIt = false;
    while (!foundIt) {
        cout<<"\n \t(-1 para salir)\nIngrese la id del alumno: ";
        errorMenu(id);
        Alumno* encontrado = listaAlumnos.buscarPorId(id);
        if (encontrado != nullptr) {
            encontrado->mostrarAlumno();
            foundIt=true;
        } else if (id==-1)  {
            foundIt=true;
            salida();
        }else{
            cout << "Alumno no encontrado." << endl;
        }
    }
}
void buscarNombre() {
    string linea;
    bool foundIt = false;

    while (!foundIt) {
        cout << "\n\t(ingrese 'salir' para volver al menu anterior)\nIngrese nombre o apellido del alumno: ";
        getline(cin, linea);

        if (linea == "salir") {
            foundIt = true;
            salida();
            break;
        }

        istringstream nomCompleto(linea);
        vector<string> palabras;
        string palabra;
        while (nomCompleto >> palabra) {
            palabras.push_back(palabra);
        }


        foundIt = listaAlumnos.buscarPorNombre(palabras);
        if (!foundIt) {
            cout << "Alumno no encontrado.\n";
        }
    }
}

void buscarAlumno() {
    int opcion;
    do {

        cout<<"\n \tBuscar Alumnos\n1)Buscar por id.\n2)Buscar por nombre.\n3)Salir.";
        errorMenu(opcion);
        switch (opcion) {
            case 1:
                buscarId();
                break;
            case 2:
                buscarNombre();
                break;
            case 3:
                salida();
                break;
            default:
                cout<<"\nIngrese una opcion valida"<<endl;

        }
    }while (opcion != 3);
}
void eliminarAlumno() {
    int id;
    do {
        cout << "(ingrese -1 para salir)\nIngrese id del alumno a eliminar: ";
        errorMenu(id);
        listaAlumnos.eliminar(id);
    }while (id==-1);
    salida();

}

void crearCurso(){}
void buscarCurso() {}
void eliminarCurso() {}

void inscribirAlumno() {}
void expulsarAlumno() {}

void inscribirNotas(){}
void modificarNotas() {}

void reporteAlumnos(){}
void reporteCurso(){}
void promedioCurso(){}
void promedioGeneral(){}




void menuAlumno () {
    int opcion;
    do {
        cout<<"\n \tMANEJO ALUMNADO\n1)Crear Alumnos.\n2)Buscar Alumnos.\n3)Eliminar Alumno.\n4)Salir.\n";
        errorMenu(opcion);

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

    }while(opcion!=4);
}
void menuCursos () {
    int opcion;
    do {
        cout<<"\n \tMANEJO CURSOS\n1)Crear Curso.\n2)Buscar Curso.\n3)Eliminar Curso.\n4)Salir.\n";
        errorMenu(opcion);

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
    }while(opcion!=4);
}
void menuInscripcion () {
    int opcion;
     do{
        cout<<"\n \tINSCRIPCION DE CURSOS\n1)Inscribir Alumno a un Curso.\n2)Eliminar Alumno de un Curso.\n3)Salir.\n";
        errorMenu(opcion);

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
    }while (opcion!=3);
}
void menuNotas() {
    int opcion;
    do {
        cout<<"\n \tMANEJO DE NOTAS\n1)Inscribir notas.\n2)Modificar Notas.\n3)Salir.\n";
        errorMenu(opcion);

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
        }while (opcion!=3);
    }
void menuReportes () {
    int opcion;
    do {
        cout<<"\n \tMANEJO ALUMNADO\n1)Obtener Alumnos. (Busqueda por carrera)\n2)Obtener Curso. (Busqueda por alumno) \n3)Calcular Promedio de Estudiante por Curso.\n4)Calcular Promedio General de Estudiante.\n5)Salir.\n";
        errorMenu(opcion);

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
    }while (opcion!=5);
}
void menuPrincipal () {

    int opcion;
    do {
        cout<<"\tMENU PRINCIPAL\n1)Manejo de Alumnos.\n2)Manejo de Cursos.\n3)Manejo de Inscripciones.\n4)Manejo de Notas. \n5)Consultas y Reportes.\n6)Salir.\n";
        errorMenu(opcion);

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
            case 6:
                cout<<"Finalizando programa, Buen dia"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while (opcion!=6);
}



int main() {

    menuPrincipal();

    return 0;
}
