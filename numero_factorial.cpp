#include <iostream>
using namespace std;

int main(){
    int n;
    long long factorial = 1;

    cout << " introduce un número: ";
    cin >> n;



   if ( n < 0){
        cout << " Error. EL factorial no puede ser negativo. " << endl;
   } else {
    // Calcular el factorial usando un ciclo for
    for (int i = 1; i <= n; i++){
        factorial *= i; // multiplicamos factorial por i en cada iteración
    }
    cout << " El factorial de " << n << " es " << factorial << endl;

   }
   return 0;
}