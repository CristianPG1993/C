/*
    EJERCICIO: Operaciones con arrays dinámicos y funciones

    Descripción:
    Crea un programa en C++ que permita al usuario:

    1. Indicar cuántos números desea introducir.
    2. Reservar memoria dinámica para guardar esos números.
    3. Introducir los números por teclado.
    4. Mostrar los números introducidos.
    5. Calcular y mostrar la media, el mayor y el menor valor.

    Requisitos:
    - Uso de memoria dinámica (`new`, `delete[]`)
    - Uso de funciones para organizar:
        a) Cargar datos en el array
        b) Mostrar el array
        c) Calcular la media
        d) Buscar el mayor y menor
    - Entrada dinámica del usuario
    - Buenas prácticas de modularidad
*/


#include <iostream>
using namespace std;

// Función para cargar los datos en el array dinámico
void cargarDatos(int* arr, int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Función para mostrar el contenido del array
void mostrarArray(int* arr, int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << "El valor " << i + 1 << " del array es: " << arr[i] << endl;
    }
}

// Función que calcula y devuelve la media del array
float calcularMedia(int* arr, int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }
    float media = float(suma) / tamano;
    return media;
}

// Función que devuelve el valor más alto del array
int encontrarMayor(int* arr, int tamano) {
    int mayor = arr[0];
    for (int i = 1; i < tamano; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
    return mayor;
}

// Función que devuelve el valor más bajo del array
int encontrarMenor(int* arr, int tamano) {
    int menor = arr[0];
    for (int i = 1; i < tamano; i++) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    return menor;
}

int main() {
    int cantidad;

    cout << "¿Cuántos números desea introducir? ";
    cin >> cantidad;

    int* numeros = new int[cantidad];

    cargarDatos(numeros, cantidad);

    cout << "\nEl array completo es: " << endl;
    mostrarArray(numeros, cantidad);

    float media = calcularMedia(numeros, cantidad);
    int mayor = encontrarMayor(numeros, cantidad);
    int menor = encontrarMenor(numeros, cantidad);

    cout << "\n📊 Resultados:\n";
    cout << "La media de los datos es: " << media << endl;
    cout << "El dato mayor en el array es: " << mayor << endl;
    cout << "El dato menor en el array es: " << menor << endl;

    delete[] numeros;
    return 0;
}
