/*
    EJERCICIO AVANZADO: Registro de estudiantes

    Objetivo:
    - Crear un programa que permita:
        1. Registrar N estudiantes (nombre + nota).
        2. Mostrar todos los datos introducidos.
        3. Calcular la nota media del grupo.
        4. Mostrar qué estudiantes han aprobado.
        5. Mostrar qué estudiante tiene la nota más alta.

    Requisitos:
    - Usar struct Estudiante { string nombre; int nota; }
    - Usar arrays dinámicos de estructuras
    - Modularizar todas las operaciones
*/


#include <iostream>
using namespace std;

struct Estudiante{

    string nombre;
    int nota;

};

void cargarEstudiantes(Estudiante* lista, int cantidad){

    
    for (int i = 0; i < cantidad; i++){
        cout << "-----------------------------------------" << endl;
        cout << "Nombre del estudiante " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> lista[i].nota;
        cout << "-----------------------------------------" << endl;
        

    }
}
void mostrarEstudiantes(Estudiante* lista, int cantidad){

    for (int i = 0; i < cantidad; i++){

        cout << "Estudiante " << i + 1 << ": " 
        << lista[i].nombre << " - Nota: " << lista[i].nota << endl;

    }
}
float calcularNotaMediaGrupo(Estudiante* lista, int cantidad){

    int suma = 0;

    for (int i = 0; i < cantidad; i++){
            suma += lista[i].nota;
    }

    float media = float(suma) / cantidad;

    return media;
}
void mostrarEstudiantesAprobados(Estudiante* lista, int cantidad) {
    int contadorAprobados = 0;

    cout << "Estudiantes que han aprobado:\n";

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].nota >= 5) {
            cout << "- " << lista[i].nombre << " (Nota: " << lista[i].nota << ")" << endl;
            contadorAprobados++;
        }
    }

    cout << "Total de aprobados: " << contadorAprobados << endl;
}

void mostrarEstudianteMayorNota(Estudiante* lista, int cantidad){

    int mayorNota = lista[0].nota;

    string nombreEstudiante = lista[0].nombre;
    

    for (int i = 1; i < cantidad; i++){

        if(lista[i].nota > mayorNota){

            mayorNota = lista[i].nota;
            nombreEstudiante = lista[i].nombre;

        }


    }

    cout << "El  estudiante " << nombreEstudiante << " tiene la mayor nota: " 
    << mayorNota << endl;
}


int main(){

    int cantidad;

    cout << "-----------------------------------------" << endl;
    cout << "¿Cuantos estudiantes vas a introducir?";
    cin >> cantidad;

    Estudiante* lista = new Estudiante[cantidad];

    cargarEstudiantes(lista, cantidad);
    cout << "-----------------------------------------" << endl;
    mostrarEstudiantes(lista, cantidad);

    float media = calcularNotaMediaGrupo(lista, cantidad);
    cout << "La nota media del grupo es: " << media << endl;


    cout << "-----------------------------------------" << endl;
    mostrarEstudiantesAprobados(lista, cantidad);
    cout << "-----------------------------------------" << endl;
    mostrarEstudianteMayorNota(lista, cantidad);

    delete [] lista;
    return 0;



}
