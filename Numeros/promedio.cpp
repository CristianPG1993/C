#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    int suma = 0;


    for (int i = 0; i < 5 ; i++) {
        cout << "Introduce un número: ";
        cin >> numeros[i];
    }

    for (int i = 0; i < 5; i++) {
        suma += numeros[i];
    }

    float promedio = suma / 5.0;

    cout << "El número promedio es: " << promedio << endl;

    int mayor = numeros[0];
    int menor = numeros[0];


    for (int i = 1; i < 5; i++) {
        if (numeros[i]> mayor){
            mayor = numeros[i];
        }
        if (numeros[i] < menor){
            menor = numeros[i];
        }
    }

    cout << "El número más grande es: " << mayor << endl;
    cout << "El número más pequeño es: " << menor << endl;
    

    return 0;
}