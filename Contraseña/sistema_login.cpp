/*
Ejercicio 3: Sistema de Login (versión básica)

Descripción:
Crea un programa en C++ que simule un sistema de login sencillo con los siguientes requisitos:

1. Almacenar hasta 5 usuarios con nombre de usuario y contraseña.
2. Permitir al usuario introducir su nombre de usuario y contraseña para iniciar sesión.
3. Verificar si las credenciales son correctas.
4. Utilizar una estructura `Usuario` con dos campos: nombre y contraseña.
5. Usar funciones para dividir el código:
   - Una función para comprobar si el login es correcto.
   - Una función para mostrar el resultado del intento de login.
6. Usar arrays y punteros para practicar el acceso a datos.

Objetivo:
Practicar el uso de estructuras, arrays de estructuras, funciones con paso de parámetros por puntero, y 
comparación de cadenas en un contexto sencillo de ciberseguridad.
*/

#include <iostream>
#include <string>
using namespace std;



struct Usuario{

    string nombre;
    string contrasena;

};

int main(){

    Usuario usuarios[3] = {
        {"admin", "admin123"},
        {"user1", "clave1"},
        {"user2", "clave2"},
    };


    string nombre_ingresado;
    string contrasena_ingresada;


    cout << "Introduce el usuario: " << endl;
    cin >> nombre_ingresado;

    cout << "introduce la contraseña: " << endl;
    cin >> contrasena_ingresada;

    bool loginCorrecto = false;

    for (int i = 0; i < 3; i++){

        if(usuarios[i].nombre == nombre_ingresado && usuarios[i].contrasena == contrasena_ingresada ){

            cout << "Login existoso." << endl;
            loginCorrecto = true;
            break;
    }
    }

    
    if(!loginCorrecto){

        cout << "Login incorrecto." << endl;

    }
    return 0;

    
}

