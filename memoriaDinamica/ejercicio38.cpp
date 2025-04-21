/*
    Ejercicio: Gestión de Hospitales y Pacientes

    Descripción:
    Crea un programa en C++ que permita gestionar varios hospitales. 
    Cada hospital puede tener múltiples pacientes ingresados. 
    El programa debe permitir al usuario realizar distintas operaciones a través de un menú interactivo:

    1. Registrar hospitales iniciales con sus pacientes.
    2. Añadir un nuevo hospital con sus pacientes.
    3. Mostrar todos los hospitales y sus pacientes.
    4. Buscar pacientes por enfermedad.
    0. Salir del programa (liberando toda la memoria dinámica usada).

    Cada hospital incluye:
    - Nombre del hospital.
    - Ciudad en la que se encuentra.
    - Lista dinámica de pacientes.
    - Cantidad de pacientes registrados.

    Cada paciente incluye:
    - Nombre del paciente.
    - Edad.
    - Enfermedad diagnosticada.
    - Número de habitación asignada.

    El programa debe hacer uso de:
    - Estructuras anidadas.
    - Memoria dinámica para arrays de hospitales y pacientes.
    - Funciones separadas para cada acción del menú.
    - Liberación de memoria al finalizar.

    Objetivo:
    Practicar estructuras anidadas, lógica de menús, manejo de memoria dinámica,
    y pasar variables por referencia en C++.
*/


#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
    string nombrePaciente;
    int edadPaciente;
    string enfermedadDiagnosticada;
    int numeroHabitacion;

};

struct Hospital
{
    string nombreHospital;
    string ciudadHospital;

    Paciente* pacientes;
    int cantidadPacientes;

};

void registrarHospitales(Hospital*& hospitales, int& cantidad){

    cout << "\n¿Cuantos hospitales deseas añadir? ";
    cin >> cantidad;

    hospitales = new Hospital[cantidad];
    cin.ignore();

    for (int i = 0; i < cantidad; i++){

        cout << "\nHospital " << i + 1 << ": " << endl;

        cout << "Nombre del hospital: ";
        getline(cin, hospitales[i].nombreHospital);

        cout << "Ciudad: ";
        getline(cin, hospitales[i].ciudadHospital);

        cout << "¿Cuantos pacientes vas a introducir? ";
        cin >> hospitales[i].cantidadPacientes;
        cin.ignore();

        hospitales[i].pacientes = new Paciente[hospitales[i].cantidadPacientes];

        for (int j = 0; j < hospitales[i].cantidadPacientes; j++){

            cout << "\nPaciente " << j + 1 << ": " << endl;

            cout << "Nombre del paciente: ";
            getline(cin, hospitales[i].pacientes[j].nombrePaciente);

            cout << "Edad: ";
            cin >> hospitales[i].pacientes[j].edadPaciente;
            cin.ignore();

            cout << "Enfermedad del paciente: ";
            getline(cin, hospitales[i].pacientes[j].enfermedadDiagnosticada);

            cout << "Numero de habitacion: ";
            cin >> hospitales[i].pacientes[j].numeroHabitacion;

            cin.ignore();
        }
    }

    
}

void agregarNuevoHospital(Hospital*& hospitales, int& cantidad) {
    char opcion;

    do {
        cout << "\n¿Deseas añadir un nuevo hospital? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S') {
            Hospital* nuevoArray = new Hospital[cantidad + 1];

            for (int i = 0; i < cantidad; i++) {
                nuevoArray[i] = hospitales[i];
            }

            cout << "\nNombre del hospital: ";
            getline(cin, nuevoArray[cantidad].nombreHospital);

            cout << "Ciudad: ";
            getline(cin, nuevoArray[cantidad].ciudadHospital);

            cout << "¿Cuántos pacientes deseas añadir? ";
            cin >> nuevoArray[cantidad].cantidadPacientes;
            cin.ignore();

            nuevoArray[cantidad].pacientes = new Paciente[nuevoArray[cantidad].cantidadPacientes];

            for (int j = 0; j < nuevoArray[cantidad].cantidadPacientes; j++) {
                cout << "\nPaciente " << j + 1 << ":" << endl;

                cout << "Nombre del paciente: ";
                getline(cin, nuevoArray[cantidad].pacientes[j].nombrePaciente);

                cout << "Edad: ";
                cin >> nuevoArray[cantidad].pacientes[j].edadPaciente;
                cin.ignore();

                cout << "Enfermedad: ";
                getline(cin, nuevoArray[cantidad].pacientes[j].enfermedadDiagnosticada);

                cout << "Número de habitación: ";
                cin >> nuevoArray[cantidad].pacientes[j].numeroHabitacion;
                cin.ignore();
            }

            delete[] hospitales;
            hospitales = nuevoArray;
            cantidad++; // ¡aquí se actualiza correctamente!
        }

    } while (opcion == 's' || opcion == 'S');
}


