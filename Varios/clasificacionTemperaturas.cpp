/*
1. Crea una estructura llamada EstadisticaTemperaturas con estos campos:
   - float maxTemp
   - float minTemp
   - float promedio
   - int frias
   - int templadas
   - int calurosas

2. Crea una función analizarTemperaturas que:
   - Reciba dos punteros (inicio y fin)
   - Devuelva la estructura con los resultados

3. En el main:
   - Pide al usuario que introduzca 8 temperaturas
   - Guarda las temperaturas en un array
   - Llama a la función y muestra los resultados
*/


#include <iostream>
using namespace std;

// Estructura que almacena estadísticas de temperaturas
struct EstadisticasTemperaturas {
    float maxTemp;       // Temperatura máxima registrada
    float minTemp;       // Temperatura mínima registrada
    float promedio;      // Promedio de temperaturas
    int frias;           // Número de temperaturas < 10 ºC
    int templadas;       // Número entre 10 ºC y 25 ºC
    int calidas;         // Número de temperaturas > 25 ºC
};

// Función que analiza un array de temperaturas usando punteros
EstadisticasTemperaturas analizarTemperaturas(float* inicio, float* fin) {
    EstadisticasTemperaturas resultado;

    // Inicializamos las estadísticas con el primer valor
    resultado.maxTemp = *inicio;
    resultado.minTemp = *inicio;
    resultado.frias = 0;
    resultado.templadas = 0;
    resultado.calidas = 0;

    float* actual = inicio; // Puntero que recorrerá el array
    float suma = 0;         // Acumulador para la suma
    int contador = 0;       // Contador de elementos

    // Bucle para recorrer el array usando aritmética de punteros
    while (actual <= fin) {
        if (*actual > resultado.maxTemp) {
            resultado.maxTemp = *actual;
        }
        if (*actual < resultado.minTemp) {
            resultado.minTemp = *actual;
        }

        // Clasificación según el valor de la temperatura
        if (*actual < 10) {
            resultado.frias++;
        } else if (*actual > 25) {
            resultado.calidas++;
        } else {
            resultado.templadas++;
        }

        suma += *actual;  // Acumulamos para el promedio
        contador++;       // Contamos cuántos elementos hay
        actual++;         // Avanzamos al siguiente valor
    }

    // Calculamos el promedio una vez terminado el recorrido
    resultado.promedio = suma / contador;

    return resultado; // Devolvemos la estructura con los resultados
}

int main() {
    float temperaturas[8]{};      // Array para almacenar las 8 temperaturas
    float* ptr = temperaturas;    // Puntero al inicio del array

    // Pedimos al usuario que introduzca 8 temperaturas
    for (int i = 0; i < 8; i++) {
        cout << "Introduce la temperatura " << i + 1 << " con decimales: ";
        cin >> temperaturas[i];
    }

    // Llamamos a la función después de haber introducido todos los datos
    EstadisticasTemperaturas resultado = analizarTemperaturas(ptr, ptr + 7);

    // Mostramos las temperaturas introducidas una a una
    cout << "Las temperaturas introducidas son: ";
    for (int i = 0; i < 8; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Mostramos los resultados del análisis
    cout << "La temperatura máxima es: " << resultado.maxTemp << " ºC" << endl;
    cout << "La temperatura mínima es: " << resultado.minTemp << " ºC" << endl;
    cout << "La temperatura promedio es: " << resultado.promedio << " ºC" << endl;
    cout << "Los días con menos de 10 grados: " << resultado.frias << endl;
    cout << "Los días entre 10 y 25 grados: " << resultado.templadas << endl;
    cout << "Los días con más de 25 grados: " << resultado.calidas << endl;

    return 0;
}

