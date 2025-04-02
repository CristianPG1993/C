#include <iostream>
using namespace std;

int main() {
    int numeros[5];


    for (int i = 0; i < 5; i++){
        cout << "Introduce un número: ";
        cin >> numeros[i];
    }


    cout << "Array en orden normal: ";
    for (int i = 0; i < 5; i++){
        cout << numeros[i] << ".";
    }
    cout << endl;


    cout << "Array en orden inverso: ";
    for (int i = 4; i >= 0; i--){
        cout << numeros[i] << "."; 
    }
    cout << endl;

    return 0;



}