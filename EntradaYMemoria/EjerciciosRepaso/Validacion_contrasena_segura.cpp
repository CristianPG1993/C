/*
🧪 Ejercicio: Validador de contraseña segura con restricción de inicio y fin

Objetivo:
Ampliar la validación de contraseñas seguras con una nueva regla:
la contraseña no puede comenzar ni terminar con un número.

Requisitos que debe cumplir la función esContrasenaSegura:
1. Al menos 8 caracteres
2. Al menos una letra mayúscula
3. Al menos una letra minúscula
4. Al menos un número
5. Al menos un símbolo especial (* ? ! ^ " $)
6. No debe contener espacios
7. No debe contener la palabra "GIT" (en ningún formato, mayúsculas o minúsculas)
8. ❌ No debe comenzar con un número
9. ❌ No debe terminar con un número

Ejemplos válidos:
- Clave1$ok         ✅
- $MiClaveSegura1   ✅

Ejemplos inválidos:
- 1ClaveSegura!     ❌ (empieza con número)
- ClaveSegura9      ❌ (termina con número)
- gitClave9!        ❌ (contiene “git”)
- Clave 123!        ❌ (tiene espacio)
*/



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool esContrasenaSegura(string contrasena){

    //1. Tiene al menos 8 caracteres de longitud 

    bool mayorQue8 = false;

    if(contrasena.length() >= 8){

        mayorQue8 = true;

    }

    // 2. Contiene al menos una letra mayúscula (A-Z)

    bool contieneMayuscula = false;

    for (char c : contrasena){

        if(isupper(c)){

            contieneMayuscula = true;
            break;

        }
    }

    // 3. Contiene al menos una letra minúscula (a-z)

    bool contieneMinuscula = false;

    for (char c : contrasena){

        if (islower(c))
        {
            contieneMinuscula = true;
            break;
        }
        
    }

    // 4. Contiene al menos un número (0-9)

    bool tieneNumero = false;

    for (char c : contrasena){

        if(isdigit(c)){

            tieneNumero = true;
            break;

        }
    }

    // Contiene al menos un símbolo especial del conjunto: * ? ! ^ " $

    bool tieneSimboloEspecial = false;
    string especiales = "*?!^\"$";

    for (char c : contrasena){

        if(especiales.find(c) != string::npos){

            tieneSimboloEspecial = true;
            break;

        }
    }

    // 6. No contiene espacios en blanco

    bool TieneEspacios = false;

    for (char c : contrasena){

        if(isspace(c)){

            TieneEspacios = true;
            break;

        }
    }

    // ❌ No debe contener la palabra "GIT" (en mayúsculas o minúsculas)

    bool tieneGit = false;

    string copiaContrasena = contrasena;

    transform(copiaContrasena.begin(), copiaContrasena.end(), copiaContrasena.begin(), ::toupper);

    if(copiaContrasena.find("GIT") != string::npos){

        tieneGit = true;
        

    }

    //No debe empezar con un dígito (isdigit(contrasena[0]))

    bool empiezaConNumero = isdigit(contrasena[0]);

    // No debe terminar con un dígito (isdigit(contrasena.back()))

    bool terminaConNumero = isdigit(contrasena.back());



    return(mayorQue8 && contieneMayuscula && contieneMinuscula && tieneNumero &&
    tieneSimboloEspecial && !TieneEspacios && !tieneGit && !empiezaConNumero && !terminaConNumero);


}

int main(){

    string contrasena;

    cout << "\nIntroduce la contrasena: ";
    getline(cin, contrasena);

    if(esContrasenaSegura(contrasena)){

        cout << "La contrasena \"" << contrasena << "\" es segura. " << endl;

    }else{

        cout << "La contrasena \"" << contrasena << "\" no es segura. " << endl;

    }

    return 0;


}