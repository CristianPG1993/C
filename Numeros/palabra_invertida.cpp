#include <iostream>
using namespace std;

int main(){
    string palabra;
    string palabra_invertida;


    cout << "Introduce la palabra: ";
    getline(cin, palabra);

    for(int i = palabra.length() - 1; i >= 0; i--){
        palabra_invertida += palabra[i]; // Agregamos la letra a la nueva palabra
    }


    cout << "La palabra invertida es " << palabra_invertida << "." << endl;

    return 0;

}