#include <iostream>
#include <stdexcept>
using namespace std;

int sumaHasta(int n){

    if (n < 0)
    {
        throw invalid_argument("El numero no puede ser negativo.");
    }
    if(n == 0) 
        return 0;
    return n  + sumaHasta(n - 1);

}

int main(){

    int numero;

    cout <<"\nintroduce un numero positivo: ";
    cin >> numero;

    try
    {
        int resultado = sumaHasta(numero);

        cout << "La suma desde 1 hasta " << numero << " es: " << resultado << endl;
    }
    catch(const invalid_argument& e)
    {
        cout << "Error: " <<  e.what() << endl;

    }
    
    return 0;
}