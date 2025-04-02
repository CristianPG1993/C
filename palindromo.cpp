#include <iostream>
using namespace std;

int main(){
    string palabra;
    string palabra_invertida;


    cout << "Introduce la palabra: ";
    getline(cin, palabra);

    for(int i = palabra.length() - 1; i >= 0; i--){
        palabra_invertida += palabra[i];
    }

    if( palabra == palabra_invertida ){
        cout << " La palabra " << palabra << " es un palíndromo. " << endl;

    } else{
        cout << " La palabra " << palabra << " no es un palíndromo. " << endl;
    }
    return 0;
}