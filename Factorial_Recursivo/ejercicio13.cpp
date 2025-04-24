/*
Ejercicio: Verificar si todos los dígitos de un número son pares

Objetivo:
Crear una función recursiva que determine si todos los dígitos de un número 
entero positivo son pares.

Ejemplo:
Entrada: 2486 → true
Entrada: 4821 → false

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar %, /, y recursión.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: bool todosPares(int n)
*/

#include <iostream>
#include <stdexcept>
using namespace std;

bool todosPares(int n) {
    if (n < 0) {
        throw invalid_argument("El numero debe de ser positivo.");
    }

    if (n == 0) return true;  // caso base: no se ha encontrado ningún impar

    int digito = n % 10;

    if (digito % 2 != 0) {
        return false;  // si encuentro un impar, corto directamente
    }

    return todosPares(n / 10);  // sigo con el siguiente dígito
}


int main(){

    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        bool resultado = todosPares(numero);

        if (resultado) {
            cout << "Todos los digitos del numero " << numero << " son pares." << endl;
        } else {
            cout << "No todos los digitos del numero " << numero << " son pares." << endl;
        }
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
    
}
