/*
Ejercicio: Suma de dígitos pares de un número

Objetivo:
Escribir una función recursiva que reciba un número entero positivo y sume únicamente los dígitos pares.

Ejemplo:
Entrada: 4729
Salida: 6  (porque 4 y 2 son pares)

Reglas:
- No se puede usar strings ni arrays.
- Solo usar operaciones matemáticas (%, /).
- Si el número es negativo, lanzar una excepción.
- La función se llama: int sumaDigitosPares(int n)
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int sumaDigitosPares(int n){

    if ( n < 0){

        throw invalid_argument("El numero debe de ser un numero positivo. ");

    }
    if ( n == 0) return 0;
    if((n % 10) % 2 == 0){

        return (n % 10) + sumaDigitosPares(n / 10);
         
    }else{

        return sumaDigitosPares(n /10);

    }
}

int main(){

    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = sumaDigitosPares(numero);

        cout << "La suma de los numeros pares del numero " << numero << " es: " << resultado << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
    
}