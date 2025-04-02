/*
    🔐 Ejercicio 2: Validar un nombre de usuario

    Descripción:
    Crear una función que verifique si un nombre de usuario es válido
    según los siguientes criterios de seguridad:

    ✅ El nombre debe tener entre 4 y 12 caracteres.
    ✅ Solo debe contener letras y números (sin espacios ni símbolos).
    ✅ No puede estar vacío.

    La función:
    bool usuario_valido(string nombre);

    El programa pedirá al usuario un nombre, y usará la función para
    validar si cumple los requisitos. Mostrará un mensaje indicando 
    si es válido o no, y por qué.
*/


#include <iostream>
#include <string>
using namespace std;

bool usuario_valido(string nombre) {
    bool longitud_ok = nombre.length() >= 4 && nombre.length() < 12;
    bool letras_numeros = true;
    bool usuario_ok = !nombre.empty();  // comprobar que no esté vacío

    for (int i = 0; i < nombre.length(); i++) {
        char letra = nombre[i];

        if (!isalpha(letra) && !isdigit(letra)) {
            letras_numeros = false;
            break;
        }
    }

    if (!usuario_ok) {
        cout << "❌ El nombre de usuario no puede estar vacío." << endl;
    }
    if (!longitud_ok) {
        cout << "❌ El nombre debe tener entre 4 y 12 caracteres." << endl;
    }
    if (!letras_numeros) {
        cout << "❌ El nombre solo puede contener letras y números." << endl;
    }

    return usuario_ok && longitud_ok && letras_numeros;
}


int main(){

    string usuario;

    cout << "Introduce tu nombre de usuario: ";
    cin >> usuario;

    if(usuario_valido(usuario)){

        cout << "El usuario " << usuario << " es válido." << endl;

    }else {

        cout << "El usuario " << usuario << " no es válido. " << endl;

    }

    return 0;
}