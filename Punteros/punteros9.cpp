/*
Crea una estructura llamada RegistroTemperatura que contenga:
- float maxTemp
- float minTemp
- float promedio

Crea una función llamada analizarTemperaturas que:
- Reciba dos punteros (inicio y fin) de un array de tipo float
- Calcule y devuelva un RegistroTemperatura con los resultados

En el main:
1. Declara un array de 7 temperaturas
2. Llama a la función
3. Muestra el resultado: temperatura máxima, mínima y promedio
*/


#include <iostream>
using namespace std;

// Estructura que almacena los resultados del análisis de temperaturas
struct RegistroTemperatura {
    float maxTemp;    // Temperatura más alta
    float minTemp;    // Temperatura más baja
    float promedio;   // Temperatura promedio
};

// Función que analiza las temperaturas y devuelve el resultado en una estructura
RegistroTemperatura analizarTemperaturas(float* inicio, float* fin) {
    RegistroTemperatura resultado;

    // Inicializamos todos los campos con el primer valor del array
    resultado.maxTemp = *inicio;
    resultado.minTemp = *inicio;
    resultado.promedio = *inicio;

    float* actual = inicio;         // Puntero que recorre el array
    float suma = 0;                 // Acumulador para calcular el promedio
    int cantidadTemperaturas = 0;   // Contador de cuántos valores hay

    // Recorremos el array desde inicio hasta fin
    while (actual <= fin) {
        // Si el valor actual es mayor que el máximo conocido, lo actualizamos
        if (*actual > resultado.maxTemp) {
            resultado.maxTemp = *actual;
        }
        // Si el valor actual es menor que el mínimo conocido, lo actualizamos
        if (*actual < resultado.minTemp) {
            resultado.minTemp = *actual;
        }

        suma += *actual;           // Sumamos la temperatura actual
        cantidadTemperaturas++;    // Contamos una lectura más
        actual++;                  // Avanzamos el puntero
    }

    // Calculamos el promedio
    resultado.promedio = suma / cantidadTemperaturas;

    // Devolvemos el resultado
    return resultado;
}

int main() {
    // Array con 7 temperaturas registradas durante la semana
    float temperaturas[7] = {21.5, 19.8, 23.1, 20.0, 18.9, 24.3, 22.0};

    // Puntero que apunta al inicio del array
    float* ptr = temperaturas;

    // Llamamos a la función de análisis pasando el inicio y el final del array
    RegistroTemperatura resultado = analizarTemperaturas(ptr, ptr + 6);

    // Mostramos todas las temperaturas
    cout << "Las temperaturas son: ";
    for (int i = 0; i < 7; i++) {
        cout << *(ptr + i) << " "; // Usamos aritmética de punteros
    }
    cout << endl;

    // Mostramos los resultados obtenidos
    cout << "La temperatura máxima es: " << resultado.maxTemp << endl;
    cout << "La temperatura mínima es: " << resultado.minTemp << endl;
    cout << "La temperatura promedio es: " << resultado.promedio << endl;

    return 0;
}
