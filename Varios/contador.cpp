#include <iostream>
using namespace std;

int main() {
    int n, contador = 0;

    // Pedir el número al usuario
    cout << "Ingrese un número: ";
    cin >> n;

    // Manejar el caso de número 0
    if (n == 0) {
        contador = 1; // 0 tiene un solo dígito
    } else {
        // Si el número es negativo, lo convertimos a positivo
        if (n < 0) {
            n = -n; // Tomamos su valor absoluto
        }

        // Contar los dígitos usando un ciclo while
        while (n > 0) {
            n = n / 10; // Eliminamos el último dígito
            contador++;  // Aumentamos el contador
        }
    }

    // Mostrar el resultado
    cout << "El número tiene " << contador << " dígitos." << endl;

    return 0;
}
