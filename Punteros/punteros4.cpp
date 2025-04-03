/*
Ejercicio 4: Invertir un array usando punteros

Descripción:
Crea un programa que tome un array de enteros y lo invierta utilizando punteros. 
No se permite usar índices (nada de array[i]): debes usar solo aritmética de punteros.

Requisitos:
1. Declarar un array de 5 enteros con valores iniciales.
2. Usar punteros para invertir el contenido del array.
3. Mostrar el array antes y después de invertirlo.
4. Usar funciones para organizar el código (por ejemplo, una función invertirArray).
*/


#include <iostream>     // Librería para entrada y salida
using namespace std;    // Evita tener que escribir std:: en cada cout, endl, etc.

int main() {

    // Declaramos un array de 5 enteros con valores iniciales
    int numeros[5] = {1, 2, 3, 4, 5};

    // Creamos un puntero que apunta al inicio del array
    int* ptr = numeros;

    // Mostrar el array original
    cout << "Array original: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // Usamos aritmética de punteros para acceder a los elementos
    }
    cout << endl; // Salto de línea para separar visualmente la salida

    // Punteros para invertir el array: uno al inicio y otro al final
    int* inicio = &numeros[0];      // o también: int* inicio = ptr;
    int* fin = &numeros[4];         // o: int* fin = ptr + 4;

    // Invertimos el array intercambiando los valores a los que apuntan inicio y fin
    while (inicio < fin) {
        int temp = *inicio;   // Guardamos temporalmente el valor de inicio
        *inicio = *fin;       // Copiamos el valor de fin en inicio
        *fin = temp;          // Recuperamos el valor original de inicio en fin

        // Movemos los punteros para continuar hacia el centro del array
        inicio++;
        fin--;
    }

    // Mostrar el array después de invertirlo
    cout << "Array invertido: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // Nuevamente usamos punteros para imprimir los valores
    }
    cout << endl; // Salto de línea final

    return 0; // Fin del programa
}
