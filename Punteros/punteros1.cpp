/*
🧪 Ejercicio 1: Mostrar el valor y la dirección de una variable
🎯 Objetivo:
Crear un programa que declare una variable, cree un puntero que apunte a ella, 
y muestre:

El valor de la variable.

La dirección de memoria de la variable.

El contenido del puntero.

La dirección del puntero.

El valor apuntado por el puntero.
*/


#include <iostream>
using namespace std;

int main(){

    int x = 42;
    int* p = &x;


    cout << "El valor de X es: " << x << endl;            // El valor de X es: 42
    cout << "La dirección de X es: " << &x << endl;       // La direcci├│n de X es: 0x61ff0c
    cout << "El contenido de P es: " << p << endl;        // El contenido de P es: 0x61ff0c
    cout << "La dirección de P es: " << &p  << endl;      // La direcci├│n de P es: 0x61ff08
    cout << "El valor apuntado por P es: " << *p << endl; // El valor apuntado por P es: 42
 
}
