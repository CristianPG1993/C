#include <iostream>
#include <string>
using namespace std;

const string CONTRASENA_CORRECTA = "admin123";

// Función que compara la contraseña introducida con la correcta
bool verificar_contrasena(string entrada) {
    return entrada == CONTRASENA_CORRECTA;
}

int main() {
    string entrada_usuario;
    int intentos = 0;
    const int LIMITE_INTENTOS = 3;

    while (intentos < LIMITE_INTENTOS) {
        cout << "Introduce la contraseña: ";
        cin >> entrada_usuario;  // Simulación de entrada (no oculta)

        if (verificar_contrasena(entrada_usuario)) {
            cout << "✅ Acceso concedido." << endl;
            return 0;
        } else {
            intentos++;
            cout << "❌ Contraseña incorrecta. Intento " << intentos << " de " << LIMITE_INTENTOS << "." << endl;
        }
    }

    cout << "🚫 Cuenta bloqueada por demasiados intentos fallidos." << endl;
    return 0;
}
