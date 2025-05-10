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

#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>
#include <thread>

int contador = 0;
std::mutex mi_mutex;

void tarea(int id, int repeticiones){

    for (int i = 0; i < repeticiones; i++){

    std::lock_guard<std::mutex> lock(mi_mutex);
    contador++;
    }

}

int main(){

    const int numeroHilos = 10;
    const int repeticiones = 1000;

    std::vector<std::thread> hilos;
    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numeroHilos; i++){

        hilos.push_back(std::thread(tarea, i+1, repeticiones));

    }

    for (auto& h : hilos){

        h.join();
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

     std::cout << "Tiempo total: " << duracion.count() << " segundos" << std::endl;

}