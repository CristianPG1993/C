#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(8);
    vector<int> pares;
    vector<int> impares;


    for (int i = 0; i < 8; i++){
        cout << "Introduce el número" << i + 1 << ":";
        cin >> numeros[i];
    }


    int par = 0;
    int impar = 0;


    for (int i = 0; i < 8; i++){
        if ( numeros[i] % 2 == 0 ){
            par++;
        } else {
            impar++;
        }
    }


    cout << "Cantidad de números pares: " << par << "." << endl;
    cout << "Cantidad de números impares: " << impar << "." << endl;

    return 0;




}