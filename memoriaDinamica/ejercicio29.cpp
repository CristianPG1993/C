/*
==============================================
🎓 ENUNCIADO - GESTIÓN DE CURSOS Y ESTUDIANTES
==============================================

Crea un programa en C++ que permita gestionar cursos y los estudiantes inscritos en ellos.

Cada curso debe tener:
- Nombre del curso (string)
- Nombre del profesor (string)
- Cantidad de estudiantes inscritos (int)
- Un array dinámico de estudiantes

Cada estudiante debe tener:
- Nombre (string)
- Edad (int)
- Nota final (float)

El programa debe permitir:

1. Introducir una lista inicial de cursos y sus estudiantes.
2. Preguntar al usuario si desea añadir otro curso.
3. Si la respuesta es sí, redimensionar dinámicamente el array de cursos y permitir añadir el nuevo curso y sus estudiantes.
4. Al finalizar, mostrar un informe de todos los cursos registrados y los datos de sus estudiantes.

Objetivo: reforzar el uso de arrays dinámicos, estructuras anidadas y redimensionamiento manual de memoria en C++.

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Estructura que representa un estudiante
struct Estudiante {
    string nombre;
    int edad;
    float notaFinal;
};

// Estructura que representa un curso con estudiantes dinámicos
struct Curso {
    string nombre;
    string nombreProfesor;
    int cantidadEstudiantes;
    Estudiante* estudiantes;
};

int main() {
    int cantidad;

    // Pedimos cuántos cursos quiere ingresar inicialmente
    cout << "\n¿Cuantos cursos vas a añadir?" << endl;
    cin >> cantidad;

    // Variable que lleva la cuenta total de cursos (inicialmente igual a cantidad)
    int cursosTotales = cantidad;

    // Creamos array dinámico de cursos
    Curso* cursos = new Curso[cantidad];
    cin.ignore();

    // Registramos los cursos iniciales
    for (int i = 0; i < cantidad; i++) {
        cout << "\n-------------------------" << endl;
        cout << "Curso " << i + 1 << ":" << endl;

        // Datos del curso
        cout << "Nombre del curso: ";
        getline(cin, cursos[i].nombre);

        cout << "Nombre del profesor: ";
        getline(cin, cursos[i].nombreProfesor);

        // Cantidad de estudiantes del curso
        cout << "¿Cuantos estudiantes tiene el curso?: ";
        cin >> cursos[i].cantidadEstudiantes;

        // Reservamos memoria para los estudiantes de ese curso
        cursos[i].estudiantes = new Estudiante[cursos[i].cantidadEstudiantes];
        cin.ignore();

        // Registramos los datos de cada estudiante
        for (int j = 0; j < cursos[i].cantidadEstudiantes; j++) {
            cout << "\n-------------------------" << endl;
            cout << "Estudiante " << j + 1 << ":" << endl;

            cout << "Nombre del estudiante: ";
            getline(cin, cursos[i].estudiantes[j].nombre);

            cout << "Edad del estudiante: ";
            cin >> cursos[i].estudiantes[j].edad;

            cout << "Nota del estudiante: ";
            cin >> cursos[i].estudiantes[j].notaFinal;

            cin.ignore(); // limpiar buffer
        }
    }

    // Bucle para permitir añadir nuevos cursos
    char opcion;
    do {
        cout << "\n¿Desea añadir otra clase? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S') {
            // Creamos un nuevo array con tamaño +1
            Curso* nuevoArray = new Curso[cursosTotales + 1];

            // Copiamos todos los cursos anteriores
            for (int i = 0; i < cursosTotales; i++) {
                nuevoArray[i] = cursos[i];
            }

            // Introducimos los datos del nuevo curso
            cout << "\nIntroduce la nueva clase:" << endl;

            cout << "Nombre de la clase: ";
            getline(cin, nuevoArray[cursosTotales].nombre);

            cout << "Nombre del profesor: ";
            getline(cin, nuevoArray[cursosTotales].nombreProfesor);

            cout << "¿Cuantos estudiantes tiene el curso?: ";
            cin >> nuevoArray[cursosTotales].cantidadEstudiantes;
            cin.ignore();

            // Creamos array de estudiantes del nuevo curso
            nuevoArray[cursosTotales].estudiantes = new Estudiante[nuevoArray[cursosTotales].cantidadEstudiantes];

            // Registramos los estudiantes del nuevo curso
            for (int j = 0; j < nuevoArray[cursosTotales].cantidadEstudiantes; j++) {
                cout << "\n--------------------------------------" << endl;
                cout << "Estudiante " << j + 1 << ":" << endl;

                cout << "Nombre del estudiante: ";
                getline(cin, nuevoArray[cursosTotales].estudiantes[j].nombre);

                cout << "Edad del estudiante: ";
                cin >> nuevoArray[cursosTotales].estudiantes[j].edad;

                cout << "Nota del estudiante: ";
                cin >> nuevoArray[cursosTotales].estudiantes[j].notaFinal;
                cin.ignore();
            }

            // Liberamos memoria del array anterior
            delete[] cursos;

            // Asignamos nuevo puntero
            cursos = nuevoArray;

            // Aumentamos el total de cursos registrados
            cursosTotales++;
        }

    } while (opcion == 's' || opcion == 'S');

    // Mostrar informe completo de todos los cursos
    for (int i = 0; i < cursosTotales; i++) {
        cout << "\n------------------------------------" << endl;
        cout << "Curso " << i + 1 << ": " << cursos[i].nombre << endl;
        cout << "Nombre del profesor: " << cursos[i].nombreProfesor << endl;
        cout << "El curso " << cursos[i].nombre << " tiene los siguientes estudiantes:" << endl;

        for (int j = 0; j < cursos[i].cantidadEstudiantes; j++) {
            cout << "\n---------------------------------" << endl;
            cout << "Estudiante " << j + 1 << ":" << endl;
            cout << "Nombre: " << cursos[i].estudiantes[j].nombre << endl;
            cout << "Edad: " << cursos[i].estudiantes[j].edad << endl;
            cout << fixed << setprecision(2);
            cout << "Nota final: " << cursos[i].estudiantes[j].notaFinal << endl;
        }
    }

    // Liberar memoria de todos los arrays internos (estudiantes)
    for (int i = 0; i < cursosTotales; i++) {
        delete[] cursos[i].estudiantes;
    }

    // Liberar el array principal de cursos
    delete[] cursos;

    return 0;
}


