#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(5);    // Vector para almacenar los números ingresados
    vector<int> invertido;     // Vector para guardar los números en orden inverso

    // Solicitar los números
    for (int i = 0; i < 5; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Llenar el vector invertido
    for (int i = 4; i >= 0; i--) {
        invertido.push_back(numeros[i]);
    }

    // Mostrar el vector original
    cout << "Vector original: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Mostrar el vector invertido
    cout << "Vector invertido: ";
    for (int i = 0; i < invertido.size(); i++) {
        cout << invertido[i] << " ";
    }
    cout << endl;

    return 0;
}
