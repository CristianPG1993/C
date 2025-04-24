/*
Ejercicio: Suma de dígitos impares de un número

Objetivo:
Escribir una función recursiva que reciba un número entero positivo y sume únicamente los dígitos impares.

Ejemplo:
Entrada: 4729
Salida: 16  (porque 7 y 9 son impares)

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, / y recursión.
- Si el número es negativo, lanzar una excepción.
- La función se llama: int sumaDigitosImpares(int n)
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int sumaDigitosImpares(int n){

    if (n < 0 ){

        throw invalid_argument("\nEl numero debe de ser positivo. ");

    }
    if (n == 0) return 0;

    if ((n % 10) % 2 == 0){

        return sumaDigitosImpares(n / 10);

    }else{
        return (n % 10) + sumaDigitosImpares(n / 10); 
    }

}

int main(){

    int numero;

    cout <<"\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = sumaDigitosImpares(numero);

        cout << "La suma de los numeros impares de " << numero << " es: " << resultado << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " <<  e.what() << endl;
    }

    return 0;
    
}