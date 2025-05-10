/*
    Ejercicio 11 de mayo – Comparativa con std::atomic

    Descripción:
    Modificar el programa multihilo anterior para reemplazar el contador protegido por mutex
    por un contador de tipo std::atomic<int>. El objetivo es comprobar cómo se comporta 
    esta alternativa en cuanto a eficiencia y exactitud en un escenario con muchos incrementos 
    concurrentes.

    Objetivo:
    - Usar std::atomic<int> para realizar incrementos atómicos desde múltiples hilos.
    - Eliminar el uso de std::mutex y std::lock_guard.
    - Medir el tiempo total de ejecución usando std::chrono.
    - Comparar el rendimiento respecto a la versión con mutex.

    Requisitos:
    - Crear N hilos (por ejemplo, 10).
    - Cada hilo debe realizar M incrementos (por ejemplo, 1000).
    - Mostrar el valor final del contador (debe ser N × M).
    - Mostrar el tiempo total de ejecución en segundos.

    Resultado esperado:
    Valor final del contador: 10000
    Tiempo total: X.XXXX segundos
*/


#include <iostream>              // Para entrada/salida estándar (cout).
#include <vector>                // Para usar el contenedor vector.
#include <chrono>                // Para medir tiempos de ejecución.
#include <thread>                // Para usar hilos (std::thread).
#include <mutex>                 // Para usar mutex y evitar condiciones de carrera.

// Variable global compartida por todos los hilos
int contador = 0;

// Mutex para sincronizar el acceso a la variable compartida 'contador'
std::mutex mi_mutex;

// Función que será ejecutada por cada hilo
void tarea(int id, int repeticiones){
    for (int i = 0; i < repeticiones; i++){
        // lock_guard asegura que el mutex se libera automáticamente al salir del scope
        std::lock_guard<std::mutex> lock(mi_mutex);
        contador++; // Sección crítica: se accede a recurso compartido
    }
}

int main(){
    const int numeroHilos = 100;      // Total de hilos que se van a crear
    const int repeticiones = 2000;    // Cuántas veces incrementará cada hilo el contador

    std::vector<std::thread> hilos;   // Vector que almacenará los hilos

    // Inicio del cronómetro para medir el rendimiento
    auto inicio = std::chrono::high_resolution_clock::now();

    // Lanzamiento de hilos
    for (int i = 0; i < numeroHilos; i++){
        hilos.push_back(std::thread(tarea, i+1, repeticiones));
    }

    // Espera a que todos los hilos terminen
    for (auto& h : hilos){
        h.join(); // join() bloquea hasta que el hilo termine
    }

    // Fin del cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    // Mostrar resultados
    std::cout << "El tiempo de ejecución del proceso ha sido: " 
              << duracion.count() << " segundos. " <<  std::endl;

    std::cout << "Valor final del contador: " << contador << std::endl;
}
