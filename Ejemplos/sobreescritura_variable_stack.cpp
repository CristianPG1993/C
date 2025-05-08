#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char clave[8];                    // Buffer vulnerable
    int accesoAutorizado = 0;        // Variable a pisar

    cout << "Dirección de clave: " << static_cast<void*>(clave) << endl;
    cout << "Dirección de accesoAutorizado: " << &accesoAutorizado << endl;
    cout << "Valor inicial accesoAutorizado: " << accesoAutorizado << endl;
    

    // Escribimos 12 bytes manualmente en clave
    // Los 4 últimos sobrescriben accesoAutorizado
    // '\x01\x00\x00\x00' corresponde a int 1 (little endian)
    strcpy(clave, "aaaaaaaa\x01\x00\x00\x00");  // 💣 desbordamiento forzado

    cout << "Valor después accesoAutorizado: " << accesoAutorizado << endl;

    if (accesoAutorizado == 1) {
        cout << "✅ Acceso concedido sin contraseña válida (simulación de exploit)." << endl;
    } else {
        cout << "❌ Acceso denegado." << endl;
    }

    return 0;
}
