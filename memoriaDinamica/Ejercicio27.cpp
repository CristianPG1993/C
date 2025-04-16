/*
==========================================================================
🏢 EJERCICIO 10 - GESTIÓN DE EMPRESAS Y SUS EMPLEADOS
==========================================================================

1. Crea una estructura `Empleado` con:
   - nombre (string)
   - puesto (string)
   - salario (float)

2. Crea una estructura `Empresa` con:
   - nombreEmpresa (string)
   - sector (string)
   - un array dinámico de `Empleado`
   - un entero que indique cuántos empleados tiene

3. Pide cuántas empresas se van a registrar.
4. Para cada empresa, pide:
   - nombre
   - sector
   - cantidad de empleados
   - y para cada empleado, pide su nombre, puesto y salario

5. Guarda todo en un array dinámico de `Empresa`.
6. Muestra un informe con todas las empresas y sus empleados.

🎯 Objetivo: seguir reforzando arrays dinámicos y estructuras anidadas
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura que representa un empleado
struct Empleado {
    string nombre;
    string puesto;
    float salario;
};

// Estructura que representa una empresa con empleados
struct Empresa {
    string nombreEmpresa;
    string sector;
    Empleado* empleados;     // Array dinámico de empleados
    int cantidadEmpleados;   // Número de empleados
};

int main() {
    int cantidad;

    // Pedimos la cantidad de empresas a registrar
    cout << "¿Cuántas empresas deseas añadir?" << endl;
    cin >> cantidad;

    int empresasTotales = cantidad;

    // Reservamos memoria para el array de empresas
    Empresa* empresas = new Empresa[cantidad];
    cin.ignore(); // Limpiar buffer antes de usar getline

    // Recorremos cada empresa para registrar sus datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--------------------------------" << endl;
        cout << "Empresa " << i + 1 << ":" << endl;

        cout << "Nombre: ";
        getline(cin, empresas[i].nombreEmpresa);

        cout << "Sector: ";
        getline(cin, empresas[i].sector);

        cout << "¿Cuántos empleados desea añadir?: ";
        cin >> empresas[i].cantidadEmpleados;
        cin.ignore();

        // Reservamos memoria para los empleados de esta empresa
        empresas[i].empleados = new Empleado[empresas[i].cantidadEmpleados];

        // Recorremos cada empleado para registrar sus datos
        for (int j = 0; j < empresas[i].cantidadEmpleados; j++) {
            cout << "\nEmpleado " << j + 1 << ":" << endl;

            cout << "Nombre del empleado: ";
            getline(cin, empresas[i].empleados[j].nombre);

            cout << "Puesto de empleo: ";
            getline(cin, empresas[i].empleados[j].puesto);

            cout << "Salario: ";
            cin >> empresas[i].empleados[j].salario;
            cin.ignore();
        }
    }



    char opcion;

    do {
        cout << "\n¿Desea añadir otra empresa? (s/n): ";
        cin >> opcion;
        cin.ignore();
    
        if (opcion == 's' || opcion == 'S') {
            // Redimensionamos con +1
            Empresa* nuevoArray = new Empresa[empresasTotales + 1];
    
            // Copiamos las empresas anteriores
            for (int i = 0; i < empresasTotales; i++) {
                nuevoArray[i] = empresas[i];
            }
    
            // Pedimos datos de la nueva empresa
            cout << "\nIntroduce la nueva empresa: " << endl;
    
            cout << "Nombre de la empresa: ";
            getline(cin, nuevoArray[empresasTotales].nombre);
    
            cout << "Sector: ";
            getline(cin, nuevoArray[empresasTotales].sector);
    
            cout << "¿Cuántos empleados desea añadir?: ";
            cin >> nuevoArray[empresasTotales].cantidadEmpleados;
            cin.ignore();
    
            // Creamos array dinámico de empleados
            nuevoArray[empresasTotales].empleados = new Empleado[nuevoArray[empresasTotales].cantidadEmpleados];
    
            // Pedimos datos de empleados
            for (int j = 0; j < nuevoArray[empresasTotales].cantidadEmpleados; j++) {
                cout << "\nEmpleado " << j + 1 << ":" << endl;
    
                cout << "Nombre: ";
                getline(cin, nuevoArray[empresasTotales].empleados[j].nombre);
    
                cout << "Puesto: ";
                getline(cin, nuevoArray[empresasTotales].empleados[j].puesto);
    
                cout << "Salario: ";
                cin >> nuevoArray[empresasTotales].empleados[j].salario;
                cin.ignore();
            }
    
            // Liberamos la memoria anterior
            delete[] empresas;
    
            // Actualizamos puntero
            empresas = nuevoArray;
    
            // Sumamos una empresa más
            empresasTotales++;
        }
    
    } while (opcion == 's' || opcion == 'S');
    

    // Mostramos el informe de empresas y sus empleados
    for (int i = 0; i < cantidad; i++) {
        cout << "\n===================================" << endl;
        cout << "Empresa " << i + 1 << ":" << endl;
        cout << "Nombre de la empresa: " << empresas[i].nombreEmpresa << endl;
        cout << "Sector: " << empresas[i].sector << endl;

        cout << empresas[i].nombreEmpresa << " tiene los siguientes empleados:" << endl;

        for (int j = 0; j < empresas[i].cantidadEmpleados; j++) {
            cout << "\nEmpleado " << j + 1 << ":" << endl;
            cout << "Nombre: " << empresas[i].empleados[j].nombre << endl;
            cout << "Puesto de empleo: " << empresas[i].empleados[j].puesto << endl;
            cout << fixed << setprecision(2);
            cout << "Salario: " << empresas[i].empleados[j].salario << " euros." << endl;
        }
    }

    // Liberamos la memoria de los empleados y empresas
    for (int i = 0; i < cantidad; i++) {
        delete[] empresas[i].empleados;
    }
    delete[] empresas;

    return 0;
}
