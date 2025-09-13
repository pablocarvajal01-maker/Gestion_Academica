git clone https://github.com/pablocarvajal01-maker/Gestion_Academica.git


cd Gestion_Academica


g++ -std=c++17 -o main Alumno.cpp Curso.cpp Notas.cpp Nodo.cpp ListaAlumnos.cpp ListaCursos.cpp main.cpp

./main

Pablo Carvajal 21.391.659-9

Alumno.h / Alumno.cpp: Clase Alumno y gestión de cursos y notas.

Curso.h / Curso.cpp: Clase Curso y gestión de alumnos inscritos.

Notas.h / Notas.cpp: Gestión de notas por curso y alumno.

Nodo.h: Nodos para listas enlazadas de alumnos (NodoAlumno) y cursos (NodoCurso).

ListaAlumnos.cpp / ListaCursos.cpp: Clases ListaAlumnos y ListaCursos, que gestionan colecciones de alumnos y cursos.

main.cpp: Programa principal con menú interactivo.

README.md: Este archivo.