void mostrarHospitales(Hospital* hospitales, int cantidad){

    cout << "\nRegistro de todos los hospitales y sus pacientes. " << endl;

    for (int i = 0; i < cantidad; i++){

        cout << "\nHospital " << i + 1 << ": " << endl;

        cout << "Nombre del hospital: " << hospitales[i].nombreHospital << endl;
        cout << "Ciudad: " << hospitales[i].ciudadHospital << endl;

        cout << "En el hospital " << hospitales[i].nombreHospital <<  " hay los siguientes pacientes: " << endl;

        for (int j = 0; j < hospitales[i].cantidadPacientes; j++){

            cout << "\nPaciente " << j + 1 << ": " << endl;

            cout << "Nombre del paciente: " << hospitales[i].pacientes[j].nombrePaciente << endl;
            cout << "Edad: " << hospitales[i].pacientes[j].edadPaciente << endl;
            cout << "Enfermedad: " << hospitales[i].pacientes[j].enfermedadDiagnosticada << endl;
            cout << "Numero de habitacion: " << hospitales[i].pacientes[j].numeroHabitacion << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
}

void buscarPacientePorEnfermedad(Hospital* hospitales, int cantidad){

    string enfermedadBuscada;
    cin.ignore();

    cout << "\nIntroduce la enfermedad para encontrar a los pacientes: ";
    getline(cin, enfermedadBuscada);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++){
        for (int j = 0; j < hospitales[i].cantidadPacientes; j++){

            if (enfermedadBuscada == hospitales[i].pacientes[j].enfermedadDiagnosticada){

                encontrado = true;

                cout << "\nPaciente " << j + 1 << endl;

                cout << "Nombre del paciente: " << hospitales[i].pacientes[j].nombrePaciente << endl;
                cout << "Hospital: " << hospitales[i].nombreHospital << endl;
                cout << "Numero de habitacion: " << hospitales[i].pacientes[j].numeroHabitacion << endl;

            }
        }

        
    }
    if (!encontrado){

        cout << "No existe ningun paciente con la enfermedad " << enfermedadBuscada << endl;
    }
}

void liberarMemoria(Hospital*& hospitales, int& cantidad){

    for (int i = 0; i < cantidad; i++){

        delete[] hospitales[i].pacientes;

    }
    delete[] hospitales;
    hospitales = nullptr;
    cantidad = 0;

}

int main() {
    // Puntero al array dinámico de hospitales
    Hospital* hospitales = nullptr;

    // Cantidad actual de hospitales registrados
    int cantidad = 0;

    // Opción seleccionada por el usuario en el menú
    int opcion;

    // Bucle principal del programa con menú interactivo
    do {
        // Mostramos el menú al usuario
        cout << "\n===== MENÚ DE GESTIÓN DE HOSPITALES =====" << endl;
        cout << "1. Registrar hospitales iniciales" << endl;
        cout << "2. Añadir un nuevo hospital" << endl;
        cout << "3. Mostrar todos los hospitales y pacientes" << endl;
        cout << "4. Buscar pacientes por enfermedad" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Ejecutamos la opción elegida por el usuario
        switch (opcion) {
            case 1:
                // Registrar hospitales desde cero
                registrarHospitales(hospitales, cantidad);
                break;

            case 2:
                // Agregar un nuevo hospital al array existente
                agregarNuevoHospital(hospitales, cantidad);
                break;

            case 3:
                // Mostrar todos los hospitales y sus pacientes
                mostrarHospitales(hospitales, cantidad);
                break;

            case 4:
                // Buscar pacientes por el nombre de su enfermedad
                buscarPacientePorEnfermedad(hospitales, cantidad);
                break;

            case 0:
                // Salir del programa y liberar toda la memoria usada
                liberarMemoria(hospitales, cantidad);
                cout << "\nMemoria liberada correctamente. ¡Hasta pronto!\n";
                break;

            default:
                // Opción no válida
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 0); // El bucle se repite hasta que el usuario elija salir

    return 0; // Fin del programa
}
