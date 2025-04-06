#include <iostream>
using namespace std;

int main(){

    int* numeros;

    int cantidad;

    cout << "¿Cuantos números deseas introducir?";
    cin >> cantidad;


    numeros = new int[cantidad];

    for (int i = 0; i < cantidad; i++ ){

        cout << "Introduce el número " << i + 1 << " :";
        cin >> numeros[i];

    }

    int suma = 0;
    
    for (int i = 0; i < cantidad; i++){

        suma += numeros[i];
        
    }


    float media = float(suma) / cantidad;

    delete[] numeros;

    return 0;
    
}