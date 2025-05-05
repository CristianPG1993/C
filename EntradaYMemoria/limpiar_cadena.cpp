/*
Ejercicio: Limpiar una cadena de símbolos especiales
Autor: Cristian Paños

Descripción:
Implementar una función en C++ llamada `limpiarCadena(string texto)` que reciba 
una cadena de texto y devuelva una nueva cadena que contenga únicamente 
letras y números.  
Todos los símbolos especiales (como signos de puntuación, espacios, 
y otros caracteres que no sean alfanuméricos) deben ser eliminados.

Ejemplos:
- Entrada: "Hola@Mundo!"     → Salida: "HolaMundo"
- Entrada: "123*ABC&xyz"     → Salida: "123ABCxyz"
- Entrada: "clave segura!"   → Salida: "clavesegura"
*/

#include <iostream>
#include <string>
using namespace std;

string limpiarCadena(string texto){

    string cadenaSinSimbolos;

    for (char c : texto){

        if (isalpha(c) || isdigit(c)){

            cadenaSinSimbolos += c;

        }
    }

    return cadenaSinSimbolos;
}

int main(){

    string texto;

    cout << "\nIntroduce una cadena de texto: ";
    getline(cin, texto);

    cout << "La cadena de texto sin quitar los simbolos raros es: " << texto << endl;
    cout << "La cadena de texto limpia es: " << limpiarCadena(texto) << endl;
    return 0;
    
}


