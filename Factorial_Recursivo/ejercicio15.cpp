/*
Ejercicio: Contar cuántos dígitos del número son pares y mayores que 5

Objetivo:
Crear una función recursiva que reciba un número entero positivo y devuelva cuántos de sus dígitos son a la vez pares y mayores que 5.

Ejemplo:
Entrada: 86429
Salida: 2 (porque 8 y 6 cumplen ambas condiciones)

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, / y recursión.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: int contarParesMayoresQueCinco(int n)
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int contarParesMayoresQueCinco(long long n){

    if (n < 0){

        throw invalid_argument("\nEl numero debe de ser positivo. ");

    }
    if ( n == 0) return 0;
    
    long long digito = n % 10;

    if ((digito % 2 == 0) && (digito > 5)){

        cout << digito << " ";

        return 1 + contarParesMayoresQueCinco(n / 10);

    }else{

        return contarParesMayoresQueCinco(n / 10);

    }
}

int main(){

    long long numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    cout << "\nLos numeros que cumplen con las dos condiciones son: " << endl;
    try
    {
        int resultado = contarParesMayoresQueCinco(numero);

        
        cout << "\nNumero que son pares y mayores que 5 en " << numero << " son: " << resultado << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;

    }
    return 0;
    
}