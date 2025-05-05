/*
Ejercicio: Verificar si una cadena es alfanumérica
Autor: Cristian Paños

Descripción:
Implementar una función llamada `esAlfanumerica(string texto)` que devuelva `true` si la cadena contiene
 **solo letras o números**, sin espacios ni símbolos especiales.  
Debe devolver `false` si encuentra algún carácter que no sea una letra (`a-z`, `A-Z`) o un dígito (`0-9`).

Ejemplos:
- Entrada: "Hola123"        → true
- Entrada: "123456"         → true
- Entrada: "Hola mundo"     → false
- Entrada: "clave_segura"   → false
*/


#include <iostream>
#include <string>
using namespace std;


bool esAlfanumerica(string texto){


    for (char c : texto){

        if(!isalpha(c) && !isdigit(c)){

            return false;
        }
    }

    return true;


}

int main(){

    string texto;


    cout << "Introduce una cadena: ";
    getline(cin, texto);

    if(esAlfanumerica(texto)){

        cout << "\n " << texto << " es alfanumerica. " << endl;

    }else{

        cout << "\n " << texto << " no es alfanumerica. " << endl;

    }
    return 0;
    
}



