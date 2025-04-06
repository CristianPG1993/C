/*
Crea una función llamada encontrarExtremos que reciba dos punteros (inicio y fin) 
y devuelva el mayor y menor valor del array usando aritmética de punteros.

Luego, en el main, declara un array, llama a la función, y muestra los valores extremos.
*/


#include <iostream>     // Librería para entrada y salida
using namespace std;    // Para no escribir std:: delante de cout, endl, etc.

// Estructura para guardar los valores extremos de un array
struct Extremos {
    int menor;  // Valor más pequeño
    int mayor;  // Valor más grande
};

// Función que encuentra el menor y mayor valor de un array usando punteros
Extremos encontrarExtremos(int* inicio, int* fin) {
    Extremos resultado;

    // Inicializamos el menor y mayor con el primer valor
    resultado.menor = *inicio;
    resultado.mayor = *inicio;

    // Puntero para recorrer el array
    int* actual = inicio;

    // Recorremos desde inicio hasta fin
    while (actual <= fin) {
        if (*actual < resultado.menor) {
            resultado.menor = *actual;  // Actualizamos menor si encontramos un valor más pequeño
        }
        if (*actual > resultado.mayor) {
            resultado.mayor = *actual;  // Actualizamos mayor si encontramos un valor más grande
        }
        actual++;  // Avanzamos al siguiente elemento
    }

    return resultado;  // Devolvemos los valores encontrados
}

int main() {
    // Declaramos un array con 6 valores
    int numeros[6] = {4, 9, 2, 7, 5, 1};

    // Puntero que apunta al inicio del array
    int* ptr = numeros;

    // Llamamos a la función pasarle el puntero al primer y último elemento
    Extremos resultado = encontrarExtremos(ptr, ptr + 5);

    // Mostramos los valores del array
    cout << "El array tiene estos números: ";
    for (int i = 0; i < 6; i++) {
        cout << *(ptr + i) << " ";  // Accedemos a los elementos usando aritmética de punteros
    }
    cout << endl;

    // Mostramos los resultados
    cout << "Su valor más pequeño es: " << resultado.menor << endl;
    cout << "Su valor más grande es: " << resultado.mayor << endl;

    return 0;
}
