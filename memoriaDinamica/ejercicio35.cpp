/*
--------------------------------------------------------
   Enunciado - Gestión de Aeropuertos y Vuelos
--------------------------------------------------------

Crea un programa en C++ que permita registrar información 
sobre varios aeropuertos y sus vuelos.

Cada aeropuerto debe contener:
- Nombre del aeropuerto
- Ciudad
- Una lista dinámica de vuelos

Cada vuelo debe contener:
- Código del vuelo (ej. IB345)
- Destino del vuelo (ej. París)
- Duración en minutos del vuelo

El programa debe:

1. Preguntar al usuario cuántos aeropuertos desea registrar inicialmente.
2. Permitir introducir los datos de cada aeropuerto y los vuelos que tiene.
3. Preguntar si se desea añadir un nuevo aeropuerto.
4. Si la respuesta es afirmativa, ampliar dinámicamente el array de aeropuertos.
5. Al finalizar, mostrar toda la información registrada de los aeropuertos y sus vuelos.
6. Liberar toda la memoria reservada dinámicamente.

*/


#include <iostream>
#include <string>
using namespace std;

// Estructura que representa un vuelo
struct Vuelo {
    string codigoVuelo;
    string ciudadDestino;
    int duracionVuelo;
};

// Estructura que representa un aeropuerto, que tiene un array dinámico de vuelos
struct Aeropuerto {
    string nombreAeropuerto;
    string ciudadAeropuerto;

    Vuelo* vuelos;
    int cantidadVuelos;
};

int main() {
    int cantidad;

    cout << "\n¿Cuántos aeropuertos deseas introducir? ";
    cin >> cantidad;

    int aeropuertosTotales = cantidad; // Variable para llevar el total al crecer el array

    // Array dinámico de aeropuertos
    Aeropuerto* aeropuertos = new Aeropuerto[cantidad];
    cin.ignore();

    // Registro inicial de aeropuertos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nAeropuerto " << i + 1 << ":" << endl;

        cout << "Nombre del aeropuerto: ";
        getline(cin, aeropuertos[i].nombreAeropuerto);

        cout << "Ciudad del aeropuerto: ";
        getline(cin, aeropuertos[i].ciudadAeropuerto);

        cout << "¿Cuántos vuelos deseas introducir? ";
        cin >> aeropuertos[i].cantidadVuelos;
        cin.ignore();

        // Crear array dinámico de vuelos para ese aeropuerto
        aeropuertos[i].vuelos = new Vuelo[aeropuertos[i].cantidadVuelos];

        for (int j = 0; j < aeropuertos[i].cantidadVuelos; j++) {
            cout << "\nVuelo " << j + 1 << ":" << endl;

            cout << "Código del vuelo: ";
            getline(cin, aeropuertos[i].vuelos[j].codigoVuelo);

            cout << "Ciudad de destino: ";
            getline(cin, aeropuertos[i].vuelos[j].ciudadDestino);

            cout << "Duración del vuelo (minutos): ";
            cin >> aeropuertos[i].vuelos[j].duracionVuelo;
            cin.ignore();
        }
    }

    // Permite al usuario añadir nuevos aeropuertos si desea
    char opcion;
    do {
        cout << "\n¿Deseas añadir un nuevo aeropuerto? (s/n): ";
        cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            Aeropuerto* nuevoArray = new Aeropuerto[aeropuertosTotales + 1];

            // Copiamos los aeropuertos existentes al nuevo array
            for (int i = 0; i < aeropuertosTotales; i++) {
                nuevoArray[i] = aeropuertos[i];
            }

            cin.ignore();

            // Pedimos datos para el nuevo aeropuerto
            cout << "\nIntroduce el nombre del aeropuerto: ";
            getline(cin, nuevoArray[aeropuertosTotales].nombreAeropuerto);

            cout << "Introduce la ciudad: ";
            getline(cin, nuevoArray[aeropuertosTotales].ciudadAeropuerto);

            cout << "¿Cuántos vuelos deseas introducir? ";
            cin >> nuevoArray[aeropuertosTotales].cantidadVuelos;
            cin.ignore();

            // Creamos el array dinámico de vuelos para este nuevo aeropuerto
            nuevoArray[aeropuertosTotales].vuelos = new Vuelo[nuevoArray[aeropuertosTotales].cantidadVuelos];

            for (int j = 0; j < nuevoArray[aeropuertosTotales].cantidadVuelos; j++) {
                cout << "\nVuelo " << j + 1 << ":" << endl;

                cout << "Código del vuelo: ";
                getline(cin, nuevoArray[aeropuertosTotales].vuelos[j].codigoVuelo);

                cout << "Ciudad de destino: ";
                getline(cin, nuevoArray[aeropuertosTotales].vuelos[j].ciudadDestino);

                cout << "Duración del vuelo (minutos): ";
                cin >> nuevoArray[aeropuertosTotales].vuelos[j].duracionVuelo;
                cin.ignore();
            }

            // Liberamos memoria del array antiguo y actualizamos puntero
            delete[] aeropuertos;
            aeropuertos = nuevoArray;
            aeropuertosTotales++;
        }

    } while (opcion == 's' || opcion == 'S');

    // Mostramos toda la información registrada
    for (int i = 0; i < aeropuertosTotales; i++) {
        cout << "\nAeropuerto " << i + 1 << ":" << endl;
        cout << "Nombre del aeropuerto: " << aeropuertos[i].nombreAeropuerto << endl;
        cout << "Ciudad del aeropuerto: " << aeropuertos[i].ciudadAeropuerto << endl;

        cout << "Vuelos registrados en " << aeropuertos[i].nombreAeropuerto << ":" << endl;

        for (int j = 0; j < aeropuertos[i].cantidadVuelos; j++) {
            cout << "\nVuelo " << j + 1 << ":" << endl;
            cout << "Código: " << aeropuertos[i].vuelos[j].codigoVuelo << endl;
            cout << "Destino: " << aeropuertos[i].vuelos[j].ciudadDestino << endl;
            cout << "Duración: " << aeropuertos[i].vuelos[j].duracionVuelo << " minutos" << endl;
        }
    }

    // Liberamos la memoria de cada array de vuelos
    for (int i = 0; i < aeropuertosTotales; i++) {
        delete[] aeropuertos[i].vuelos;
    }

    // Liberamos la memoria del array principal
    delete[] aeropuertos;

    return 0;
}

