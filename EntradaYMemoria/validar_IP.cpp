/*
🧪 Ejercicio: Validar dirección IP (IPv4)

Crea una función llamada esDireccionIPValida que reciba una cadena
y devuelva true si:

1. Contiene 4 bloques separados por puntos.
2. Cada bloque es un número entre 0 y 255.
3. No contiene letras, espacios ni símbolos extra.

Ejemplos válidos:
- "192.168.0.1"      ✅
- "10.0.0.255"       ✅

Ejemplos no válidos:
- "300.168.1.1"      ❌
- "192.168.1"        ❌
- "192.abc.1.1"      ❌
*/


#include <iostream>
#include <sstream>
using namespace std;

bool esDireccionIPValida(string ip) {
    stringstream ss(ip);   // Creamos un flujo con la IP
    string bloque;
    int contador = 0;

    // Recorremos cada parte separada por '.'
    while (getline(ss, bloque, '.')) {
        // Verificamos que el bloque no esté vacío
        if (bloque.empty()) return false;

        // Verificamos que todos los caracteres sean dígitos
        for (char c : bloque) {
            if (!isdigit(c)) return false;
        }

        // Convertimos el bloque a entero
        int num = stoi(bloque);

        // Verificamos que esté entre 0 y 255
        if (num < 0 || num > 255) return false;

        contador++;  // Contamos el bloque válido
    }

    // Debe haber exactamente 4 bloques
    return (contador == 4);
}


int main(){

    string ip;

    cout << "\nIntroduce una direccion IPv4 (ej: 192.168.1.1): ";
    getline(cin, ip);

    if(esDireccionIPValida(ip)){

        cout << "\nLa direccion " << ip << " es una direccion valida. " << endl;

    }else{

        cout << "\nLa direccion " << ip << " no es una direccion valida. " << endl;

    }

    return 0;

}