#include <iostream>
using namespace std;

int main() {
    string palabra; // Variable para almacenar la palabra
    int contador_vocales = 0; // Contador de vocales

    // Pedir la palabra al usuario
    cout << "Introduce una palabra: ";
    cin.ignore(); // Evita problemas si antes se usó 'cin'
    getline(cin, palabra); // Permite capturar palabras con espacios

    // Recorrer cada letra de la palabra
    for (int i = 0; i < palabra.length(); i++) {
        char letra = palabra[i]; // Extraemos la letra actual

        // Verificamos si la letra es una vocal (mayúsculas y minúsculas)
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            contador_vocales++; // Aumentamos el contador si es vocal
        }
    }

    // Mostrar el resultado
    cout << "La palabra " << palabra << " tiene " << contador_vocales << " vocales." << endl;

    return 0; // Fin del programa
}
