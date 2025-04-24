/*
Autor: Cristian Paños
Ejercicio: Validador de contraseñas seguras
Descripción:
Implementar un programa en C++ que valide si una contraseña cumple con los requisitos mínimos de seguridad.

Requisitos que debe cumplir la contraseña:
1. Tener al menos 8 caracteres de longitud.
2. Contener al menos una letra mayúscula.
3. Contener al menos una letra minúscula.
4. Contener al menos un número.
5. Contener al menos un símbolo especial (*, ?, !, ^, ", $).
6. No debe contener la palabra "GIT" en ningún formato (ni "git", "Git", etc).

Objetivo:
Crear una función bool esContrasenaValida(string password) que devuelva true si cumple todas las condiciones y false si falla al menos una. 
En caso de fallo, el programa debe indicar al usuario qué condición no se cumple.
*/


#include <iostream>      // Librería para entrada y salida estándar
#include <string>        // Librería para trabajar con strings (cadenas de texto)
#include <algorithm>     // Librería que contiene transform (para cambiar a minúsculas)
using namespace std;

// Función que valida si la contraseña cumple con los requisitos de seguridad
bool esContrasenaValida(string password) {

    // Validación 1: longitud mínima
    bool esMayor8Caracteres = false;
    if (password.length() >= 8) {
        esMayor8Caracteres = true;
        cout << "✅ La contraseña tiene al menos 8 caracteres." << endl;
    } else {
        cout << "❌ La contraseña tiene menos de 8 caracteres." << endl;
    }

    // Validación 2: contiene al menos una letra mayúscula
    bool tieneMayuscula = false;
    for (char c : password) {
        if (isupper(c)) {
            tieneMayuscula = true;
            break;  // Salimos del bucle si ya encontramos una
        }
    }
    if (tieneMayuscula) {
        cout << "✅ La contraseña contiene al menos una letra mayúscula." << endl;
    } else {
        cout << "❌ La contraseña no contiene ninguna letra mayúscula." << endl;
    }

    // Validación 3: contiene al menos una letra minúscula
    bool tieneMinuscula = false;
    for (char c : password) {
        if (islower(c)) {
            tieneMinuscula = true;
            break;
        }
    }
    if (tieneMinuscula) {
        cout << "✅ La contraseña contiene al menos una letra minúscula." << endl;
    } else {
        cout << "❌ La contraseña no contiene ninguna letra minúscula." << endl;
    }

    // Validación 4: contiene al menos un número
    bool tieneNumero = false;
    for (char c : password) {
        if (isdigit(c)) {
            tieneNumero = true;
            break;
        }
    }
    if (tieneNumero) {
        cout << "✅ La contraseña contiene al menos un número." << endl;
    } else {
        cout << "❌ La contraseña no contiene ningún número." << endl;
    }

    // Validación 5: contiene al menos un símbolo especial
    bool tieneSimboloEspecial = false;
    string especiales = "*?!^\"$";
    for (char c : password) {
        if (especiales.find(c) != string::npos) {
            tieneSimboloEspecial = true;
            break;
        }
    }
    if (tieneSimboloEspecial) {
        cout << "✅ La contraseña contiene al menos un símbolo especial (*?!^\"$)." << endl;
    } else {
        cout << "❌ La contraseña no contiene ningún símbolo especial." << endl;
    }

    // Validación 6: no debe contener la palabra 'git' (en ninguna combinación de mayúsculas)
    bool noTieneGit = false;
    string copia = password;
    transform(copia.begin(), copia.end(), copia.begin(), ::tolower);  // Convertimos toda la contraseña a minúsculas
    if (copia.find("git") == string::npos) {
        noTieneGit = true;
        cout << "✅ La contraseña no contiene la palabra prohibida 'git'." << endl;
    } else {
        cout << "❌ La contraseña contiene la palabra prohibida 'git'." << endl;
    }

    // Resultado final: solo si todas las condiciones se cumplen, devuelve true
    return esMayor8Caracteres &&
           tieneMayuscula &&
           tieneMinuscula &&
           tieneNumero &&
           tieneSimboloEspecial &&
           noTieneGit;
}

// Función principal: pide la contraseña y llama al validador
int main() {
    string password;

    cout << "\nIntroduce la contraseña: ";
    getline(cin, password);  // Usamos getline para permitir espacios

    bool valida = esContrasenaValida(password);  // Validamos la contraseña

    // Mostramos resultado final
    if (valida) {
        cout << "✅ La contraseña \"" << password << "\" es válida." << endl;
    } else {
        cout << "❌ La contraseña \"" << password << "\" no es válida." << endl;
    }

    return 0;
}
