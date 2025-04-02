#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(12);

    for (int i = 0; i < 12; i++){

        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros[i];
    }


    int maxima_frecuencia = 0;
    int moda = 0;


    for (int i = 0; i < 12; i++){
        int contador = 0;
        for (int j = 0; j < 12; j++){
            if (numeros[i] == numeros[j]){
                contador++;
            }
        }
        if (contador > maxima_frecuencia){
            maxima_frecuencia = contador;
            moda = numeros[i];
        }
    }

    cout << "El número que más se repite es el " << moda << "y se repite " << maxima_frecuencia << endl;

    return 0;





}