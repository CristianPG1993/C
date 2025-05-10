/*
    Ejercicio: Uso de std::mutex para proteger una variable compartida en C++

    Descripción:
    Este programa es un ejemplo práctico para entender cómo se usa std::mutex
    para evitar condiciones de carrera cuando varios hilos acceden a una misma
    variable global. El objetivo es demostrar cómo la sincronización con mutex
    asegura que el resultado final sea correcto incluso en entornos multihilo.

    Instrucciones:
    - Se crea una variable global llamada 'contador'.
    - Se lanzan 5 hilos, y cada hilo incrementa la variable 10.000 veces.
    - Se utiliza un std::mutex para proteger la zona crítica donde se incrementa el contador.
    - Al final, el valor esperado del contador es 50.000 si se sincroniza correctamente.

    Objetivo:
    - Practicar el uso de std::thread y std::mutex.
    - Entender cómo evitar errores de concurrencia (race conditions).
    - Observar qué ocurre si se omite el uso del mutex (ejecutar sin lock/unlock).
*/



#include <iostream>   // Para imprimir por consola con cout
#include <thread>     // Para usar std::thread
#include <mutex>      // Para usar std::mutex (bloqueo)
#include <vector>     // Para almacenar los hilos


// Variable compartida que todos los hilos van a modificar
int contador = 0;

// Mutex para proteger el acceso al contador
std::mutex mi_mutex;

// Función que ejecutará cada hilo
void incrementar_contador(int veces) {
    for (int i = 0; i < veces; ++i) {
        // Sección crítica protegida con un mutex
        mi_mutex.lock();   // Bloqueamos el acceso para los demás hilos
        ++contador;        // Incrementamos la variable compartida
        mi_mutex.unlock(); // Liberamos el acceso
    }
}

int main() {
    const int num_hilos = 100;        // Número total de hilos
    const int repeticiones = 1000000; // Cuántas veces cada hilo incrementará el contador

    std::vector<std::thread> hilos;           // Vector para almacenar los hilos

    // Creamos y lanzamos los hilos
    for (int i = 0; i < num_hilos; ++i) {
        // Cada hilo ejecutará la función 'incrementar_contador'
        hilos.push_back(std::thread(incrementar_contador, repeticiones)); // se añade cada hilo al final del vector
    }

    // Esperamos a que todos los hilos terminen
    for (auto& h : hilos) {
        h.join(); // join() espera a que el hilo finalice
    }

    // Mostramos el resultado final
    std::cout << "Valor final del contador: " << contador << std::endl;
    // Esperamos que el valor final sea 5 * 10000 = 50000

    return 0;
}
