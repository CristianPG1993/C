#include <iostream>
using namespace std;

int main(){
    int numeros[6];


    for (int i = 0; i < 6; i++){
        cout << "Introduce los números: ";
        cin >> numeros[i];
    }


    int suma_par = 0;
    int suma_impar = 0;

 
    for (int i = 0; i < 6; i++){
        if (numeros[i] % 2 == 0){
            suma_par++;    
        } else {
            suma_impar++;
        }


    }

    cout << "Cantidad de números pares: " << suma_par << endl;
    cout << "Cantidad de números impares: " << suma_impar << endl;


    return 0;
}