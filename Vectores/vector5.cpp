#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(8);
    vector<int> pares;   // Vector para almacenar números pares
    vector<int> impares; // Vector para almacenar números impares

    // Pedir los números
    for (int i = 0; i < 8; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Clasificar en pares o impares
    for (int i = 0; i < 8; i++) {
        if (numeros[i] % 2 == 0) {
            pares.push_back(numeros[i]);  // Si es par, lo agregamos a `pares`
        } else {
            impares.push_back(numeros[i]); // Si es impar, lo agregamos a `impares`
        }
    }

    // Mostrar resultados
    cout << "Números pares: ";
    for (int num : pares) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Números impares: ";
    for (int num : impares) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
