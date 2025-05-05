/*
🛡️ Ejercicio: Verificador de Cadenas Seguras

Escribe una función llamada esCadenaSegura que reciba una cadena de texto
y devuelva true si cumple todos los siguientes requisitos:

1. Contiene al menos una letra mayúscula.
2. Contiene al menos una letra minúscula.
3. Contiene al menos un número.
4. Contiene al menos un símbolo especial del conjunto: *, ?, !, ^, ", $
5. No contiene espacios en blanco.

Ejemplo:
string cadena = "HolaMundo1!";
Si cumple todos los requisitos, se imprimirá:
"Cadena segura ✅"
En caso contrario:
"Cadena insegura ❌"
*/


#include <iostream>
#include <string>
using namespace std;

bool esCadenaSegura(string texto) {
    // 1. Verificar si tiene al menos una letra mayúscula
    bool tieneMayuscula = false;
    for (char c : texto) {
        if (isupper(c)) {
            tieneMayuscula = true;
            break;
        }
    }

    // 2. Verificar si tiene al menos una letra minúscula
    bool tieneMinuscula = false;
    for (char c : texto) {
        if (islower(c)) {
            tieneMinuscula = true;
            break;
        }
    }

    // 3. Verificar si tiene al menos un número
    bool tieneNumero = false;
    for (char c : texto) {
        if (isdigit(c)) {
            tieneNumero = true;
            break;
        }
    }

    // 4. Verificar si tiene al menos un símbolo especial permitido
    bool tieneSimbolosEspeciales = false;
    string especiales = "*?!^\"$"; // lista exacta de símbolos permitidos
    for (char c : texto) {
        if (especiales.find(c) != string::npos) {
            tieneSimbolosEspeciales = true;
            break;
        }
    }

    // 5. Verificar que no tenga espacios en blanco
    bool tieneEspacios = false;
    for (char c : texto) {
        if (isspace(c)) {
            tieneEspacios = true;
            break;
        }
    }

    // Devolver true solo si se cumplen todas las condiciones
    return tieneMayuscula && tieneMinuscula && tieneNumero && tieneSimbolosEspeciales && !tieneEspacios;
}

int main() {
    string texto;

    cout << "\nIntroduce la cadena: ";
    getline(cin, texto); // Leer toda la línea, incluyendo espacios si los hay

    // Llamamos a la función con la cadena introducida
    if (esCadenaSegura(texto)) {
        cout << "La cadena \"" << texto << "\" es segura. ✅" << endl;
    } else {
        cout << "La cadena \"" << texto << "\" no es segura. ❌" << endl;
    }

    return 0;
}