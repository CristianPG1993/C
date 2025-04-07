/*
    EJERCICIO: Buscar y filtrar datos en un array dinámico

    Descripción:
    Crea un programa que permita:

    1. Introducir N números en un array dinámico.
    2. Mostrar el array.
    3. Buscar un número introducido por el usuario y mostrar si se encuentra (y en qué posiciones).
    4. Mostrar solo los números mayores que la media.

    Requisitos:
    - Usar memoria dinámica (`new`, `delete[]`)
    - Usar funciones para:
        a) Cargar datos
        b) Mostrar datos
        c) Calcular media
        d) Buscar un número en el array
        e) Mostrar los valores mayores que la media
*/

#include <iostream>
using namespace std;

// =================== PROTOTIPOS DE FUNCIONES ===================

// Cargar datos en el array dinámico
void cargarDatos(int* arr, int tamano);

// Mostrar todos los datos del array
void mostrarArray(int* arr, int tamano);

// Calcular la media de los elementos del array
float calcularMedia(int* arr, int tamano);

// Buscar un número específico dentro del array
void buscarNumero(int* arr, int tamano, int numeroBuscado);

// Mostrar los números que son mayores que la media
void mostrarMayoresQueMedia(int* arr, int tamano, float media);


// =================== DEFINICIONES DE FUNCIONES ===================

// Cargar datos en el array dinámico
void cargarDatos(int* arr, int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Mostrar todos los datos del array
void mostrarArray(int* arr, int tamano) {
    cout << "Contenido del array: ";
    for (int i = 0; i < tamano; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Calcular la media de los elementos del array
float calcularMedia(int* arr, int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
    }
    return float(suma) / tamano; // Conversión a float para obtener decimales
}

// Buscar un número específico dentro del array
void buscarNumero(int* arr, int tamano, int numeroBuscado) {
    bool encontrado = false;

    for (int i = 0; i < tamano; i++) {
        if (arr[i] == numeroBuscado) {
            cout << "El número se encuentra en la posición: " << i << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "El número no se encuentra en el array." << endl;
    }
}

// Mostrar los números que son mayores que la media
void mostrarMayoresQueMedia(int* arr, int tamano, float media) {
    cout << "Los valores por encima de la media (" << media << ") son: ";

    bool alguno = false; // Para saber si se encontró alguno

    for (int i = 0; i < tamano; i++) {
        if (arr[i] > media) {
            cout << arr[i] << " ";
            alguno = true;
        }
    }

    if (!alguno) {
        cout << "Ninguno";
    }

    cout << endl;
}


// =================== FUNCIÓN PRINCIPAL ===================

int main() {
    int cantidad;

    // Paso 1: Pedimos al usuario cuántos datos va a introducir
    cout << "¿Cuántos datos quieres en el array? ";
    cin >> cantidad;

    // Paso 2: Reservamos memoria dinámica para el array
    int* numeros = new int[cantidad];

    // Paso 3: Cargamos los datos
    cargarDatos(numeros, cantidad);

    // Paso 4: Mostramos los datos introducidos
    mostrarArray(numeros, cantidad);

    // Paso 5: Calculamos y guardamos la media
    float media = calcularMedia(numeros, cantidad);

    // Paso 6: Pedimos al usuario un número a buscar
    int numeroBuscado;
    cout << "Introduce el número que deseas buscar en el array: ";
    cin >> numeroBuscado;

    // Paso 7: Buscamos ese número en el array
    buscarNumero(numeros, cantidad, numeroBuscado);

    // Paso 8: Mostramos los valores mayores que la media
    mostrarMayoresQueMedia(numeros, cantidad, media);

    // Paso 9: Liberamos la memoria dinámica reservada
    delete[] numeros;

    return 0;
}
