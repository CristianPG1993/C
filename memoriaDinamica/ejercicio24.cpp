/*
==========================================================================
👨‍🎓 EJERCICIO 7 - GESTIÓN DE ALUMNOS CON NOTAS (ESTRUCTURA ANIDADA)
==========================================================================

1. Crea una estructura `Nota` con:
   - asignatura (string)
   - calificacion (float)

2. Crea una estructura `Alumno` con:
   - nombre (string)
   - edad (int)
   - un array dinámico de `Nota`
   - un entero que indique cuántas notas tiene

3. Pide al usuario cuántos alumnos va a registrar.
4. Para cada alumno, pide:
   - nombre
   - edad
   - cuántas asignaturas tiene
   - para cada asignatura, pide el nombre y la calificación
5. Guarda todos los datos en un array dinámico de `Alumno`.
6. Al final, muestra toda la información registrada (nombre, edad y sus notas).

🎯 Objetivo: entender cómo funcionan estructuras anidadas y arrays dinámicos dentro de otras estructuras.
*/

#include <iostream>
#include <string>
#include <iomanip> // Para setprecision
using namespace std;

// Paso 1: Estructura Nota (asignatura + calificación)
struct Nota {
    string asignatura;
    float calificacion;
};

// Paso 2: Estructura Alumno con notas anidadas
struct Alumno {
    string nombre;
    int edad;
    Nota* notas;          // Array dinámico de notas
    int cantidadNotas;    // Número de notas
};

int main() {
    int cantidad;

    // Paso 3: Pedimos cuántos alumnos se van a registrar
    cout << "\n¿Cuántos alumnos desea ingresar? ";
    cin >> cantidad;

    // Creamos array dinámico de alumnos
    Alumno* alumnos = new Alumno[cantidad];
    cin.ignore(); // Limpiar buffer antes de getline

    // Paso 4: Recorremos para pedir los datos de cada alumno
    for (int i = 0; i < cantidad; i++) {
        cout << "\nAlumno " << i + 1 << ":\n";

        cout << "Nombre: ";
        getline(cin, alumnos[i].nombre);

        cout << "Edad: ";
        cin >> alumnos[i].edad;

        cout << "¿Cuántas asignaturas tiene? ";
        cin >> alumnos[i].cantidadNotas;

        // Reservamos memoria para las notas
        alumnos[i].notas = new Nota[alumnos[i].cantidadNotas];
        cin.ignore(); // Limpieza antes de pedir asignaturas

        // Paso 5: Pedimos cada asignatura y calificación
        for (int j = 0; j < alumnos[i].cantidadNotas; j++) {
            cout << "\nNota " << j + 1 << ":\n";

            cout << "Asignatura: ";
            getline(cin, alumnos[i].notas[j].asignatura);

            cout << "Calificación: ";
            cin >> alumnos[i].notas[j].calificacion;
            cin.ignore();
        }
    }

    // Paso 6: Mostrar todos los datos registrados
    cout << "\n📋 INFORME DE ALUMNOS:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\nAlumno " << i + 1 << ":\n";
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Edad: " << alumnos[i].edad << " años" << endl;

        cout << "Notas de " << alumnos[i].nombre << ":\n";

        for (int j = 0; j < alumnos[i].cantidadNotas; j++) {
            cout << " - " << alumnos[i].notas[j].asignatura << ": ";
            cout << fixed << setprecision(2) << alumnos[i].notas[j].calificacion << endl;
        }
    }

    // Paso 7: Liberar toda la memoria dinámica
    for (int i = 0; i < cantidad; i++) {
        delete[] alumnos[i].notas;
    }
    delete[] alumnos;

    return 0;
}

