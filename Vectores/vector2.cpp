#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros(6);
    int suma = 0;


    for (int i = 0; i < 6; i++){
    cout << "Introduce el número " << i + 1 << ":";
    cin >> numeros[i];
    suma += numeros[i];
    }

    double promedio = suma / static_cast<double>(numeros.size());


    cout << "El promedio de los números ingresados es: " << promedio << endl;
    

    return 0;



}