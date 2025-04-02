#include <iostream>
using namespace std;


int main(){
    int numeros[8];

    for (int i = 0; i < 8; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];
    }


    int mayor = numeros[0];
    int posicion = 0;

    for (int i = 1; i < 8; i++){
        if(numeros[i] > mayor){
            mayor = numeros[i];
            posicion = i;
        

        }
    }

    cout << "El número más grande es: " << mayor << endl;
    cout << "Se encuentra en la posición: " << posicion << endl;

    return 0;



}