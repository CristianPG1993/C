#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> numeros(9);


    for (int i = 0; i < 9; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];

    }


    cout << "El vector original es: ";
    for (int i = 0; i < 9; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++){
            if (numeros[j] > numeros[j + 1]){
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;

            }
        }
    }


    cout << "El vector ordenado es: ";
    for (int i = 0; i < 9; i++){
        cout << numeros[i] << " ";

    }
    cout << endl;


    double mediana;
    if (numeros.size() % 2 == 0){
        // Número par
        mediana = (numeros[(numeros.size) / 2 - 1] + numeros[(numeros.size / 2)] / 2.0);
    }else{
        // Numero impar
        mediana = numeros[numeros.size() / 2];
    }


    cout << "La mediana es: " << mediana << endl;

    return 0;



}