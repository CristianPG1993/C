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
*/


#include <iostream>   // Para imprimir en consola
#include <thread>     // Para manejar múltiples hilos
#include <mutex>      // Para evitar condiciones de carrera con std::mutex
#include <vector>     // Para almacenar los hilos en un vector
#include <chrono>     // Para medir el tiempo de ejecución

// Variable compartida entre los hilos
int contador = 0;

// Mutex para proteger la variable compartida 'contador'
std::mutex mi_mutex;

// Función que ejecutará cada hilo
void tarea(int id, int repeticiones){
    for (int i = 0; i < repeticiones; i++){
        
        // Imprime el número del hilo. Esto puede generar salidas mezcladas en consola.
        std::cout << "Hilo " << id << std::endl;

        {
            // Sección crítica protegida por mutex
            std::lock_guard<std::mutex> lock(mi_mutex);
            
            contador++;  // Incrementa el contador de forma segura

            // Imprime el valor actualizado del contador
            std::cout << "Contador:  " << contador << std::endl;
        }
    }
}

int main(){
    const int numeroHilos = 10;      // Total de hilos a lanzar
    const int repeticiones = 1000;   // Número de veces que cada hilo ejecuta la tarea

    std::vector<std::thread> hilos;  // Vector para almacenar los hilos

    // Marca el inicio de la ejecución
    auto inicio = std::chrono::high_resolution_clock::now();

    // Crea y lanza todos los hilos
    for (int i = 0; i < numeroHilos; i++){
        hilos.push_back(std::thread(tarea, i + 1, repeticiones));
    }

    // Espera a que todos los hilos terminen
    for (auto& h : hilos){
        h.join();
    }

    // Marca el final de la ejecución
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcula la duración de la ejecución
    std::chrono::duration<double> duracion = fin - inicio;

    // Muestra el tiempo total que tardó el programa
    std::cout << "Tiempo total: " << duracion.count() << " segundos" << std::endl;
}
