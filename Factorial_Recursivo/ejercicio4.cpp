/*
Ejercicio: Suma de los dígitos de un número

Objetivo:
Crear una función recursiva que sume todos los dígitos de un número entero positivo.

Ejemplo:
Entrada: 472
Salida: 13 → (4 + 7 + 2)

Reglas:
- Si el número es negativo, lanzar excepción con throw invalid_argument.
- La función debe llamarse: int sumaDigitos(int n)
- No se permite usar strings ni arrays. Solo matemáticas y recursión.
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int sumaDigitos(int n){

    if (n < 0){

        throw invalid_argument("El numero tiene que ser positivo. ");

    }
    if ( n == 0) return 0;
    return (n % 10) + sumaDigitos(n / 10);

}

int main(){

    int numero;

    cout <<"\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = sumaDigitos(numero);

        cout << "La suma de los digitos de " << numero << " es: " << resultado << endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;

    }
    return 0;
    
}