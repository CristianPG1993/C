/*
Ejercicio: Contar cuántos unos tiene un número binario

Objetivo:
Escribe una función recursiva que cuente la cantidad de unos ('1') que tiene un número binario representado en decimal.

Ejemplo:
Entrada: 13   →  Binario: 1101
Salida: 3     →  Porque hay tres unos en 1101

Reglas:
- Si el número es negativo, lanzar una excepción con throw invalid_argument.
- La función debe llamarse: int contarUnos(int n)
- No se permite convertir el número a string ni usar funciones especiales de biblioteca.
- Solo se pueden usar operaciones matemáticas: %, /, etc.
*/


#include <iostream>
#include <stdexcept>
using namespace std;

int contarUnos(int n){

    if (n < 0 ){

        throw invalid_argument("El numero debe de ser positivo. ");

    }
    if(n == 0) return 0;
    return (n % 2) + contarUnos(n / 2);

}

int main(){

    int numero;

    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = contarUnos(numero);

        cout << "El numero " << numero << " tiene " << resultado << " unos. " << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " <<  e.what() << endl;
    }
    return 0;
    
}