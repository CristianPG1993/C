/*
    Ejercicio 10 de mayo – Simulador multihilo de escaneo de puertos

    Descripción:
    Simular un escáner de puertos usando múltiples hilos. Cada hilo tomará un puerto de una lista 
    compartida (ej: del 1000 al 1100), simulará un escaneo (con una pausa de milisegundos y un resultado aleatorio), 
    y almacenará el resultado (abierto o cerrado) en una estructura compartida protegida por mutex.

    Objetivo:
    - Practicar acceso sincronizado a recursos compartidos (lista de puertos, resultados).
    - Repartir tareas dinámicamente entre hilos (cada hilo pide un nuevo puerto al terminar uno).
    - Registrar resultados sin condición de carrera.
    - Medir el tiempo total de escaneo con std::chrono.

    Pistas:
    - Usar std::vector<int> para la lista de puertos.
    - Proteger acceso a la lista de tareas con std::mutex.
    - Simular escaneo con std::this_thread::sleep_for(...) y std::rand().
    - Guardar resultados en std::map<int, bool> (puerto -> abierto o cerrado).

    Resultado esperado:
    - Un resumen al final con los puertos abiertos y cerrados.
    - Tiempo total de escaneo.
*/

#include <iostream>    // Para imprimir en consola
#include <vector>      // Para almacenar la lista de puertos a escanear
#include <map>         // Para guardar el resultado de cada puerto (abierto/cerrado)
#include <thread>      // Para lanzar múltiples hilos
#include <mutex>       // Para proteger datos compartidos entre hilos
#include <chrono>      // Para simular latencia y medir tiempo de ejecución
#include <cstdlib>     // Para usar rand()
#include <ctime>       // Para inicializar la semilla de rand()

// Variables globales compartidas entre los hilos
std::vector<int> puertos;         // Lista de puertos a escanear
std::map<int, bool> resultado;    // Resultado del escaneo (true = abierto, false = cerrado)
std::mutex mi_mutex;              // Mutex para proteger acceso concurrente

// Función que ejecutará cada hilo
void tarea() {
    while (true) {
        int puerto;

        // Sección crítica para acceder a la lista de puertos
        {
            std::lock_guard<std::mutex> lock(mi_mutex);

            if (puertos.empty()) {
                break;  // Si ya no quedan puertos, salimos del bucle
            }

            puerto = puertos.back();  // Tomamos el último puerto disponible
            puertos.pop_back();       // Lo eliminamos del vector
        }

        // Simulamos el tiempo que tarda en "escanear" un puerto
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Simulamos aleatoriamente si el puerto está abierto o cerrado
        bool abierto = rand() % 2;

        // Sección crítica para escribir en el mapa de resultados
        {
            std::lock_guard<std::mutex> lock(mi_mutex);
            resultado[puerto] = abierto;  // Guardamos el resultado del escaneo
        }
    }
}

int main() {
    // Inicializamos la semilla para generar resultados aleatorios diferentes en cada ejecución
    std::srand(std::time(nullptr));

    // Rellenamos el vector con los puertos del 1000 al 1100
    for (int i = 1000; i <= 1100; i++) {
        puertos.push_back(i);
    }

    const int numeroHilos = 10;  // Número de hilos a lanzar

    std::vector<std::thread> hilos;  // Contenedor para los hilos

    // Registramos el tiempo de inicio
    auto inicio = std::chrono::high_resolution_clock::now();

    // Lanzamos todos los hilos
    for (int i = 0; i < numeroHilos; i++) {
        hilos.push_back(std::thread(tarea));
    }

    // Esperamos a que todos los hilos terminen su ejecución
    for (auto& h : hilos) {
        h.join();
    }

    // Mostramos los resultados del escaneo de puertos
    for (auto& par : resultado) {
        std::cout << "Puerto " << par.first << ": " 
                  << (par.second ? "ABIERTO" : "CERRADO") << std::endl;
    }

    // Registramos el tiempo de fin
    auto fin = std::chrono::high_resolution_clock::now();

    // Calculamos y mostramos la duración total del escaneo
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "El tiempo de duración del escaneo de puertos ha sido: " 
              << duracion.count() << " segundos. " << std::endl;

    return 0;
}
