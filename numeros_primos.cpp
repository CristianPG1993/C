#include <iostream>
using namespace std;

int main(){
    int n, contador = 0; // Contador para contar los divisores


    cout << "Introduce un número: ";
    cin >> n;

   // Verificar si el número es primo 
    if( n < 2){
        cout << "El número no es primo (los primos son mayores o iguales a 2)." << endl;
    } else {
        for( int i = 1; i <= n; i++){ // Iteramos desde 1 hasta n
           if( n % i == 0){ // Si n es divisible por i
            contador++; // Aumentamos el contador de dividores
           }
        }


        // Un número primo solo tiene dos divisores: 1 y él mismo
        if( contador == 2) {
            cout << "El número " << n << " es primo. " << endl;
        } else{
            cout << "El número "  << n << " no es primo. " << endl;
            cout << " Tiene " << contador << " divisores. " << endl;
        }
    }

    return 0;

}