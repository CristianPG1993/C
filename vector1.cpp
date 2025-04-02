#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(5); // ✅ Creamos un vector de tamaño 5

    // ✅ Pedir 5 números al usuario
    for(int i = 0; i < 5; i++){
        cout << "Introduce el número " << i + 1 << ": ";
        cin >> numeros[i]; // ✅ Se usa `;` al final
    }

    // ✅ Mostrar los valores ingresados correctamente
    cout << "Los números ingresados son: ";
    for (int i = 0; i < 5; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
