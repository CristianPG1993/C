/*
🛡️ Herramienta: Validador de Rutas Peligrosas (v1)

Objetivo:
Detectar si una cadena de texto que representa una ruta de sistema o comando
es potencialmente peligrosa. Esta herramienta forma parte del laboratorio
de análisis de entradas inseguras en C++ aplicado a ciberseguridad.

Reglas de validación:
1. ❌ Intenta acceder directamente al directorio raíz ("/" o "C:\")
2. ❌ Contiene patrones de traversal como "../" o "..\"
3. ❌ Hace referencia a carpetas críticas como: etc, bin, system32 (sin importar mayúsculas)
4. ❌ Usa comillas escapadas como \" o \'
5. ❌ Empieza con doble barra: "//" o "\\" (sospechoso en scripts o rutas UNC)

Requisitos:
- Leer la ruta como una cadena con `getline`
- Mostrar qué patrones peligrosos se han encontrado
- Marcar como peligrosa o segura con detalle

Ejemplo de entrada:
    ../../etc/passwd   → debe marcarse como peligrosa

*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void cadenaPotencialmentePeligrosa(string input) {
    bool intentoAccesoDirectorioRaiz = false;
    string copiaInput = input;

    transform(copiaInput.begin(), copiaInput.end(), copiaInput.begin(), ::tolower);

    if (input.length() > 0) {
        if (input[0] == '/') {
            intentoAccesoDirectorioRaiz = true;
            cout << "\n❌ La entrada es potencialmente peligrosa porque empieza por '/' (directorio raíz Unix)." << endl;
        } else if (copiaInput.substr(0, 3) == "c:\\") {
            intentoAccesoDirectorioRaiz = true;
            cout << "\n❌ La entrada es potencialmente peligrosa porque empieza por 'C:\\' (directorio raíz Windows)." << endl;
        } else {
            cout << "\n✅ La entrada no empieza por un directorio raíz." << endl;
        }
    }

    bool patronesTransversales = false;

    if (input.find("../") != string::npos || input.find("..\\") != string::npos){

        patronesTransversales = true;
        cout << "\nLa entrada es potencialmente peligrosa porque contiene '../' o '..\\'. " << endl; 
    }else{

        cout << "\nLa entrada no contiene '../' o '..\\'. " << endl;
    }

    bool contieneDirectoriosCriticos = false;

    if(copiaInput.find("etc") !=string::npos || copiaInput.find("bin") !=string::npos || copiaInput.find("system32") != string::npos){

        contieneDirectoriosCriticos = true;
        cout << "\nLa entrada contiene algún directorio critico. " << endl;

    }else{

        cout << "\nLa entrada no contiene referencia a ningún directorio critico. " << endl;
    }

    bool comillasEscapadas = false;

    if(copiaInput.find("\\\"") != string::npos || copiaInput.find("\\'") != string::npos){

        comillasEscapadas = true;
        cout << "\nLa entrada contiene comillas escapadas. " << endl;

    }else{

        cout << "\nLa entrada no contiene comillas escapadas. " << endl;

    }

    bool empiezaConDobleBarra = false;

    if (copiaInput.length() >= 2) {
        string inicio = copiaInput.substr(0, 2);

        if (inicio == "//" || inicio == "\\\\") {
            empiezaConDobleBarra = true;
            cout << "\n❌ La entrada empieza con doble barra '//' o '\\\\'. Puede indicar intento de evasión o ruta UNC." << endl;
        } else {
            cout << "\n✅ La entrada no empieza con doble barra." << endl;
        }
    }


    if (intentoAccesoDirectorioRaiz || patronesTransversales || contieneDirectoriosCriticos || comillasEscapadas || empiezaConDobleBarra) {

        cout << "\n⚠️ La entrada de texto contiene elementos potencialmente maliciosos. Detalles:" << endl;
    
        if (intentoAccesoDirectorioRaiz) {
            cout << " - Intenta acceder directamente al directorio raíz." << endl;
        }
        if (patronesTransversales) {
            cout << " - Contiene patrones de traversal (../ o ..\\)." << endl;
        }
        if (contieneDirectoriosCriticos) {
            cout << " - Hace referencia a directorios críticos como etc, bin o system32." << endl;
        }
        if (comillasEscapadas) {
            cout << " - Contiene comillas escapadas (\\\" o \\\')." << endl;
        }
        if (empiezaConDobleBarra) {
            cout << " - Empieza con doble barra (// o \\\\)." << endl;
        }
    
    } else {
        cout << "\n✅ La entrada parece segura." << endl;
    }
    

}

int main(){

    string input;

    cout << "\nIntroduce una cadena de texto: ";
    getline(cin, input);

    cadenaPotencialmentePeligrosa(input);

    return 0;
}