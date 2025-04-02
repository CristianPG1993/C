#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros = {10, 20, 30, 40, 50};

    cout << "El segundo número es: " << numeros.at(1) << "." << endl;
    cout << "El cuarto número es: " << numeros.at(3) << "." << endl;



    numeros.clear();

    cout << "El tamaño del vector después de clear() es: " << numeros.size() << endl;

    return 0;
   

}


