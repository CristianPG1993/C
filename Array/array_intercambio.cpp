#include <iostream>
using namespace std;

int main() {
    int numeros[6];

    // ✅ Pedir los números al usuario
    for (int i = 0; i < 6; i++){
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // ✅ Mostrar el array original
    cout << "Array con valores normales: " << endl;
    for (int i = 0; i < 6; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;

    // ✅ Encontrar el número más grande y el más pequeño
    int mayor = numeros[0];
    int menor = numeros[0];
    int posicion_mayor = 0;
    int posicion_menor = 0;

    for (int i = 1; i < 6; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
            posicion_mayor = i;
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
            posicion_menor = i;
        }
    }

    // ✅ Intercambiar los valores
    int temp = numeros[posicion_mayor];
    numeros[posicion_mayor] = numeros[posicion_menor];
    numeros[posicion_menor] = temp;

    // ✅ Mostrar el array modificado
    cout << "Array con valores modificados: " << endl;
    for (int i = 0; i < 6; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
