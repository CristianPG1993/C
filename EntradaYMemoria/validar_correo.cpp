/*
🧪 Ejercicio: Validación básica de correo electrónico

Crea una función llamada esEmailValido que reciba una cadena de texto
y devuelva true si cumple con la estructura básica de un correo electrónico:

1. Contiene exactamente una arroba '@'.
2. Hay al menos un carácter antes de la arroba.
3. Después de la arroba, existe al menos un punto '.'.
4. El punto debe estar ubicado después de la arroba.
5. No debe contener espacios.

Ejemplos válidos:
- "usuario@correo.com"      ✅
- "admin@mail.es"           ✅

Ejemplos no válidos:
- "usuario@@correo.com"     ❌
- "usuario@.com"            ❌
- "usuariocorreo.com"       ❌
- "@dominio.com"            ❌
- "correo @mail.com"        ❌
*/


#include <iostream>
#include <sstream>
using namespace std;

bool esEmailValido(string correo) {
    // 1. Contar la cantidad de arrobas
    int arrobas = 0;
    for (char c : correo) {
        if (c == '@') arrobas++;
    }
    if (arrobas != 1) return false;

    // 2. Verificar que no empieza con '@'
    if (correo[0] == '@') return false;

    // 3. Buscar posición de la arroba
    int posArroba = correo.find('@');

    // 4. Verificar que hay un punto después de la arroba
    int posPunto = correo.find('.', posArroba);
    if (posPunto == string::npos) return false;

    // 5. Verificar que no haya espacios
    for (char c : correo) {
        if (isspace(c)) return false;
    }

    return true;
}

int main(){

    string correo;

    cout << "\nIntroduce un correo valido: ";
    getline(cin, correo);

    if(esEmailValido(correo)){

        cout << "\nEl correo " << correo << " es valido. " << endl;

    }else{

        cout << "\nEl correo " << correo <<  " no es valido. " << endl;

    }

    return 0;
    
}