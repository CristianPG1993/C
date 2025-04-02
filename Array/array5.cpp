#include <iostream>
using namespace std;

int main(){
    int numeros[5]{};


    for( int i = 0; i < 5; i++){
        cout << " Introduce un número: ";
        cin >> numeros[i];
         
    }

    for (int i = 0; i < 5; i++) {  
    cout << "El número en la posición " << i << " es: " << numeros[i] << endl;
    }

    return 0;

    
}





