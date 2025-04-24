/*
Ejercicio: Contar cuántas letras mayúsculas contiene una cadena
Autor: Cristian Paños

Descripción:
Implementar una función en C++ llamada `contarMayusculas(string texto)` 
que reciba una cadena de texto y devuelva un número entero (`int`) indicando 
cuántos caracteres del texto son letras mayúsculas (A–Z).

Ejemplos:
- Entrada: "Hola Mundo"         → 2
- Entrada: "CRISTIAN"           → 8
- Entrada: "código limpio"      → 0
- Entrada: "Ya Me Voy"          → 3
*/

#include <iostream>
#include <string>
using namespace std;

int contarMayusculas(string texto){

    int contadorMayusculas = 0;

    for (char c : texto){

        if(isupper(c)){

            contadorMayusculas++;

        }
    }

    return contadorMayusculas;

}

int main(){

    string texto;

    cout << "\nIntroduce una cadena de texto: ";
    getline(cin, texto);

    cout << texto << " tiene " << contarMayusculas(texto) << " mayusculas. " << endl;

    return 0;


}