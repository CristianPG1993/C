#include <iostream>
using namespace std;

int main() {
    int numeros[6];

    // ✅ Pedimos los números al usuario
    for (int i = 0; i < 6; i++) {
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    bool repetido = false; // ✅ Variable para saber si encontramos un repetido

    // ✅ Comparar cada número con los demás
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (numeros[i] == numeros[j]) {
                repetido = true;
                break; // ✅ Salimos del segundo `for`
            }
        }
        if (repetido) {
            break; // ✅ Salimos del primer `for`
        }
    }

    // ✅ Mostrar resultado
    if (repetido) {
        cout << "¡Hay un número repetido en el array!" << endl;
    } else {
        cout << "No hay números repetidos en el array." << endl;
    }

    return 0;
}
