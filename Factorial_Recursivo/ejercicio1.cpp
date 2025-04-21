#include <iostream>
#include <stdexcept> // Para std::invalid_argument
using namespace std;

int factorial(int n) {
    if (n < 0)
        throw invalid_argument("El número no puede ser negativo.");
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int numero;

    cout << "\nIntroduce un número entero: ";
    cin >> numero;

    try {
        int resultado = factorial(numero);
        cout << "El factorial es: " << resultado << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


