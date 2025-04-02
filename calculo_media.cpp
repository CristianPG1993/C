#include <iostream>
using namespace std;


int main(){
    double numero, suma = 0; // suma almacena suma total
    int contador = 0; // cuenta cuantos numeros positivos ingresó el usuario

    cout << " Ingrese número positivos( ingrese un número negativo para terminar): " << endl;

    while (true) 
    {
        cout << "Número :";
        cin >> numero;

        if (numero < 0) { // Si el número es negativo, salir del bucle
            break;
        }

        suma += numero; // sumamos el número ingresado
        contador++; // Aumentamos el contador e números ingresados
    
    }

    // Verificamos si se ingresaron número antes de calcular la media
    if (contador > 0){
        double media = suma / contador; // Calculamos la media
        cout << " La media de los números ingresados es: " << media << endl;
    } else {
        cout << " No ingresaste ningún número positivo." << endl;

    }

    return 0;
    
}