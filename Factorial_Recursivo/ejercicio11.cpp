/*
Ejercicio: Contar cuántos dígitos pares tiene un número

Objetivo:
Crear una función recursiva que reciba un número entero positivo y devuelva cuántos de sus dígitos son pares.

Ejemplo:
Entrada: 4729
Salida: 2 (porque 4 y 2 son pares)

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, / y recursión.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: int contarDigitosPares(int n)
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int contarDigitosPares(int n){

    if ( n < 0){

        throw invalid_argument("\nEl numero debe de ser positivo. ");

    }
    if (n == 0)return 0;
    if((n % 10) % 2 == 0){

        return 1 + contarDigitosPares(n /10);

    } else {
        return contarDigitosPares(n / 10);
    }
}

int main(){

    int numero;

    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = contarDigitosPares(numero);

        cout << "El numero " << numero << " tiene " << resultado << " digitos pares." << endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " <<  e.what() << endl;
    }

    return 0;

    
}