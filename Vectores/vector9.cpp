#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(10);

    // Pedir los números al usuario
    for (int i = 0; i < 10; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Mostrar el vector original
    cout << "Vector original: ";
    for (int i = 0; i < 10; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    // Ordenar el vector en orden ascendente usando burbuja
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) { // Va hasta 9 porque compara j con j+1
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    // Mostrar el vector ordenado
    cout << "Vector ordenado: ";
    for (int i = 0; i < 10; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
