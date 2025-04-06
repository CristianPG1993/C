/*
Crea una estructura llamada EstadisticasJugador con estos campos:
- int maxPuntuacion
- int minPuntuacion
- float promedio
- int vecesSuperior80

Crea una función llamada analizarPuntuaciones que:
- Reciba dos punteros (inicio y fin) de un array de int
- Calcule los valores anteriores y los devuelva en la estructura

En el main:
1. Declara un array con 10 puntuaciones
2. Llama a la función
3. Muestra los resultados
*/


#include <iostream>
using namespace std;

// Estructura para almacenar estadísticas del jugador
struct EstadisticasJugador {
    int maxPuntuacion;       // Puntuación más alta
    int minPuntuacion;       // Puntuación más baja
    float promedio;          // Promedio de todas las puntuaciones
    int vecesSuperior80;     // Cuántas veces superó los 80 puntos
};

// Función que analiza las puntuaciones usando punteros
EstadisticasJugador analizarPuntuaciones(int* inicio, int* fin) {
    EstadisticasJugador resultado;

    // Inicializamos los valores con el primero del array
    resultado.maxPuntuacion = *inicio;
    resultado.minPuntuacion = *inicio;
    resultado.promedio = *inicio;
    resultado.vecesSuperior80 = 0;

    int* actual = inicio;
    int suma = 0;
    int contador = 0;

    // Recorremos el array con punteros
    while (actual <= fin) {
        if (*actual > resultado.maxPuntuacion) {
            resultado.maxPuntuacion = *actual;
        }
        if (*actual < resultado.minPuntuacion) {
            resultado.minPuntuacion = *actual;
        }
        if (*actual > 80) {
            resultado.vecesSuperior80++;
        }

        suma += *actual;
        contador++;
        actual++;
    }

    // Calculamos el promedio
    resultado.promedio = suma / static_cast<float>(contador);

    return resultado;
}

int main() {
    // Array con las puntuaciones obtenidas en 10 partidas
    int puntuaciones[10] = {78, 95, 88, 60, 83, 70, 91, 55, 86, 100};

    // Puntero que apunta al inicio del array
    int* ptr = puntuaciones;

    // Llamamos a la función pasando el primer y último elemento
    EstadisticasJugador resultado = analizarPuntuaciones(ptr, ptr + 9);

    // Mostramos todas las puntuaciones usando aritmética de punteros
    cout << "Las puntuaciones del jugador son: ";
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Mostramos los resultados analizados
    cout << "La mayor puntuación es: " << resultado.maxPuntuacion << endl;
    cout << "La menor puntuación es: " << resultado.minPuntuacion << endl;
    cout << "La puntuación promedio es: " << resultado.promedio << endl;
    cout << "Número de veces mayor que 80: " << resultado.vecesSuperior80 << endl;

    return 0;
}


