/*
Ejercicio: Contar cuántos dígitos impares tiene un número

Objetivo:
Crear una función recursiva que reciba un número entero positivo y devuelva cuántos de sus dígitos son impares.

Ejemplo:
Entrada: 4729
Salida: 2 (porque 7 y 9 son impares)

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, / y recursión.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: int contarDigitosImpares(int n)
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int contarDigitosImpares(int n){

    if (n < 0){

        throw invalid_argument("El numero debe de ser positivo. ");

    }
    if ( n == 0) return 0;

    if((n % 10) % 2 == 0){

        return contarDigitosImpares(n / 10);

    }else{

        return 1 + contarDigitosImpares(n / 10);

    }

}

int main (){

    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = contarDigitosImpares(numero);

        cout << "En el numero " << numero << " existen " << resultado << " numeros impares. " << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;

    }

    return 0;
    
}