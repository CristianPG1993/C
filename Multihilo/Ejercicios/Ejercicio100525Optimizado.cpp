/*
    Ejercicio final del 10 de mayo – Simulación de tareas mezcladas con multihilo

    Descripción:
    Crear un programa que lance varios hilos. Cada hilo realizará:
    1. Una tarea no crítica (simulada con un mensaje y una pequeña espera).
    2. Una tarea crítica: incrementar un contador compartido.

    El contador estará protegido con std::mutex mediante std::lock_guard
    para asegurar que solo un hilo a la vez puede modificarlo.

    Objetivo:
    - Observar que los hilos pueden ejecutar en paralelo partes no críticas.
    - Garantizar que el acceso al contador es exclusivo.
    - Comprobar el valor final correcto del contador.

    Al final, el programa debe mostrar el valor del contador, que debe ser
    igual a: número_de_hilos * repeticiones_por_hilo.

    Al quitar los cout de la función Tarea ha mejorado el rendimiento de 7.2 segundos en 
    procesar las repeticiones en los hilos a solo 0.005 segundos.
*/
#include <iostream>   // Para entrada/salida estándar (cout)
#include <vector>     // Para usar el contenedor std::vector
#include <chrono>     // Para medir el tiempo de ejecución
#include <mutex>      // Para usar std::mutex y evitar condiciones de carrera
#include <thread>     // Para crear y manejar hilos (std::thread)

// Variable global compartida entre todos los hilos
int contador = 0;

// Mutex global para proteger el acceso a la variable 'contador'
std::mutex mi_mutex;

// Función que ejecutará cada hilo
void tarea(int id, int repeticiones) {
    // Cada hilo realiza 'repeticiones' veces esta operación
    for (int i = 0; i < repeticiones; i++) {
        // Lock automático del mutex: evita que más de un hilo entre en esta sección crítica a la vez
        std::lock_guard<std::mutex> lock(mi_mutex);
        contador++;  // Sección crítica: modificación de la variable compartida
    }
}

int main() {
    const int numeroHilos = 10;     // Número de hilos a lanzar
    const int repeticiones = 1000;  // Número de repeticiones por hilo

    std::vector<std::thread> hilos; // Vector donde almacenamos los hilos

    // Marca el tiempo de inicio del proceso multihilo
    auto inicio = std::chrono::high_resolution_clock::now();

    // Lanzamos los hilos
    for (int i = 0; i < numeroHilos; i++) {
        // Cada hilo ejecuta la función 'tarea'
        hilos.push_back(std::thread(tarea, i + 1, repeticiones));
    }

    // Esperamos a que todos los hilos terminen
    for (auto& h : hilos) {
        h.join(); // join bloquea hasta que el hilo h finalice
    }

    // Marca el tiempo de fin del proceso
    auto fin = std::chrono::high_resolution_clock::now();

    // Calculamos la duración en segundos
    std::chrono::duration<double> duracion = fin - inicio;

    // Mostramos el tiempo total que tardó el programa
    std::cout << "Tiempo total: " << duracion.count() << " segundos" << std::endl;

    // Podría añadirse también:
    // std::cout << "Valor final del contador: " << contador << std::endl;
}
