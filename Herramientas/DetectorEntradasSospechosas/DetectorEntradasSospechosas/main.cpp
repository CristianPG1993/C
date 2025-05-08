/*
🛡️ Herramienta: Detector de entradas sospechosas (v1)

Objetivo:
Desarrollar una función llamada `esEntradaPeligrosa(string input)` que evalúe
si una cadena de texto representa una entrada potencialmente maliciosa o peligrosa
para un sistema, consola o base de datos.

Reglas de detección:
1. Rechazar si contiene la palabra "DROP" en cualquier combinación de mayúsculas/minúsculas
2. Rechazar si contiene el símbolo ';'
3. Rechazar si la longitud es mayor a 40 caracteres
4. Rechazar si empieza con un espacio en blanco
5. Rechazar si contiene más de 3 símbolos especiales del conjunto: * ? ! ^ " $

La herramienta debe:
- Pedir una entrada al usuario
- Indicar si la entrada es segura o sospechosa
- Mostrar los motivos si no es válida

Esta herramienta es parte del laboratorio de defensa de entradas en C++
aplicado a ciberseguridad.
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void esEntradaPeligrosa(string input){

    bool contieneDrop = false;

    string copiaInput = input;

    transform(copiaInput.begin(),copiaInput.end(),copiaInput.begin(), ::tolower);
    

    if(copiaInput.find("drop") != string::npos){

        contieneDrop = true;
        cout << "\nLa entrada contiene DROP, podría representar una entrada maliciosa o peligrosa. " << endl;
    }else{

        cout << "\nLa entrada no contiene DROP. " << endl;

    }

    bool contieneSimboloPuntoComa = false;

    if(input.find(";") != string::npos) {

        contieneSimboloPuntoComa = true;

        cout << "\nLa entrada contiene el simbolo ;. Podría representar una entrada maliciosa o peligrosa. " << endl;


    }
    else{
        
        cout << "\nLa entrada no contiene el símbolo ;. " << endl;


    }

    bool mayor40Caracteres = false;

    if(input.length()> 40){

        mayor40Caracteres = true;

        cout << "\nLa entrada es de \"" << input.length() << "\" caracteres. Podría representar una entrada maliciosa o peligrosa. " << endl;

    } else{

        cout << "\nLa entrada tiene menos de 4o caracteres. " << endl;

    }

    bool espacioBlanco = false;

    if (input.length() > 0) {
        if (input[0] == ' ') {
            espacioBlanco = true;
            cout << "\n❌ La entrada comienza con un espacio en blanco. Puede ser sospechosa." << endl;
        } else {
            cout << "\n✅ La entrada no empieza con espacio en blanco." << endl;
        }
    }

    bool tieneMasDe3SimbolosEspeciales = false;

    int contadorSimbolos = 0;
    string especiales = "*?!^\"$";

    for (char c : input){

        if(especiales.find(c) != string::npos){

            contadorSimbolos++;

        }
    }

    if(contadorSimbolos > 3){

        tieneMasDe3SimbolosEspeciales = true;
        cout << "\nLa entrada tiene mas de 3 caracteres especiales. Puede ser una entrada sospechosa. " << endl;

    }else{ 

        cout << "\nLa entrada no contiene más de 3 caracteres especiales. " << endl;

    }

    if (contieneDrop || contieneSimboloPuntoComa || mayor40Caracteres || espacioBlanco || tieneMasDe3SimbolosEspeciales) {
        cout << "\n⚠️ La entrada ha sido marcada como PELIGROSA por los siguientes motivos:\n";
    
        if (contieneDrop)
            cout << "  - Contiene la palabra 'DROP'.\n";
        if (contieneSimboloPuntoComa)
            cout << "  - Contiene el símbolo ';'.\n";
        if (mayor40Caracteres)
            cout << "  - Supera los 40 caracteres.\n";
        if (espacioBlanco)
            cout << "  - Comienza con un espacio en blanco.\n";
        if (tieneMasDe3SimbolosEspeciales)
            cout << "  - Tiene más de 3 símbolos especiales (*?!^\"$).\n";
    
    } else {
        cout << "\n✅ La entrada parece segura.\n";
    }
    

    
}

int main(){

    string input;

    cout << "\nIntroduce un texto: ";
    getline(cin, input);

    esEntradaPeligrosa(input);

    return 0; 


}