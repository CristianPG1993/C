/*
Ejercicio: Detectar si una cadena contiene símbolos especiales
Autor: Cristian Paños

Descripción:
Implementar una función en C++ llamada `contieneSimbolosEspeciales(string texto)` 
que devuelva `true` si la cadena contiene al menos un símbolo especial 
(es decir, caracteres que **no son letras ni números**).  
Si todos los caracteres son letras o dígitos, debe devolver `false`.

Ejemplos:
- Entrada: "HolaMundo123"       → false
- Entrada: "Hola_Mundo"         → true (guion bajo)
- Entrada: "clave!segura"       → true (exclamación)
- Entrada: "Texto limpio"       → true (espacio)
*/



#include <iostream>
#include <string>
using namespace std;

bool contieneSimbolosRaros(string texto){



    for (char c : texto){

        if(!isdigit(c) && !isalpha(c)){

            return true;

        }
    }
    return false;

}

int main(){

    string texto;

    cout << "\nIntroduce una cadena de texto: ";
    getline(cin, texto);

    bool valido = contieneSimbolosRaros(texto);

    if (valido){

        cout << "La cadena de texto (" << texto <<") contiene simbolos raros. " << endl;

    }else{

        cout << "La cadena de texto (" << texto <<") no contiene simbolos raros. " << endl;
    }

    return 0;
}