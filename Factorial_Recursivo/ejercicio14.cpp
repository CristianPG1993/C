/*
Ejercicio: Contar cuántos dígitos del número son mayores que 5

Objetivo:
Escribir una función recursiva que reciba un número entero positivo y
 devuelva cuántos de sus dígitos son mayores que 5.

Ejemplo:
Entrada: 4869
Salida: 3 (porque 8, 6 y 9 son mayores que 5)

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, / y recursión.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: int contarMayoresQueCinco(int n)
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int contarMayoresQueCinco(int n){

    if (n < 0){

        throw invalid_argument("\nEl numero debe de ser positivo. ");

    }
    if (n == 0) return 0;

    int digito = n % 10;

    if(digito > 5){

        return 1 + contarMayoresQueCinco(n / 10);

    } else{

        return contarMayoresQueCinco(n / 10);

    }
}

int main(){

    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = contarMayoresQueCinco(numero);

        cout << "Los numeros mayores que 5 en " << numero << " son: " << resultado << endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;

    }

    return 0;

    
}