#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(15);

    for (int i = 0; i < 15; i++){
        cout << "introduce el número " << i + 1 << ":";
        cin >> numeros[i];
    }



    int mayor = 0;
    int posicion = numeros[0];


    for ( int i = 1; i < 15; i++){
        if (numeros[i] > mayor){
            mayor = numeros[i];
            posicion = i;
        }

    }


    cout << "El número más grande es el número: " << mayor << "." << endl;
    cout << "El número " << mayor << " se encuentra en la posición " << posicion << "." << endl;

    return 0;



}