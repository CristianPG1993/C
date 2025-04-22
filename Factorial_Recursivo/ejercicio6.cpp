/*
Ejercicio: Convertir un número decimal a binario usando recursión

Objetivo:
Escribir una función recursiva que reciba un número entero positivo y muestre su representación binaria por consola.

Ejemplo:
Entrada: 13
Salida: 1101

Reglas:
- Si el número es negativo, lanzar una excepción con throw.
- La función se llama: void mostrarBinario(int n)
- No se permite usar arrays, strings, ni operadores de bit.
- Solo se permite usar %, / y cout.
- El número binario debe imprimirse en orden correcto.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

void mostrarBinario(int n) {
    // Validación: solo permitimos números positivos
    if (n < 0) {
        throw invalid_argument("El número debe ser positivo.");
    }

    // Caso base: cuando n llega a 0, no imprimimos nada (salimos de la recursión)
    if (n == 0) return;

    // Paso recursivo: primero llamamos con n / 2 (bit más significativo)
    mostrarBinario(n / 2);

    // Luego imprimimos el bit actual (n % 2)
    cout << (n % 2);
}

int main() {
    int numero;
    cout << "\nIntroduce un número positivo: ";
    cin >> numero;

    try {
        cout << "Representación binaria de " << numero << ": ";
        if (numero == 0) {
            cout << 0; // caso especial: 0 se imprime como "0"
        } else {
            mostrarBinario(numero);
        }
        cout << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
