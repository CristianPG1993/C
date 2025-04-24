/*
Autor: Cristian Paños
Ejercicio: Validación de entrada con getline y control de errores
Descripción:
Este programa solicita al usuario su edad y nombre completo.
Valida que el nombre no esté vacío y no supere cierta longitud.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int edad;
    string nombre;
    const int MAX_LONGITUD = 30;
    


    

    do
    {
        cout << "\nIntroduce la edad: ";
        cin >> edad;
        cin.ignore();

        if (edad < 0 || edad > 120)
        {
            
            cout << "Error: La edad debe de ser entre 0 y 120 años. " << endl;
        }
        

    } while ((edad < 0) || (edad > 120));
    

    do
    {
        cout << "Introduce el nombre: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "Error: El nombre no puede estar vacío." << endl;
        }

        if (nombre.length() > MAX_LONGITUD) {
            
          cout << "Error: El nombre es demasiado largo (max " << MAX_LONGITUD << " caracteres). " << endl;

        }
        

    } while ((nombre.empty()) || (nombre.length() > MAX_LONGITUD));
    
}