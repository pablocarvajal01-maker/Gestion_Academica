#include <iostream>
#include <ostream>
#include <sstream>
#include <limits>
#include "Alumno.h"
#include "Nodo.h"

using namespace std;
int static id;

ListaAlumnos students;
ListaCursos Ramos;


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

    cout << "Ingrese ano de ingreso: ";
    while (!(cin >> ingreso)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un ano valido: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer

    id++;

    Alumno* nuevo= new Alumno(nombre,apellido,carrera,ingreso,id);
    students.agregar(nuevo);
    cout << "Alumno creado: \n"<<endl;
    students.mostrar();

}

void buscarId(){
    int identificacion;
    bool foundIt = false;
    while (!foundIt) {
        cout<<"\n \t(-1 para salir)\nIngrese la id del alumno: ";
        errorMenu(identificacion);
        Alumno* encontrado = students.buscarPorId(identificacion);
        if (encontrado != nullptr) {
            encontrado->mostrarAlumno();
            foundIt=true;
        } else if (identificacion==-1)  {
            foundIt=true;
            salida();
        }else{
            cout << "Alumno no encontrado." << endl;
        }
    }
}
void buscarNombre(ListaAlumnos& students) {
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


        string palabras[10];
        int cantidad = 0;
        string palabra = "";

        for (size_t i = 0; i <= linea.size(); i++) {
            if (i == linea.size() || linea[i] == ' ') {
                if (!palabra.empty()) {
                    palabras[cantidad++] = palabra;
                    palabra = "";
                }
            } else {
                palabra += linea[i];
            }
        }


        foundIt = students.buscarPorNombre(palabras, cantidad);
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
                buscarNombre(students);
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
    int identificacion;
    do {
        cout << "(ingrese -1 para salir)\nIngrese id del alumno a eliminar: ";
        errorMenu(identificacion);
        students.eliminar(identificacion);
    }while (identificacion==-1);
    salida();

}

void crearCurso() {
    string codigo, nombre, carrera, profesor;
    int cupoMax, cupoActual;

    cout << "Ingrese codigo del curso: ";
    cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (Ramos.buscarPorCodigo(codigo) != nullptr) {
        cout << "Error: ya existe un curso con ese codigo.\n";
        return;
    }

    cout << "Ingrese nombre del curso: ";
    getline(cin, nombre);

    cout << "Ingrese carrera: ";
    getline(cin, carrera);

    cout << "Ingrese profesor: ";
    getline(cin, profesor);

    cout << "Ingrese cupo máximo: ";
    while (!(cin >> cupoMax) || cupoMax <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero valido para cupo máximo: ";
    }

    cout << "Ingrese cupo actual: ";
    while (!(cin >> cupoActual) || cupoActual < 0 || cupoActual > cupoMax) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero valido para cupo actual (0 a " << cupoMax << "): ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Curso* nuevo = new Curso(codigo, nombre, carrera, profesor, cupoMax, cupoActual);
    Ramos.agregar(nuevo);

    cout << "\nCurso creado exitosamente!\n";
    nuevo->mostrarInfo();
}

void eliminarCurso() {
    string codigo;
    cout << "Ingrese el codigo del curso a eliminar: ";
    cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    if (Ramos.eliminar(codigo)) {
        cout << "Curso eliminado exitosamente.\n";
    } else {
        cout << "Curso no encontrado.\n";
    }

}

void buscarCurso() {
    string codigo;
    cout << "Ingrese el codigo del curso a buscar: ";
    cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Curso* curso = Ramos.buscarPorCodigo(codigo);
    if (curso != nullptr) {
        cout << "\nCurso encontrado:\n";
        curso->mostrarInfo();
    } else {
        cout << "Curso no encontrado.\n";
    }
}

void inscribirAlumno() {
    int id;
    string codigo;
    cout << "Ingrese ID del alumno: ";
    errorMenu(id);
    cout << "Ingrese código del curso: ";
    cin >> codigo;

    Curso* curso = Ramos.buscarPorCodigo(codigo);
    if (!curso) {
        cout << "Curso no encontrado.\n" << endl;
        return;
    }
    Alumno* alumno = students.buscarPorId(id);
    if (!alumno) {
        cout << "Alumno no encontrado.\n" << endl;
        return;
    }
    if (curso->inscribirAlumno(alumno)) {
        cout << "Alumno " << alumno->getName() << " inscrito en "
             << curso->getNombre() << "\n" << endl;
    } else {
        cout << "No se pudo inscribir al alumno (curso lleno o error)\n" << endl;
    }
}

void expulsarAlumno() {
    int id;
    string codigo;
    cout << "Ingrese ID del alumno: ";
    errorMenu(id);
    cout << "Ingrese código del curso: ";
    cin >> codigo;
    Curso* curso = Ramos.buscarPorCodigo(codigo);
    if (!curso) {
        cout << "Curso no encontrado.\n" << endl;
        return;
    }
    Alumno* alumno = students.buscarPorId(id);
    if (!alumno) {
        cout << "Alumno no encontrado.\n" << endl;
        return;
    }

    if (curso->expulsarAlumno(id)) {
        cout << "Alumno " << alumno->getName() << " expulsado del curso "
             << curso->getNombre() << "\n" << endl;
    } else {
        cout << "No se pudo expulsar al alumno (quizás no estaba inscrito)\n" << endl;
    }
}


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
