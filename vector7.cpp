#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(7);
    int n;

    // Pedir los números al usuario
    for (int i = 0; i < 7; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Preguntar qué número buscar
    cout << "Número a buscar: ";
    cin >> n;

    // Buscar el número en el vector
    int posicion = -1; // Para marcar si el número no se encuentra
    bool encontrado = false;

    for (int i = 0; i < 7; i++) {
        if (n == numeros[i]) {
            posicion = i;
            encontrado = true;
            break; // Una vez encontrado, salimos del bucle
        }
    }

    // Mostrar el resultado
    if (encontrado) {
        cout << "El número " << n << " se encuentra en la posición: " << posicion << "." << endl;
    } else {
        cout << "El número " << n << " no se encuentra en ninguna posición." << endl;
    }

    return 0;
}
