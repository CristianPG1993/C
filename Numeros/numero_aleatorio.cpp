#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0)); // Inicializar semilla para números aleatorios
    int numero_secreto = rand() % 10 + 1; // Generar número aleatorio entre 1 y 10
    int intento;
    cout << " Adivina el número secreto entre 1 y 10: ";
    
    //Bucle hasta que el usuario adivine
    while (true) {
        cin >> intento;

        if (intento < numero_secreto) {
            cout << "🔻 Demasiado bajo. Inténtalo de nuevo: ";
        } else if (intento > numero_secreto) {
            cout << "🔺 Demasiado alto. Inténtalo de nuevo: ";
        } else {
            cout << "🎉 ¡Felicidades! Has adivinado el número." << endl;
            break; // Sale del bucle
        }
    }

    return 0;
}