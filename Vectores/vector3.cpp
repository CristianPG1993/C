#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> numeros(7);

    for (int i = 0; i < 7; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];
    }


    int mayor = numeros[0];
    int menor = numeros[0];


    for ( int i = 1; i < 7; i++){
        if (numeros[i] > mayor){
            mayor = numeros[i];
        }

        if (numeros[i] < menor ){
            menor = numeros[i];
        }
    }


    cout << "El número mayor es: " << mayor << "." << endl;
    cout << "El número menor es: " << menor << "." << endl;

    return 0;


}