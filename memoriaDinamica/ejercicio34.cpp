/*
    Programa de registro de universidades

    Este programa permite registrar varias universidades. 
    Cada universidad contiene:

    - Nombre de la universidad
    - Ciudad
    - Varias facultades

    Cada facultad contiene:
    - Nombre de la facultad
    - Número de alumnos

    Funcionalidades:
    1. Pedir al usuario cuántas universidades desea registrar inicialmente.
    2. Para cada universidad, registrar sus facultades.
    3. Permitir al usuario añadir más universidades si lo desea.
    4. Mostrar toda la información registrada al final.
    5. Liberar toda la memoria dinámica utilizada correctamente.
*/


#include <iostream>
#include <string>
using namespace std;

struct Facultad
{
    string nombreFacultad;
    int numeroAlumnos;

};

struct Universidad
{
    string nombreUniversidad;
    string ciudad;

    Facultad* facultades;
    int cantidadFacultades;


};

int main(){

    int cantidad;

    cout << "\n¿Cuantas universidades desea añadir? " << endl;
    cin >> cantidad;

    int universidadesTotales = cantidad;

    Universidad* universidades = new Universidad[cantidad];
    cin.ignore();

    for (int i = 0; i < cantidad; i++){

        cout << "\nUniversidad " << i + 1 << ": " << endl;

        cout << "Nombre: ";
        getline(cin, universidades[i].nombreUniversidad);

        cout << "Ciudad: ";
        getline(cin, universidades[i].ciudad);

        cout << "¿Cuantas facultades deseas añadir? ";
        cin >> universidades[i].cantidadFacultades;

        cin.ignore();

        universidades[i].facultades = new Facultad[universidades[i].cantidadFacultades];

        for (int j = 0; j < universidades[i].cantidadFacultades; j++){

            cout << "\nFacultad " << j + 1 << ": " << endl;

            cout << "Nombre: ";
            getline(cin, universidades[i].facultades[j].nombreFacultad);

            cout << "Introduce el numero de alumnos: ";
            cin >> universidades[i].facultades[j].numeroAlumnos;

            cin.ignore();

        }
    }

    char opcion;

    do
    {
        cout << "\n¿Desea añadir una nueva universidad? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S')
        {
            Universidad* nuevoArray = new Universidad[universidadesTotales + 1];

            for (int i = 0; i < universidadesTotales; i++){

                nuevoArray[i] = universidades[i];

            }

            cout << "\nIntroduce el nombre de la universidad: ";
            getline(cin, nuevoArray[universidadesTotales].nombreUniversidad);

            cout << "Introduce la ciudad: ";
            getline(cin, nuevoArray[universidadesTotales].ciudad);

            cout << "¿Cuantas facultades desea introducir? ";
            cin >> nuevoArray[universidadesTotales].cantidadFacultades;

            nuevoArray[universidadesTotales].facultades = new Facultad[nuevoArray[universidadesTotales].cantidadFacultades];

            cin.ignore();


            for (int j  = 0; j < nuevoArray[universidadesTotales].cantidadFacultades; j++){

                cout << "Nombre de la facultad: ";
                getline(cin, nuevoArray[universidadesTotales].facultades[j].nombreFacultad);

                cout << "Numero de alumnos: ";
                cin >> nuevoArray[universidadesTotales].facultades[j].numeroAlumnos;

                cin.ignore();

            }

            delete[] universidades;

            universidades = nuevoArray;

            universidadesTotales++;

        }
        
    } while (opcion == 's' || opcion == 'S');

    for (int i = 0; i < universidadesTotales; i++){

        cout << "\nUniversidad " << i + 1 << ": " << endl;

        cout << "Nombre de la universidad: " << universidades[i].nombreUniversidad << endl;
        cout << "Ciudad: " << universidades[i].ciudad << endl;

        cout << "La universidad " << universidades[i].nombreUniversidad << " tiene las siguientes facultades: " << endl;

        for (int j = 0; j < universidades[i].cantidadFacultades; j++){

            cout << "\nFacultad " << j + 1 << ": " << endl;

            cout << "Nombre de la facultad: " << universidades[i].facultades[j].nombreFacultad << endl;
            cout << "Numero de alumnos: " << universidades[i].facultades[j].numeroAlumnos << endl;

        }

    }

    for (int i = 0; i <  universidadesTotales; i++){

        delete[] universidades[i].facultades;

    }

    delete [] universidades;

    return 0;
    
}

