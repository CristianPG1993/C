/*
Crea una función llamada buscarElemento que reciba:
- dos punteros (inicio y fin)
- un número entero a buscar

Debe recorrer el array usando punteros (sin usar índices)
y devolver la posición (desde 0) en la que se encuentra el número.

Si no lo encuentra, debe devolver -1.

En el main, declara un array, pide al usuario un número a buscar,
llama a la función y muestra el resultado.
*/


#include <iostream>
using namespace std;

// Función que busca un valor en el array usando punteros
// Devuelve la posición si lo encuentra, o -1 si no lo encuentra
int buscarElemento(int* inicio, int* fin, int valorBuscado) {
    int* actual = inicio;   // Puntero que recorrerá el array
    int posicion = 0;       // Contador de posición, empieza en 0

    // Recorremos desde el inicio hasta el final del array
    while (actual <= fin) {
        if (*actual == valorBuscado) {
            return posicion; // Si encontramos el valor, devolvemos la posición
        }
        actual++;    // Avanzamos el puntero al siguiente elemento
        posicion++;  // Avanzamos la posición
    }

    return -1; // Si no lo encontramos, devolvemos -1
}

int main() {
    // Declaramos un array con 6 valores
    int numeros[6] = {3, 7, 2, 9, 5, 8};

    // Puntero que apunta al inicio del array
    int* ptr = numeros;

    // Variable donde guardaremos el número a buscar
    int valor;

    // Pedimos al usuario un número
    cout << "Introduce un número: " << endl;
    cin >> valor;

    // Llamamos a la función buscarElemento y guardamos el resultado
    int posicion = buscarElemento(ptr, ptr + 5, valor);

    // Mostramos el resultado
    if (posicion == -1) {
        cout << "El número no se encuentra en el array." << endl;
    } else {
        cout << "El número se encuentra en la posición: " << posicion << endl;
    }

    return 0;
}
