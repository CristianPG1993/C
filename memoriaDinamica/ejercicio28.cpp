/*
==========================================================================
🏥 RETO GUIADO - GESTIÓN DE CLÍNICAS Y SUS PACIENTES
==========================================================================

1. Estructura `Paciente`:
   - nombre (string)
   - edad (int)
   - motivoConsulta (string)

2. Estructura `Clinica`:
   - nombre (string)
   - ciudad (string)
   - array dinámico de pacientes
   - entero para contar cuántos pacientes tiene

3. Pide al usuario cuántas clínicas desea registrar.
4. Para cada clínica, solicita:
   - su nombre
   - ciudad
   - número de pacientes
   - y para cada paciente: nombre, edad y motivo de consulta

5. Muestra un informe con los datos de todas las clínicas y sus pacientes.

🎯 Objetivo: hacerlo tú paso a paso, con mi ayuda si te atascas.
*/


#include <iostream>
#include <string>
using namespace std;

// Estructura de un paciente
struct Paciente {
    string nombre;
    int edad;
    string motivoConsulta;
};

// Estructura de una clínica
struct Clinica {
    string nombre;
    string ciudad;
    Paciente* pacientes;
    int cantidadPacientes;
};

int main() {
    int cantidad;
    cout << "¿Cuántas clínicas desea introducir?" << endl;
    cin >> cantidad;

    int totalClinicas = cantidad; // Clínica inicial
    Clinica* clinicas = new Clinica[cantidad];
    cin.ignore();

    // Registro de clínicas iniciales
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--------------------------------" << endl;
        cout << "Clínica " << i + 1 << ":" << endl;

        cout << "Nombre: ";
        getline(cin, clinicas[i].nombre);

        cout << "Ciudad: ";
        getline(cin, clinicas[i].ciudad);

        cout << "¿Cuántos pacientes desea ingresar? ";
        cin >> clinicas[i].cantidadPacientes;
        cin.ignore();

        clinicas[i].pacientes = new Paciente[clinicas[i].cantidadPacientes];

        for (int j = 0; j < clinicas[i].cantidadPacientes; j++) {
            cout << "\nPaciente " << j + 1 << ":\n";

            cout << "Nombre: ";
            getline(cin, clinicas[i].pacientes[j].nombre);

            cout << "Edad: ";
            cin >> clinicas[i].pacientes[j].edad;
            cin.ignore();

            cout << "Motivo de la consulta: ";
            getline(cin, clinicas[i].pacientes[j].motivoConsulta);
        }
    }

    // 🔁 Añadir más clínicas dinámicamente
    char opcion;
    do {
        cout << "\n¿Desea añadir otra clínica? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S') {
            // Creamos nuevo array con 1 espacio más
            Clinica* nuevoArray = new Clinica[totalClinicas + 1];

            // Copiamos las clínicas anteriores
            for (int i = 0; i < totalClinicas; i++) {
                nuevoArray[i] = clinicas[i];
            }

            // Pedimos la nueva clínica
            cout << "\nNueva clínica " << totalClinicas + 1 << ":\n";
            cout << "Nombre: ";
            getline(cin, nuevoArray[totalClinicas].nombre);

            cout << "Ciudad: ";
            getline(cin, nuevoArray[totalClinicas].ciudad);

            cout << "¿Cuántos pacientes tiene?: ";
            cin >> nuevoArray[totalClinicas].cantidadPacientes;
            cin.ignore();

            nuevoArray[totalClinicas].pacientes = new Paciente[nuevoArray[totalClinicas].cantidadPacientes];

            for (int j = 0; j < nuevoArray[totalClinicas].cantidadPacientes; j++) {
                cout << "\nPaciente " << j + 1 << ":\n";

                cout << "Nombre: ";
                getline(cin, nuevoArray[totalClinicas].pacientes[j].nombre);

                cout << "Edad: ";
                cin >> nuevoArray[totalClinicas].pacientes[j].edad;
                cin.ignore();

                cout << "Motivo de la consulta: ";
                getline(cin, nuevoArray[totalClinicas].pacientes[j].motivoConsulta);
            }

            // Liberamos el array viejo y actualizamos
            delete[] clinicas;
            clinicas = nuevoArray;
            totalClinicas++;
        }

    } while (opcion == 's' || opcion == 'S');

    // Mostrar informe
    for (int i = 0; i < totalClinicas; i++) {
        cout << "\n==================================" << endl;
        cout << "Clínica " << i + 1 << ":" << endl;
        cout << "Nombre: " << clinicas[i].nombre << endl;
        cout << "Ciudad: " << clinicas[i].ciudad << endl;
        cout << "Tiene " << clinicas[i].cantidadPacientes << " pacientes:\n";

        for (int j = 0; j < clinicas[i].cantidadPacientes; j++) {
            cout << "\nPaciente " << j + 1 << ":\n";
            cout << "Nombre: " << clinicas[i].pacientes[j].nombre << endl;
            cout << "Edad: " << clinicas[i].pacientes[j].edad << endl;
            cout << "Motivo de consulta: " << clinicas[i].pacientes[j].motivoConsulta << endl;
        }
    }

    // Liberar memoria
    for (int i = 0; i < totalClinicas; i++) {
        delete[] clinicas[i].pacientes;
    }
    delete[] clinicas;

    return 0;
}
