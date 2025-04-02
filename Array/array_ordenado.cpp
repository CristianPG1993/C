#include <iostream>
using namespace std;

int main() {
    int numeros[7];

    // ✅ Pedir los números al usuario
    for (int i = 0; i < 7; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // ✅ Verificar si el array está ordenado
    bool ordenado = true; // ✅ Asumimos que está ordenado

    for (int i = 0; i < 6; i++) { // ✅ Recorremos hasta el penúltimo elemento
        if (numeros[i] > numeros[i + 1]) { // Si encontramos un desorden...
            ordenado = false;
            break; // ✅ Salimos del `for` ya que no necesitamos seguir revisando
        }
    }

    // ✅ Imprimir resultado final
    if (ordenado) {
        cout << "El array está ordenado de menor a mayor." << endl;
    } else {
        cout << "El array no está ordenado de menor a mayor." << endl;
    }

    return 0;
}
