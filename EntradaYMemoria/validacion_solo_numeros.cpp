/*
Ejercicio: Validar si una cadena contiene solo números
Autor: Cristian Paños

Descripción:
Implementar una función en C++ llamada `esSoloNumeros(string texto)` que reciba una cadena y devuelva `true` si todos sus caracteres son dígitos numéricos (del 0 al 9).
Si encuentra letras, espacios o símbolos, debe devolver `false`.

Ejemplos:
- Entrada: "123456"     → true
- Entrada: "abc123"     → false
- Entrada: "12 34"      → false
- Entrada: "123.45"     → false
*/

#include <iostream>
#include <string>
using namespace std;

bool esSoloNumeros(string texto){

    for (char c : texto){

        if (!isdigit(c))
        {
            
            return false;
        
        }
    }
    return true;

}

int main(){

    string texto;

    cout << "Introduce un cadena de texto solo de numeros: ";
    getline(cin, texto);

    bool valido = esSoloNumeros(texto);

    if (valido)
    {
        cout << "La cadena de texto (" << texto << ") solo contiene numeros. " << endl;

    }else{

        cout << "La cadena de texto (" << texto << ") contiene caracteres no numericos. " << endl;

    }

    return 0;
    
}