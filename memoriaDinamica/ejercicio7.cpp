/*
    EJERCICIO: Análisis de notas de estudiantes

    Descripción:
    Crea un programa que permita:

    1. Introducir N calificaciones de estudiantes (enteros del 0 al 10).
    2. Mostrar todas las calificaciones introducidas.
    3. Calcular la media de las notas.
    4. Contar cuántos estudiantes aprobaron (nota >= 5).
    5. Contar cuántos estudiantes suspendieron (nota < 5).
    6. Mostrar la nota más alta y la más baja.

    Requisitos:
    - Usar memoria dinámica (`new`, `delete[]`)
    - Modularizar en funciones:
        - cargarNotas
        - mostrarNotas
        - calcularMedia
        - contarAprobados
        - contarSuspendidos
        - mostrarNotaMaxima
        - mostrarNotaMinima
*/


#include <iostream>
using namespace std;

// ===================== FUNCIONES =====================

// Función que pide al usuario introducir las notas y las guarda en el array dinámico
void cargarNotas(int* arr, int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << "Introduce la nota " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Función que muestra todas las notas del array
void mostrarNotas(int* arr, int tamano) {
    cout << "Las notas introducidas son: ";
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función que calcula la media aritmética de las notas
float calcularMedia(int* arr, int tamano) {
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }

    float media = float(suma) / tamano;  // Conversión a float para obtener decimales
    return media;
}

// Función que cuenta y muestra cuántas notas son mayores o iguales a 5 (aprobados)
void contarAprobados(int* arr, int tamano) {
    int contadorAprobados = 0;

    for (int i = 0; i < tamano; i++) {
        if (arr[i] >= 5) {
            contadorAprobados++;
        }
    }

    cout << "El número de aprobados es: " << contadorAprobados << endl;
}

// Función que cuenta y muestra cuántas notas son menores que 5 (suspensos)
void contarSuspensos(int* arr, int tamano) {
    int contarSuspensos = 0;

    for (int i = 0; i < tamano; i++) {
        if (arr[i] < 5) {
            contarSuspensos++;
        }
    }

    cout << "El número de suspensos es: " << contarSuspensos << endl;
}

// Función que encuentra y muestra la nota más alta del array
void mostrarNotaMaxima(int* arr, int tamano) {
    int notaMax = arr[0]; // Inicializamos con el primer valor

    for (int i = 0; i < tamano; i++) {
        if (arr[i] > notaMax) {
            notaMax = arr[i];
        }
    }

    cout << "La nota máxima es: " << notaMax << endl;
}

// Función que encuentra y muestra la nota más baja del array
void mostrarNotaMinima(int* arr, int tamano) {
    int notaMin = arr[0]; // Inicializamos con el primer valor

    for (int i = 0; i < tamano; i++) {
        if (arr[i] < notaMin) {
            notaMin = arr[i];
        }
    }

    cout << "La nota mínima es: " << notaMin << endl;
}

// ===================== FUNCIÓN PRINCIPAL =====================

int main() {
    int cantidad;

    // Preguntamos al usuario cuántas notas desea introducir
    cout << "¿Cuántas notas vas a introducir? ";
    cin >> cantidad;

    // Reservamos memoria dinámica para el array de notas
    int* numeros = new int[cantidad];

    // Cargamos las notas en el array
    cargarNotas(numeros, cantidad);

    // Mostramos todas las notas
    mostrarNotas(numeros, cantidad);

    // Calculamos y mostramos la media
    float media = calcularMedia(numeros, cantidad);
    cout << "La nota media es: " << media << endl;

    // Contamos aprobados y suspensos
    contarAprobados(numeros, cantidad);
    contarSuspensos(numeros, cantidad);

    // Mostramos la nota máxima y mínima
    mostrarNotaMaxima(numeros, cantidad);
    mostrarNotaMinima(numeros, cantidad);

    // Liberamos la memoria dinámica reservada
    delete[] numeros;

    return 0;
}
