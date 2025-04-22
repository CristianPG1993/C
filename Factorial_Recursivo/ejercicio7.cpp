/*
Ejercicio: Calcular la longitud de la representación binaria

Objetivo:
Escribir una función recursiva que reciba un número entero positivo y devuelva la cantidad de bits que tiene su representación binaria.

Ejemplo:
Entrada: 13  → 1101
Salida: 4

Reglas:
- Si el número es negativo, lanzar una excepción.
- La función se llama: int longitudBinaria(int n)
- Solo se puede usar división, módulo y recursión (no strings, ni arrays, ni logaritmos).
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int longitudBinaria(int n){

    if ( n < 0){

        throw invalid_argument("El numero debe de ser un numero positivo. ");

    }
    if(n == 0) return 0;
    return 1 + longitudBinaria(n / 2);

}

int main(){

    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = longitudBinaria(numero);

        cout << "El numero " << numero << " tiene " << resultado << " digitos binarios." << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
    
}