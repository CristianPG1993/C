#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <vector>


std::atomic<int> contador(0);

void tarea(int id, int repeticiones){

    for (int i = 0; i < repeticiones; i++){

        contador++;
        
    }
}

int main(){

    const int numHilos = 20;
    const int repeticiones = 40000;

    std::vector<std::thread> hilos;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numHilos; i++){

        hilos.push_back(std::thread(tarea, i + 1, repeticiones));

    }

    for (auto& h : hilos){

        h.join();

    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "La duración del proceso ha sido: " << duracion.count() << " segundos. " << std::endl;
    std::cout << "Valor de las tareas procesadas: " << contador << std::endl;

}