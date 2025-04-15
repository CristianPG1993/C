/*
=========================================
🚀 EJERCICIO 1 - AMPLIAR MEMORIA DE ARRAY DINÁMICO
=========================================

Crea un programa en C++ que:

1. Crea un array dinámico de 3 enteros.
2. Solicita al usuario los 3 números iniciales.
3. Pide un cuarto número.
4. Crea un array nuevo con espacio para 4 elementos.
5. Copia los antiguos al nuevo array.
6. Añade el nuevo número al final.
7. Libera la memoria anterior.
8. Reasigna el puntero.
9. Muestra todos los elementos del array final.
*/

#include <iostream>
using namespace std;

int main() {
    // Paso 1: Crear array dinámico inicial
    int* numeros = new int[3];

    // Paso 2: Pedir los 3 números iniciales
    for (int i = 0; i < 3; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Paso 3: Pedir un nuevo número
    int nuevoNumero;
    cout << "\nIntroduce un número adicional: ";
    cin >> nuevoNumero;

    // Paso 4: Crear nuevo array con tamaño 4
    int* nuevoArray = new int[4];

    // Paso 5: Copiar los 3 números al nuevo array
    for (int i = 0; i < 3; i++) {
        nuevoArray[i] = numeros[i];
    }

    // Paso 6: Añadir el nuevo número
    nuevoArray[3] = nuevoNumero;

    // Paso 7: Liberar la memoria antigua
    delete[] numeros;

    // Paso 8: Redirigir el puntero al nuevo array
    numeros = nuevoArray;

    // Paso 9: Mostrar el contenido actualizado
    cout << "\nContenido del array actualizado:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Número " << i + 1 << ": " << numeros[i] << endl;
    }

    // Buen hábito: liberar memoria final
    delete[] numeros;

    return 0;
}
