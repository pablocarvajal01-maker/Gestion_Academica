#include "Alumno.h"
using namespace std;

int main() {
    Alumno a1( "Jared", "Hopeworth", "Crook", 2015,9123);

    a1.mostrarAlumno();
    a1.setCarrera("Bone Turner´s",2017);
    a1.mostrarAlumno();

    return 0;
}
