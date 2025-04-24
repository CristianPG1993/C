/*
Autor: Cristian Paños
Ejercicio: Problema al usar getline() después de cin
Descripción:
Este programa demuestra cómo getline() puede fallar si se usa justo después de cin >> 
sin limpiar el buffer de entrada con cin.ignore().
*/

#include <iostream>
#include <string>
using namespace std;

int main(){

    int edad;
    string nombre;

    cout << "\nIntroduce la edad: ";
    cin >> edad;

    cout << "\nIntroduce el nombre: ";
    getline(cin, nombre);


    cout << "\nEdad: " << edad << endl;
    cout << "\nNombre: " << nombre << endl;

    return 0;


}