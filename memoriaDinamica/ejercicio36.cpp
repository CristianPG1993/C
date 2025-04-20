#include <iostream>
#include <string>
using namespace std;

/*
    Ejercicio: Gestión de Aeropuertos y Vuelos

    Descripción:
    Crea un programa en C++ que permita gestionar un conjunto de aeropuertos. 
    Cada aeropuerto puede tener varios vuelos asociados. El programa ofrece un menú con opciones para:

    1. Registrar aeropuertos iniciales.
    2. Agregar un nuevo aeropuerto.
    3. Mostrar todos los aeropuertos y sus vuelos.
    4. Buscar vuelos por ciudad de destino.
    0. Salir del programa.

    El programa utiliza memoria dinámica para permitir la expansión de datos en tiempo de ejecución
    y libera la memoria reservada al finalizar.
*/

// Estructura que representa un vuelo
struct Vuelo {
    string codigoVuelo;
    string ciudadDestino;
    int duracionVuelo;
};

// Estructura que representa un aeropuerto
struct Aeropuerto {
    string nombreAeropuerto;
    string ciudadAeropuerto;
    Vuelo* vuelos;
    int cantidadVuelos;
};

// Función para registrar varios aeropuertos
void registrarAeropuertos(Aeropuerto*& aeropuertos, int& cantidad) {
    cout << "\n¿Cuántos aeropuertos deseas registrar? ";
    cin >> cantidad;
    cin.ignore();

    aeropuertos = new Aeropuerto[cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "\nAeropuerto " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        getline(cin, aeropuertos[i].nombreAeropuerto);

        cout << "Ciudad: ";
        getline(cin, aeropuertos[i].ciudadAeropuerto);

        cout << "¿Cuántos vuelos deseas introducir? ";
        cin >> aeropuertos[i].cantidadVuelos;
        cin.ignore();

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
}

// Función para añadir un nuevo aeropuerto
void agregarNuevoAeropuerto(Aeropuerto*& aeropuertos, int& cantidad) {
    char opcion;

    do {
        cout << "\n¿Deseas añadir un nuevo aeropuerto? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S') {
            int aeropuertosTotales = cantidad;
            Aeropuerto* nuevoArray = new Aeropuerto[aeropuertosTotales + 1];

            for (int i = 0; i < aeropuertosTotales; i++) {
                nuevoArray[i] = aeropuertos[i];
            }

            cout << "\nNombre del aeropuerto: ";
            getline(cin, nuevoArray[aeropuertosTotales].nombreAeropuerto);

            cout << "Ciudad del aeropuerto: ";
            getline(cin, nuevoArray[aeropuertosTotales].ciudadAeropuerto);

            cout << "¿Cuántos vuelos deseas introducir? ";
            cin >> nuevoArray[aeropuertosTotales].cantidadVuelos;
            cin.ignore();

            nuevoArray[aeropuertosTotales].vuelos = new Vuelo[nuevoArray[aeropuertosTotales].cantidadVuelos];

            for (int j = 0; j < nuevoArray[aeropuertosTotales].cantidadVuelos; j++) {
                cout << "\nCódigo del vuelo: ";
                getline(cin, nuevoArray[aeropuertosTotales].vuelos[j].codigoVuelo);

                cout << "Ciudad de destino: ";
                getline(cin, nuevoArray[aeropuertosTotales].vuelos[j].ciudadDestino);

                cout << "Duración del vuelo (minutos): ";
                cin >> nuevoArray[aeropuertosTotales].vuelos[j].duracionVuelo;
                cin.ignore();
            }

            delete[] aeropuertos;
            aeropuertos = nuevoArray;
            cantidad++;
        }

    } while (opcion == 's' || opcion == 'S');
}

// Función para mostrar todos los aeropuertos y vuelos
void mostrarAeropuertos(Aeropuerto* aeropuertos, int cantidad) {
    cout << "\n3. Todos los aeropuertos y vuelos registrados:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\nAeropuerto " << i + 1 << ":" << endl;
        cout << "Nombre del aeropuerto: " << aeropuertos[i].nombreAeropuerto << endl;
        cout << "Ciudad: " << aeropuertos[i].ciudadAeropuerto << endl;

        cout << "Vuelos registrados en " << aeropuertos[i].nombreAeropuerto << ":" << endl;

        for (int j = 0; j < aeropuertos[i].cantidadVuelos; j++) {
            cout << "\nVuelo " << j + 1 << ":" << endl;
            cout << "Código del vuelo: " << aeropuertos[i].vuelos[j].codigoVuelo << endl;
            cout << "Ciudad de destino: " << aeropuertos[i].vuelos[j].ciudadDestino << endl;
            cout << "Duración del vuelo: " << aeropuertos[i].vuelos[j].duracionVuelo << " minutos" << endl;
        }
    }
}

// Función para buscar vuelos por ciudad destino
void buscarVuelosPorDestino(Aeropuerto* aeropuertos, int cantidad) {
    string buscarCiudad;
    cin.ignore();

    cout << "\nIntroduce el nombre de la ciudad destino del vuelo: ";
    getline(cin, buscarCiudad);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < aeropuertos[i].cantidadVuelos; j++) {
            if (buscarCiudad == aeropuertos[i].vuelos[j].ciudadDestino) {
                encontrado = true;

                cout << "\nAeropuerto " << i + 1 << ":" << endl;
                cout << "Nombre del aeropuerto: " << aeropuertos[i].nombreAeropuerto << endl;
                cout << "Código del vuelo: " << aeropuertos[i].vuelos[j].codigoVuelo << endl;
                cout << "Ciudad de destino: " << aeropuertos[i].vuelos[j].ciudadDestino << endl;
                cout << "Duración del vuelo: " << aeropuertos[i].vuelos[j].duracionVuelo << " minutos" << endl;
            }
        }
    }

    if (!encontrado) {
        cout << "\nNo se ha encontrado ningún vuelo con destino a " << buscarCiudad << "." << endl;
    }
}

// Función para liberar memoria
void liberarMemoria(Aeropuerto*& aeropuertos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        delete[] aeropuertos[i].vuelos;
    }
    delete[] aeropuertos;
    aeropuertos = nullptr; // buena práctica
}

// Función principal
int main() {
    Aeropuerto* aeropuertos = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n===== MENÚ DE GESTIÓN DE AEROPUERTOS =====" << endl;
        cout << "1. Registrar aeropuertos iniciales" << endl;
        cout << "2. Añadir un nuevo aeropuerto" << endl;
        cout << "3. Mostrar todos los aeropuertos y vuelos" << endl;
        cout << "4. Buscar vuelos por ciudad de destino" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarAeropuertos(aeropuertos, cantidad);
                break;
            case 2:
                agregarNuevoAeropuerto(aeropuertos, cantidad);
                break;
            case 3:
                mostrarAeropuertos(aeropuertos, cantidad);
                break;
            case 4:
                buscarVuelosPorDestino(aeropuertos, cantidad);
                break;
            case 0:
                liberarMemoria(aeropuertos, cantidad);
                cout << "\nSaliendo del programa. ¡Hasta pronto!\n";
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}
