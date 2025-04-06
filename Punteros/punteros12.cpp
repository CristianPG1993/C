/*
1. Crea una estructura llamada EstadisticaAlturas con estos campos:
   - float maxAltura
   - float minAltura
   - float promedio
   - int mayores175

2. Crea una función llamada analizarAlturas que:
   - Reciba dos punteros (inicio y fin)
   - Devuelva la estructura con los resultados

3. En el main:
   - Pide al usuario que introduzca 6 alturas en cm
   - Guarda las alturas en un array
   - Llama a la función y muestra los resultados
*/


#include <iostream>
using namespace std;

// Estructura que almacena estadísticas de un conjunto de alturas
struct EstadisticaAlturas {
    float maxAltura;      // Altura máxima encontrada
    float minAltura;      // Altura mínima encontrada
    float promedio;       // Altura promedio
    int mayores175;       // Cantidad de personas con altura > 175 cm
};

// Función que analiza un rango de alturas usando punteros
EstadisticaAlturas analizarAlturas(float* inicio, float* fin) {
    EstadisticaAlturas resultado;

    // Inicializamos con el primer valor del array
    resultado.maxAltura = *inicio;
    resultado.minAltura = *inicio;
    resultado.promedio = *inicio;
    resultado.mayores175 = 0;

    float* actual = inicio;
    float suma = 0;
    int contador = 0;

    // Recorremos desde el puntero inicio hasta fin (inclusive)
    while (actual <= fin) {
        if (*actual > resultado.maxAltura) {
            resultado.maxAltura = *actual;
        }
        if (*actual < resultado.minAltura) {
            resultado.minAltura = *actual;
        }
        if (*actual > 175) {
            resultado.mayores175++;
        }

        suma += *actual;
        contador++;
        actual++; // Avanzamos al siguiente elemento
    }

    // Calculamos la media
    resultado.promedio = suma / contador;

    return resultado;
}

int main() {
    float alturas[6]{};      // Array para almacenar 6 alturas
    float* ptr = alturas;    // Puntero al inicio del array

    // Pedimos al usuario que introduzca las 6 alturas
    for (int i = 0; i < 6; i++) {
        cout << "Introduce la altura " << i + 1 << " en centímetros: ";
        cin >> alturas[i];
    }

    // Llamamos a la función pasando el puntero al primer y último elemento
    EstadisticaAlturas resultado = analizarAlturas(ptr, ptr + 5);

    // Mostramos las alturas introducidas
    cout << "Las alturas introducidas son: ";
    for (int i = 0; i < 6; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Mostramos los resultados del análisis
    cout << "La altura máxima es: " << resultado.maxAltura << " cm." << endl;
    cout << "La altura mínima es: " << resultado.minAltura << " cm." << endl;
    cout << "La altura promedio es: " << resultado.promedio << " cm." << endl;
    cout << "Cantidad de personas que miden más de 175 cm: " << resultado.mayores175 << endl;

    return 0;
}


