/*
Crea una estructura llamada ResultadoMedias que contenga dos campos:
- mediaPositivos
- mediaNegativos

Crea una función llamada calcularMedias que reciba dos punteros (inicio y fin) 
y calcule la media de los valores positivos y la de los negativos del array.

En el main, declara un array de enteros con valores positivos y negativos, 
llama a la función, y muestra los resultados.
*/


#include <iostream>     // Librería para entrada y salida estándar
using namespace std;

// Estructura que almacena las medias de los valores positivos y negativos
struct ResultadoMedias {
    float mediaPositivos; // Media de los números positivos
    float mediaNegativos; // Media de los números negativos
};

// Función que calcula las medias de los valores positivos y negativos de un array usando punteros
ResultadoMedias calcularMedias(int* inicio, int* fin) {
    // Variables para acumular la suma de positivos y negativos, y sus contadores
    float positivos = 0;
    float negativos = 0;
    int contadorPositivos = 0;
    int contadorNegativos = 0;

    // Puntero auxiliar para recorrer el array desde inicio hasta fin
    int* actual = inicio;

    // Recorremos el array usando aritmética de punteros
    while (actual <= fin) {
        if (*actual >= 0) { // Si el valor es positivo o cero
            positivos += *actual;  // Acumula la suma de los valores positivos
            contadorPositivos++;   // Incrementa el contador de positivos
        } else { // Si el valor es negativo
            negativos += *actual;  // Acumula la suma de los valores negativos
            contadorNegativos++;   // Incrementa el contador de negativos
        }
        actual++;  // Avanza al siguiente elemento del array
    }

    // Declaramos una variable de tipo ResultadoMedias para almacenar las medias calculadas
    ResultadoMedias resultado;

    // Calculamos la media de los positivos solo si hay al menos uno
    if (contadorPositivos > 0) {
        resultado.mediaPositivos = positivos / contadorPositivos;
    } else {
        resultado.mediaPositivos = 0; // Si no hay positivos, la media se establece en 0
    }

    // Calculamos la media de los negativos solo si hay al menos uno
    if (contadorNegativos > 0) {
        resultado.mediaNegativos = negativos / contadorNegativos;
    } else {
        resultado.mediaNegativos = 0; // Si no hay negativos, la media se establece en 0
    }

    // Devolvemos la estructura con las medias calculadas
    return resultado;
}

int main() {
    // Declaramos un array de 8 enteros con valores positivos y negativos
    int numeros[8] = {4, -2, 6, -5, 0, 9, -3, 1};
    // Creamos un puntero que apunta al inicio del array
    int* ptr = numeros;

    // Llamamos a la función calcularMedias pasándole el puntero al primer elemento y el puntero al último
    ResultadoMedias resultado = calcularMedias(ptr, ptr + 7);

    // Mostramos el contenido del array recorriéndolo con aritmética de punteros
    cout << "Los números son: ";
    for (int i = 0; i < 8; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    // Mostramos la media de los valores positivos y negativos
    cout << "La media de los positivos es: " << resultado.mediaPositivos << endl;
    cout << "La media de los negativos es: " << resultado.mediaNegativos << endl;

    return 0;
}


