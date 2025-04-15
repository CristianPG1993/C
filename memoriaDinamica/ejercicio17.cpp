/*
=============================================
🚀 EJERCICIO 2 - AÑADIR ELEMENTOS EN BUCLE
=============================================

Crea un programa en C++ que:

1. Empiece con un array dinámico vacío (tamaño 0).
2. En un bucle, pida al usuario un número entero y lo añada al array.
3. Después de cada inserción, pregunte si desea seguir ("s" para sí, "n" para no).
4. El array debe ampliarse dinámicamente cada vez que se añade un nuevo número.
5. Al terminar, muestra todos los números introducidos.

El objetivo es reforzar la lógica de cómo ampliar arrays dinámicos durante la ejecución.
*/


#include <iostream>
using namespace std;

int main() {
    int* numeros = nullptr;   // Array dinámico vacío
    int tamañoArray = 0;      // Contador de elementos
    char opcion;
    int nuevoNumero;

    do {
        // Paso 1: Pedir nuevo número
        cout << "\nIntroduce un número entero: ";
        cin >> nuevoNumero;

        // Paso 2: Crear nuevo array con tamaño aumentado
        int* nuevoArray = new int[tamañoArray + 1];

        // Paso 3: Copiar elementos anteriores (si existen)
        for (int i = 0; i < tamañoArray; i++) {
            nuevoArray[i] = numeros[i];
        }

        // Paso 4: Añadir nuevo número al final
        nuevoArray[tamañoArray] = nuevoNumero;

        // Paso 5: Liberar memoria anterior
        delete[] numeros;

        // Paso 6: Redirigir puntero
        numeros = nuevoArray;

        // Paso 7: Aumentar tamaño
        tamañoArray++;

        // Preguntar si quiere seguir
        cout << "¿Desea introducir otro número? (s/n): ";
        cin >> opcion;

    } while (opcion == 's');

    // Mostrar todos los números introducidos
    cout << "\n📋 Números introducidos:\n";
    for (int i = 0; i < tamañoArray; i++) {
        cout << "Número " << i + 1 << ": " << numeros[i] << endl;
    }

    // Liberar memoria final
    delete[] numeros;

    return 0;
}
