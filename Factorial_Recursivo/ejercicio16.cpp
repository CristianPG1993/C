#include <iostream>
using namespace std;

int main() {
    char nombre[10];
    int numeroSecreto = 12345;

    cout << "Introduce tu nombre: ";
    cin.get(nombre, 10);

    cout << "Nombre recibido: " << nombre << endl;
    cout << "Valor del numero secreto: " << numeroSecreto << endl;

    return 0;
}
