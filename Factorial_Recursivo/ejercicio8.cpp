/*
Ejercicio: Invertir un número entero usando recursión

Objetivo:
Crear una función recursiva que reciba un número entero positivo y devuelva el número invertido.

Ejemplo:
Entrada: 472
Salida: 274

Reglas:
- No se pueden usar strings ni arrays.
- Solo se permite usar operaciones matemáticas.
- Si el número es negativo, lanzar una excepción.
- La función debe llamarse: int invertirNumero(int n, int acumulador = 0)
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int invertirNumero(int n, int acumulador = 0){
    if (n < 0)
        throw invalid_argument("El numero debe de ser positivo.");
    if (n == 0)
        return acumulador;
    return invertirNumero(n / 10, acumulador * 10 + (n % 10));
}

int main(){
    int numero;
    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try {
        int resultado = invertirNumero(numero);
        cout << "El número invertido es: " << resultado << endl;
    }
    catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
