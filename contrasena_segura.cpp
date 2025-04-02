/*
    Ejercicio: Verificar si una contraseña es segura.

    Requisitos para que la contraseña sea considerada segura:
    1. Debe tener al menos 8 caracteres.
    2. Debe contener al menos una letra mayúscula.
    3. Debe contener al menos un número.

    La función:
    bool es_contrasena_segura(string clave);

    Debe devolver true si cumple todos los requisitos, false si no.

    El programa debe pedir al usuario una contraseña, 
    comprobar si es segura y mostrar un mensaje correspondiente.
*/


#include <iostream>
#include <string>
using namespace std;

bool es_contrasena_segura(string clave) {
    bool longitud_ok = clave.length() >= 8;
    bool tiene_mayuscula = false;
    bool tiene_numero = false;

    // Recorremos la contraseña para verificar número y mayúscula
    for (int i = 0; i < clave.length(); i++) {
        if (isupper(clave[i])) {
            tiene_mayuscula = true;
        }
        if (isdigit(clave[i])) {
            tiene_numero = true;
        }
    }

    // Mostrar mensajes personalizados
    if (!longitud_ok) {
        cout << "❌ La contraseña debe tener al menos 8 caracteres." << endl;
    }
    if (!tiene_mayuscula) {
        cout << "❌ La contraseña debe incluir al menos una letra mayúscula." << endl;
    }
    if (!tiene_numero) {
        cout << "❌ La contraseña debe contener al menos un número." << endl;
    }

    // Solo es segura si todo es verdadero
    return longitud_ok && tiene_mayuscula && tiene_numero;
}


int main(){

    string contrasena_usuario;


    cout << "Introduce la contraseña para verificar su seguridad: ";
    cin >> contrasena_usuario;

    if(es_contrasena_segura(contrasena_usuario)){

        cout << "Tu contraseña es segura. " << endl;

    }else{

        cout << "Tu contraseña no es segura. " << endl;

    }

    return  0;
}

