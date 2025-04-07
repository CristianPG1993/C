/*
    EJERCICIO: Sistema de gestión de usuarios (login) con memoria dinámica

    Descripción:
    Crea un programa que permita registrar varios usuarios, almacenando su nombre de usuario y contraseña.

    El usuario debe poder:
    - Indicar cuántos usuarios desea registrar.
    - Introducir un nombre de usuario y una contraseña por cada uno.

    El programa debe:
    - Guardar la información usando memoria dinámica.
    - Preguntar por un nombre de usuario y contraseña, y verificar si coinciden con los registrados.
    - Mostrar un mensaje de acceso concedido o denegado.

    Requisitos técnicos:
    - Uso de estructuras (`struct`)
    - Uso de `new` y `delete[]` para arrays dinámicos
    - Comparación de strings
    - Entrada dinámica del usuario

    Objetivo:
    Reforzar el uso de memoria dinámica aplicada a la autenticación de usuarios.
*/


#include <iostream>
using namespace std;

struct Usuario{

    string nombre;
    string password;

};

int main(){

    int cantidadUsuarios;

    Usuario* lista;

    cout << "¿Cuantos usuarios desea registrar?";
    cin >> cantidadUsuarios;

    lista = new Usuario[cantidadUsuarios];

    for (int i = 0; i < cantidadUsuarios; i++){

        cout << "Introduce el nombre " << i + 1 << " :";
        cin >> lista[i].nombre;

        cout << "Introduce el password del usuario " << i + 1 << " :";
        cin >> lista[i].password;

    }

    string nombreUsuario;
    string passwordUsuario;

    cout << "Escribe tu usuario: ";
    cin >> nombreUsuario;

    cout << "Introduce tu password: ";
    cin >> passwordUsuario;

    bool accesoConcecido = false;

    
    for (int i = 0; i < cantidadUsuarios; i++){

        if(nombreUsuario == lista[i].nombre && passwordUsuario == lista[i].password){

            accesoConcecido = true;
            break;

        }
    }

    if(accesoConcecido){

        cout << "Acceso concecido. " << endl;

    }else {
        cout << "El usuario o la contraseña no coinciden. " << endl;

    }

    delete [] lista;
    return 0;

}