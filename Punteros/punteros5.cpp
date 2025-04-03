#include <iostream>     // Librería para entrada y salida estándar
using namespace std;    // Para evitar escribir std:: antes de cout, endl, etc.


// Función que invierte un array usando punteros
void invertirArray(int* inicio, int* fin) {
    // Mientras los punteros no se crucen
    while (inicio < fin) {
        int temp = *inicio;    // Guardamos el valor apuntado por inicio
        *inicio = *fin;        // Reemplazamos el valor de inicio con el de fin
        *fin = temp;           // Guardamos el valor original de inicio en fin

        inicio++;  // Avanzamos el puntero de inicio hacia la derecha
        fin--;     // Retrocedemos el puntero de fin hacia la izquierda
    }
}

int main() {
    // Declaramos un array de 5 enteros
    int numeros[5] = {1, 2, 3, 4, 5};

    // Creamos un puntero que apunta al inicio del array
    int* ptr = numeros;

    // Mostramos el contenido original del array
    cout << "El array original es: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // Usamos aritmética de punteros para recorrer
    }
    cout << endl;

    // Definimos dos punteros: uno al inicio y otro al final del array
    int* inicio = &numeros[0];   // o: int* inicio = ptr;
    int* fin = &numeros[4];      // o: int* fin = ptr + 4;

    // Llamamos a la función que invierte el array
    invertirArray(inicio, fin);

    // Mostramos el contenido del array después de invertirlo
    cout << "El array invertido es: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // Recorrido con punteros, igual que antes
    }
    cout << endl;

    return 0; // Fin del programa
}
