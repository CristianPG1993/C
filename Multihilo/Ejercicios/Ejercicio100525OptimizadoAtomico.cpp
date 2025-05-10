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


#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

int contador = 0;
std::mutex mi_mutex;

void tarea(int id, int repeticiones){

    for (int i = 0; i < repeticiones; i++){

        std::lock_guard<std::mutex> lock(mi_mutex);
        contador++;
    }

}

int main(){

    const int numeroHilos = 100;
    const int repeticiones = 2000;

    std::vector<std::thread> hilos;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numeroHilos;i++){

        hilos.push_back(std::thread(tarea, i+1, repeticiones));

    }

    for (auto& h : hilos){

        h.join();

    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "El tiempo de ejecución del proceso ha sido: " << duracion.count() << " segundos. " <<  std::endl;
    std::cout << "Valor final del contador: " << contador << std::endl;


}