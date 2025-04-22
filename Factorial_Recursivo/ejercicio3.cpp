#include <iostream>
#include <stdexcept>
using namespace std;

int contarDigitos(int n){

    if (n < 0){

        throw invalid_argument("El numero debe ser un numero positivo.");
    }
    if (n < 10)
        return 1;
    return 1 + contarDigitos(n / 10); 
    
}

int main(){

    int numero;

    cout << "\nIntroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = contarDigitos(numero);

        cout << "\nEl numero " << numero << " tiene " << resultado << " digitos. " << endl;

    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " <<  e.what() << endl;
    }

    return 0;
    
}

