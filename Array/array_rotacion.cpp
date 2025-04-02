#include <iostream>
using namespace std;

int main(){
    int numeros[6];

    for (int i = 0; i < 6; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];

    }
    
    cout << " Array original es: ";
    for (int i = 0; i < 6; i++){
        cout << numeros[i] << " ";
    
    }
    cout << endl;

    int ultimo = numeros[5];

    for (int i = 5; i > 0; i--){
        numeros[i] = numeros[i - 1];
    }

    numeros[0] = ultimo;

    cout << "Array rotado: ";
    for (int i = 0; i < 6; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;

}