/*
🛡️ Ejercicio: Validar clave con std::string para evitar desbordamientos

Objetivo:
Reescribir el programa de validación de clave, esta vez utilizando
`std::string` en lugar de arrays de caracteres, para eliminar por completo
el riesgo de buffer overflow y simplificar la comparación de cadenas.

Requisitos:
1. Usar `std::string` para almacenar la clave del usuario.
2. Leer la clave con `cin` o `getline()`, sin preocuparte del tamaño.
3. Comparar directamente con la palabra `"secreto"`.
4. Si coincide, establecer `accesoAutorizado = 1`.
5. Mostrar si el acceso fue concedido o denegado, y el valor real
   de la variable `accesoAutorizado`.

Objetivo práctico:
- Evitar el uso de `char[]` y funciones como `strcmp`.
- Trabajar con tipos seguros de alto nivel como `std::string`.
*/


#include <iostream>     // Para entrada/salida estándar
using namespace std;    // Para evitar escribir std:: todo el tiempo

int main() {
    // Declaramos una variable tipo string para la clave introducida por el usuario
    string clave;

    // Variable de control para saber si el acceso debe concederse
    int accesoAutorizado = 0;

    // Pedimos al usuario que introduzca la clave
    cout << "\nIntroduce la clave: ";
    getline(cin, clave);  // Usamos getline para aceptar incluso claves con espacios

    // Comprobamos si la clave introducida es exactamente "secreto"
    if (clave == "secreto") {
        accesoAutorizado = 1;  // Si coincide, activamos el acceso
    }

    // Verificamos el estado de accesoAutorizado para dar respuesta
    if (accesoAutorizado == 1) {
        cout << "\nAcceso autorizado. " << endl;
    } else {
        cout << "\nAcceso denegado. " << endl;
    }

    return 0;  // Fin del programa
}
