/*
🛡️ Ejercicio: Protección contra Buffer Overflow con cin.getline()

Objetivo:
Modificar el código vulnerable de login para proteger la memoria
del desbordamiento de búfer.

Requisitos:
1. Crear un array de caracteres de 8 posiciones para almacenar una clave.
2. Leer la clave del usuario utilizando cin.getline() para evitar desbordamientos.
3. Comparar la clave introducida con la palabra "secreta".
4. Si es correcta, cambiar la variable accesoAutorizado a 1.
5. Mostrar si el acceso fue concedido o denegado, y mostrar también
   el valor real de accesoAutorizado para comprobar que no ha sido manipulado.

Objetivo práctico:
- Evitar que el usuario pueda sobrescribir memoria mediante una entrada demasiado larga.
- Comprobar que incluso si el usuario introduce más de 7 caracteres, la variable accesoAutorizado permanece intacta.
*/


#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char clave[8];
    int accesoAutorizado = 0;

    cout << "\nIntroduce la clave: ";
    cin.getline(clave, 8);

    if(strcmp(clave, "secreto") == 0){

        accesoAutorizado = 1;

    }


    cout << "\nEl valor real de la clave es: " << accesoAutorizado << endl;

    if(accesoAutorizado == 1){

        cout << "\nAcceso autorizado. " << endl;

    }else{

        cout << "\nAcceso denegado. " << endl;

    }
    return 0;

}