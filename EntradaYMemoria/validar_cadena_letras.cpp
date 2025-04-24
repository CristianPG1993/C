/*
Ejercicio: Validar si una cadena contiene solo letras
Autor: Cristian Paños

Descripción:
Implementar una función en C++ llamada `esSoloLetras(string texto)` que reciba una cadena y devuelva `true` si todos sus caracteres son letras del alfabeto (mayúsculas o minúsculas).  
En caso de encontrar números, espacios o símbolos, debe devolver `false`.

Ejemplos:
- Entrada: "HolaMundo"    → true
- Entrada: "Hola123"      → false
- Entrada: "Hola mundo"   → false
- Entrada: "Clave$123"    → false
*/


#include <iostream>
#include <string>
using namespace std;

bool esSoloLetras(string texto){

    for (char c : texto){

        if (!isalpha(c))
        {
            return false;

        }
        
    }
    return true;

}

int main(){

    string texto;

    cout <<"\nIntroduce un texto: ";
    getline(cin, texto);

    bool valido = esSoloLetras(texto);

    if(valido){

        cout << "El texto (" << texto << ") solo contiene letras. " << endl;

    }else{

        cout << "El texto (" << texto << ") contiene otros caracteres. " << endl;

    }

    return 0;

}