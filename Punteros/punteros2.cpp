/*
🧪 Ejercicio 2: Modificar el valor de una variable usando un puntero
🎯 Objetivo:
Modificar el valor de una variable entera usando solo el puntero, 
no la variable directamente.

*/

#include <iostream>
using namespace std;

int main(){

    int numero = 100;

    int* ptr = &numero;

    *ptr = 200;

    cout << "El valor de numero es: " << numero << endl;
    

}