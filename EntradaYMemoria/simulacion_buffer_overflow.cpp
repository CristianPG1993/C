/*
🧪 Ejercicio: Simulación de buffer overflow

Crea un programa que tenga dos variables:

1. Un array de caracteres de 8 posiciones para almacenar una clave: `char clave[8];`
2. Un entero llamado `accesoAutorizado` inicializado en 0

El programa debe:
- Pedir al usuario una clave
- Almacenar la entrada en `clave` usando `cin >>`
- Si la clave introducida es "secreta", cambiar `accesoAutorizado` a 1
- Mostrar si el acceso ha sido concedido o denegado según el valor de `accesoAutorizado`

🔐 ¿Dónde está el fallo?
- Si introduces más de 8 caracteres, puedes sobreescribir la variable `accesoAutorizado`

Objetivo: Comprueba cómo escribir más de 8 caracteres cambia el valor de `accesoAutorizado`, 
incluso sin introducir la clave correcta.
*/


#include <iostream>
#include <cstring>
using namespace std;


int main(){

    char clave[8];
    int accesoAutorizado = 0;

    cout << "\nIntroduce la clave: ";
    cin >> clave;

    // Comparación correcta del contenido de la clave
    if (strcmp(clave, "secreta") == 0) {
        accesoAutorizado = 1;
    }

    // Mostrar el valor real
    cout << "\nValor real de accesoAutorizado: " << accesoAutorizado << endl;

    if(accesoAutorizado == 1){

        cout << "Acceso concedido. " << endl;

    }else { 
        cout << "Acceso denegado. " << endl;

    }
    return 0;
    
}