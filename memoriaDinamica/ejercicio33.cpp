/*
🦷 Gestión de Clínicas Dentales

Crea un programa en C++ que permita registrar un conjunto de clínicas dentales. 
Cada clínica tiene un nombre, una ciudad y una lista dinámica de pacientes. 
Cada paciente tiene un nombre, edad y tratamiento realizado.

El programa debe:

1. Preguntar al usuario cuántas clínicas desea registrar inicialmente.
2. Para cada clínica, solicitar su información (nombre, ciudad) y los datos de sus pacientes.
3. Después de registrar las clínicas iniciales, preguntar si desea añadir otra clínica.
4. Si el usuario responde que sí, permitir agregar una nueva clínica con sus pacientes,
   redimensionando dinámicamente el array de clínicas.
5. Al final, mostrar toda la información registrada: nombre de la clínica, ciudad 
   y los datos de todos sus pacientes.
6. Liberar correctamente la memoria utilizada antes de finalizar el programa.
*/


#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
    string nombre;
    int edad;
    string tratamientoRealizado;
    
};

struct Clinica
{
    string nombre;
    string ciudad;

    Paciente* pacientes;
    int cantidadPacientes;

};


int main(){

    int cantidad;

    cout << "\nBienvenido al registro de clinicas ";
    cout << "¿Cuantas clinicas deseas registrar? ";
    cin >> cantidad;

    int clinicasTotales = cantidad;

    Clinica* clinicas = new Clinica[cantidad];

    cin.ignore();

    for (int i = 0; i < cantidad; i++){

        cout << "\nClinica " << i + 1 << ": " << endl;

        cout << "Nombre: ";
        getline(cin, clinicas[i].nombre);

        cout << "Ciudad: ";
        getline(cin, clinicas[i].ciudad);

        cout << "¿Cuantos pacientes vas añadir? ";
        cin >> clinicas[i].cantidadPacientes;

        cin.ignore();

        clinicas[i].pacientes = new Paciente[clinicas[i].cantidadPacientes];

        for (int j = 0; j < clinicas[i].cantidadPacientes; j++){

            cout << "\nPaciente " << j + 1 << ": " << endl;

            cout << "Nombre: ";
            getline(cin, clinicas[i].pacientes[j].nombre);

            cout << "Edad: ";
            cin >> clinicas[i].pacientes[j].edad;
            cin.ignore();

            cout << "Tratamiento: ";
            getline(cin, clinicas[i].pacientes[j].tratamientoRealizado);

        }
    }

    char opcion;

    do
    {
        cout << "\nDeseas añadir una nueva clinica? (s/n): ";
        cin >> opcion;

        cin.ignore();

        if (opcion == 's' || opcion == 'S')
        {
            Clinica* nuevoArray = new Clinica[clinicasTotales + 1];

            for (int i = 0; i < clinicasTotales; i++){

                nuevoArray[i] = clinicas[i];

            }

            cout << "\nIntroduce el nombre de la clinica: ";
            getline(cin, nuevoArray[clinicasTotales].nombre);

            cout << "Ciudad: ";
            getline(cin, nuevoArray[clinicasTotales].ciudad);

            cout << "¿Cuantos pacientes deseas introducir? ";
            cin >> nuevoArray[clinicasTotales].cantidadPacientes;

            cin.ignore();

            nuevoArray[clinicasTotales].pacientes = new Paciente[nuevoArray[clinicasTotales].cantidadPacientes];

            for (int j  = 0; j < nuevoArray[clinicasTotales].cantidadPacientes; j++){

                cout << "\nPaciente " << j + 1 << ": " << endl;

                cout << "Nombre: ";
                getline(cin, nuevoArray[clinicasTotales].pacientes[j].nombre);

                cout << "Edad: ";
                cin >> nuevoArray[clinicasTotales].pacientes[j].edad;

                cout << "Tratamiento realizado: ";
                getline(cin, nuevoArray[clinicasTotales].pacientes[j].tratamientoRealizado);

                cin.ignore();

            }

            delete [] clinicas;
            clinicas = nuevoArray;
            clinicasTotales++;


        }
        
    } while (opcion == 's' || opcion == 'S');
    

    for (int i = 0; i < clinicasTotales; i++){

        cout << "\nClinica " << i + 1 << ": " << endl;

        cout << "Nombre: " << clinicas[i].nombre << endl;
        cout << "Ciudad: " << clinicas[i].ciudad << endl;

        cout << "En la clinica " << clinicas[i].nombre << " hay los siguientes pacientes: " << endl;

        for (int j = 0; j < clinicas[i].cantidadPacientes){

            cout << "\nPaciente " << j + 1 << ": " << endl;

            cout << "Nombre: " << clinicas[i].pacientes[j].nombre << endl;
            cout << "Edad: " << clinicas[i].pacientes[j].edad << endl;
            cout << "Tratamiento realicado: " << clinicas[i].pacientes[j].tratamientoRealizado << endl;

            cout << "Historial del paciente " << j + 1 << " finalizado." << endl;

        }
    }

    for (int i = 0; i < clinicasTotales; i++){

        delete[] clinicas[i].pacientes;

    }

    delete [] clinicas;

    return 0;
}

