/*
🧪 Ejercicio: Verificación de cadena alfanumérica

Crea una función llamada esAlfanumerica que reciba una cadena de texto
y devuelva true si cumple todos los siguientes requisitos:

1. Contiene solo letras (mayúsculas o minúsculas) y números.
2. No contiene espacios, ni símbolos, ni caracteres especiales.

Ejemplos válidos:
- "Usuario123"    ✅
- "holaMundo7"    ✅

Ejemplos no válidos:
- "usuario!"      ❌
- "mi clave"      ❌
- "clave$123"     ❌
*/


#include <iostream>
#include <string>
using namespace std;

bool esAlfanumerica(string texto){


    for (char c : texto){

        if(!isalnum(c)){

            return false;

        }
    }
    return true;

}

int main(){

    string texto;

    cout <<"\nIntroduce el texto: ";
    getline(cin, texto);

    if(esAlfanumerica(texto)){

        cout << texto << " es una cadena alfanumerica. " << endl;

    }else{

        cout << texto << " no es una cadena alfanumerica. " << endl;

    }

    return 0;
    
}