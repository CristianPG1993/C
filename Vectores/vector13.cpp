#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> numeros;

    for (int i = 0; i < 5; i++){
        cout << "Introduce el número " << i + 1 << ":";
        cin >> numeros.push_back(num);
    }



    cout << "Contenido del vector: ";
    for (int i = 0; i < 5; i++){
        cout << numeros[i] << " ";
    }
    cout << endl;

    numeros.resize(7);

    cout << "Vector después de resize(7)";
    for ( int i = 0; i < numeros.size(); i++){
        cout << numeros[i] << " ";
    
    }
    cout << endl;



}