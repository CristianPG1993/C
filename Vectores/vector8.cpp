#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(6);

    for (int i = 0; i < 6; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];
    }


    cout << "Vector original: ";
    for (int i = 0; i < 6; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;


    int ultimo = numeros[5];

    for (int i = 5; i > 0; i--){
        numeros [i] = numeros [i - 1];
    }

    numero[0] = ultimo;

    cout << "Vector rotado: ";
    for (int i = 0; i < 6; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;


    return 0;



}