/*
    EJERCICIO: Registro de temperaturas semanales por ciudad (memoria dinámica + estructuras)

    Descripción:
    Crea un programa en C++ que permita registrar las temperaturas diarias durante una semana para varias ciudades.

    El usuario debe poder:
    - Indicar cuántas ciudades va a introducir.
    - Escribir el nombre de cada ciudad.
    - Introducir 7 temperaturas (una por cada día) para cada ciudad.

    El programa debe:
    - Usar memoria dinámica para crear un array de estructuras `Ciudad`.
    - Usar otro array dinámico dentro de la estructura para guardar las temperaturas.
    - Calcular y mostrar la temperatura media de cada ciudad.

    Requisitos técnicos:
    - Uso de estructuras (`struct`)
    - Uso de `new` y `delete[]` para reservar y liberar memoria dinámica
    - Uso de punteros y bucles
    - Entrada del usuario dinámica

    Objetivo:
    Reforzar el manejo de memoria dinámica en C++ y combinarlo con estructuras y punteros.
*/


#include <iostream>
using namespace std;

// Estructura que representa una ciudad con su nombre y un array dinámico de temperaturas
struct Ciudad {
    string nombre;         // Nombre de la ciudad
    float* temperaturas;   // Puntero a un array dinámico de 7 temperaturas
};

int main() {
    int cantidad;           // Número de ciudades que va a introducir el usuario
    Ciudad* resultado;      // Puntero al array dinámico de estructuras Ciudad

    // Solicitar al usuario cuántas ciudades quiere introducir
    cout << "¿Cuántas ciudades desea introducir? ";
    cin >> cantidad;

    // Crear dinámicamente un array de estructuras Ciudad
    resultado = new Ciudad[cantidad];

    // Bucle para introducir los datos de cada ciudad
    for (int i = 0; i < cantidad; i++) {
        // Pedir el nombre de la ciudad
        cout << "Introduce la ciudad " << i + 1 << " : ";
        cin >> resultado[i].nombre;

        // Crear dinámicamente un array de 7 temperaturas para esta ciudad
        resultado[i].temperaturas = new float[7];

        // Bucle para introducir las 7 temperaturas
        for (int j = 0; j < 7; j++) {
            cout << "Temperatura del día " << j + 1 << ": ";
            cin >> resultado[i].temperaturas[j];
        }
    }

    // Bucle para procesar y mostrar los datos de cada ciudad
    for (int i = 0; i < cantidad; i++) {
        float suma = 0.0;
        float max = resultado[i].temperaturas[0]; // Inicializar con el primer valor
        float min = resultado[i].temperaturas[0];

        // Bucle para recorrer las 7 temperaturas y calcular suma, máx y mín
        for (int j = 0; j < 7; j++) {
            float temp = resultado[i].temperaturas[j];

            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }

            suma += temp;
        }

        // Calcular la media
        float media = suma / 7.0;

        // Mostrar resultados
        cout << "La media de temperatura en " << resultado[i].nombre << " es: " 
             << media << " ºC." << endl;
        cout << "Temperatura máxima: " << max << " ºC" << endl;
        cout << "Temperatura mínima: " << min << " ºC" << endl;
    }

    // Liberar memoria de los arrays de temperaturas por ciudad
    for (int i = 0; i < cantidad; i++) {
        delete[] resultado[i].temperaturas;
    }

    // Liberar el array dinámico de estructuras Ciudad
    delete[] resultado;

    return 0;
}
