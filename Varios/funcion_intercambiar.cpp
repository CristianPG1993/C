#include <iostream>  // Librería para entrada/salida estándar
using namespace std; // Uso del espacio de nombres estándar (evita poner std:: delante)


// Definimos una estructura llamada Par para almacenar dos valores enteros
struct Par {
    int a; // Primer valor (será el nuevo valor de X después del intercambio)
    int b; // Segundo valor (será el nuevo valor de Y después del intercambio)
};


// Función que intercambia dos valores enteros usando retorno de estructura
Par intercambiar(int x, int y) {
    Par resultado;      // Creamos una variable de tipo Par
    resultado.a = y;    // Guardamos y como nuevo valor para x
    resultado.b = x;    // Guardamos x como nuevo valor para y
    return resultado;   // Devolvemos el resultado con los valores intercambiados
}


int main() {
    // Declaramos dos variables enteras con valores iniciales
    int x = 10;
    int y = 20;

    // Mostramos sus valores antes del intercambio
    cout << "El valor de X es: " << x << endl;
    cout << "El valor de Y es: " << y << endl;

    // Llamamos a la función intercambiar y guardamos el resultado en una variable de tipo Par
    Par resultado = intercambiar(x, y);

    // Mostramos los valores después del intercambio usando los campos de la estructura
    cout << "Después del intercambio:" << endl;
    cout << "El valor de X es: " << resultado.a << endl;
    cout << "El valor de Y es: " << resultado.b << endl;

    return 0; // Fin del programa
}
