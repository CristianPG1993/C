/*
    Ejercicio avanzado – Logger multihilo sincronizado (11 de mayo)

    Descripción:
    Simular una herramienta que lanza varios hilos para realizar tareas 
    (como escanear puertos) y registrar un log con mensajes de cada hilo.

    Cada hilo debe:
    1. Tomar un puerto de una lista compartida.
    2. Simular un escaneo (espera + resultado aleatorio).
    3. Generar un mensaje: "Hilo X: escaneó puerto Y (ABIERTO/CERRADO)".
    4. Guardar ese mensaje en un vector de strings llamado 'log'.

    Requisitos:
    - Usar std::vector<std::string> log como estructura de log.
    - Proteger el acceso al log con std::mutex para evitar condiciones de carrera.
    - Lanzar N hilos, que trabajan en paralelo sobre una lista de puertos.
    - Mostrar al final todos los mensajes del log en orden de inserción.

    Resultado esperado:
    - Registro completo de la actividad de cada hilo.
    - Tiempo total de ejecución medido con std::chrono.

    Objetivo:
    - Consolidar el uso de mutex con estructuras dinámicas.
    - Aprender a registrar actividad concurrente sin errores.
*/


#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib> // rand
#include <functional> // std::hash

// Estructuras globales
std::vector<int> puertos;                         // Lista de puertos por escanear
std::vector<std::string> registros;               // Bitácora de actividad (log)
std::vector<std::thread> hilos;                   // Lista de hilos lanzados
std::mutex mi_mutex;                              // Mutex para proteger acceso a puertos y log

// Función que simula el trabajo de cada hilo
void tarea() {
    while (true) {
        int puerto;

        // Zona crítica para acceder a la lista de puertos
        {
            std::lock_guard<std::mutex> lock(mi_mutex);
         
            if (puertos.empty()){
                
                break;
            }
            puerto = puertos.back();
            puertos.pop_back();
        }

        // Simular escaneo del puerto
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        bool abierto = rand() % 2;

        // Construir el mensaje del log
        std::string mensaje = "Hilo " + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id())) +
                              ": escaneó puerto " + std::to_string(puerto) +
                              (abierto ? " (ABIERTO)" : " (CERRADO)");

        // Zona crítica para escribir en el log
        {
            std::lock_guard<std::mutex> lock(mi_mutex);
            registros.push_back(mensaje);
        }
    }
}

int main() {
    // Inicializar puertos del 1000 al 1050
    for (int i = 1000; i <= 1050; i++) {
        puertos.push_back(i);
    }

    const int numeroHilos = 10;

    auto inicio = std::chrono::high_resolution_clock::now();

    // Lanzar hilos
    for (int i = 0; i < numeroHilos; i++) {
        hilos.push_back(std::thread(tarea));
    }

    // Esperar a que todos los hilos terminen
    for (auto& h : hilos) {
        h.join();
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    // Mostrar contenido del log
    for (const auto& entrada : registros) {
        std::cout << entrada << std::endl;
    }

    std::cout << "\nTiempo total de escaneo: " << duracion.count() << " segundos." << std::endl;

    return 0;
}






