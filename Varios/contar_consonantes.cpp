#include <iostream>
using namespace std;

int main() {
    string palabra; // Variable para almacenar la palabra
    int contador_consonantes = 0; // Contador de consonantes

    // Pedir la palabra al usuario
    cout << "Introduce una palabra: ";
    getline(cin, palabra); // Captura toda la línea, incluyendo espacios

    // Recorrer cada letra de la palabra
    for (int i = 0; i < palabra.length(); i++) { 
        char letra = palabra[i]; // Extraemos la letra actual

        // Verificamos si la letra es una consonante
        if (!(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
              letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')) {
            contador_consonantes++; // ✅ Si no es vocal, es consonante
        }
    }

    // Mostrar el resultado
    cout << "La palabra " << palabra << " tiene " << contador_consonantes << " consonantes." << endl;

    return 0; // Fin del programa
}
