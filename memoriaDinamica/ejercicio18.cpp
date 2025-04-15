/*
================================================
🚀 EJERCICIO PRÁCTICO - AÑADIR UN ELEMENTO (PASO A PASO)
================================================

1. Crea un array dinámico de 2 enteros y pide al usuario que introduzca esos dos números.
2. Luego, pide un tercer número.
3. Crea un nuevo array dinámico con tamaño 3.
4. Copia los 2 números originales al nuevo array.
5. Guarda el número nuevo al final.
6. Muestra el contenido del array actualizado.

👉 Este ejercicio está pensado para practicar solo UNA ampliación.
*/


#include <iostream>
using namespace std;

int main() {
    // Paso 1: Crear un array dinámico para 2 números
    int* numeros;
    numeros = new int[2]; // Reservamos memoria para 2 enteros

    // Paso 2: Pedimos al usuario que introduzca los 2 primeros números
    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduce el número " << i + 1 << ": ";
        cin >> numeros[i]; // Guardamos cada número en la posición i
    }

    // Paso 3: Pedimos el tercer número
    int nuevoNumero = 0;
    cout << "\nIntroduce el tercer número: ";
    cin >> nuevoNumero;

    // Paso 4: Creamos un nuevo array con espacio para 3 números
    int* nuevoArray = new int[3];

    // Paso 5: Copiamos los 2 números del array original al nuevo
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = numeros[i];
    }

    // Paso 6: Guardamos el nuevo número al final del array nuevo
    nuevoArray[2] = nuevoNumero;

    // Paso 7: Liberamos la memoria del array original
    delete[] numeros;

    // Paso 8: Hacemos que el puntero original apunte al array nuevo
    numeros = nuevoArray;

    // Paso 9: Mostramos los 3 números almacenados en el array actualizado
    cout << "\n📋 Números actualizados:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Número " << i + 1 << ": " << numeros[i] << endl;
    }

    // Paso 10 (opcional pero recomendable): liberamos la memoria final
    delete[] numeros;

    return 0;
}
