/*
    Ejercicio: Gestión de Puertos y Barcos

    Descripción:
    Crea un programa en C++ que permita gestionar varios puertos. 
    Cada puerto puede tener varios barcos registrados. El programa debe permitir al usuario realizar las siguientes acciones mediante un menú interactivo:

    1. Registrar una lista inicial de puertos y sus barcos.
    2. Añadir un nuevo puerto con sus barcos.
    3. Mostrar todos los puertos y los barcos registrados.
    4. Buscar todos los barcos con destino a una ciudad específica.
    0. Salir del programa (liberando toda la memoria).

    Cada puerto incluye:
    - Nombre del puerto.
    - Ciudad donde se ubica.
    - Lista dinámica de barcos.
    - Cantidad de barcos registrados.

    Cada barco incluye:
    - Nombre del barco.
    - Tipo (por ejemplo: carga, pasajeros, pesca...).
    - Ciudad de destino.
    - Capacidad de personas (enteros).

    El programa debe gestionar memoria dinámica correctamente, usar estructuras anidadas, y estar dividido en funciones separadas para cada opción del menú.
*/


#include <iostream>
#include <string>
using namespace std;

struct Barco
{
    string nombreBarco;
    string tipoCarga;
    string ciudadDestino;
    int cantidadPersonas;

};

struct Puerto
{
    string nombrePuerto;
    string ciudadPuerto;

    Barco* barcos;
    int cantidadBarcos;

};

void registrarPuertos(Puerto*& puertos, int& cantidad){

    cout << "\n¿Cuantos puertos deseas añadir? ";
    cin >> cantidad;

    puertos = new Puerto[cantidad];
    cin.ignore();

    for (int i = 0; i < cantidad; i++){

        cout << "\nPuerto " << i + 1 << ": " << endl;

        cout << "Nombre del puerto: ";
        getline(cin, puertos[i].nombrePuerto);

        cout << "Ciudad del puerto: ";
        getline(cin, puertos[i].ciudadPuerto);

        cout << "¿Cuantos barcos deseas introducir? ";
        cin >> puertos[i].cantidadBarcos;
        cin.ignore();

        puertos[i].barcos = new Barco[puertos[i].cantidadBarcos];

        for (int j = 0; j < puertos[i].cantidadBarcos; j++){

            cout << "\nBarco " << j + 1 << ": " << endl;

            cout << "Nombre: ";
            getline(cin, puertos[i].barcos[j].nombreBarco);

            cout << "Tipo de barco: ";
            getline(cin, puertos[i].barcos[j].tipoCarga);

            cout << "Ciudad destino: ";
            getline(cin, puertos[i].barcos[j].ciudadDestino);

            cout << "Pasajeros: ";
            cin >> puertos[i].barcos[j].cantidadPersonas;

            cin.ignore();

        }
    }
}

void mostrarPuertos(Puerto* puertos, int cantidad){

    cout << "\n3. Todos los puertos y barcos registrados:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\nPuerto " << i + 1 << ":" << endl;
        cout << "Nombre del puerto: " << puertos[i].nombrePuerto << endl;
        cout << "Ciudad: " << puertos[i].ciudadPuerto << endl;

        cout << "Barcos registrados en " << puertos[i].nombrePuerto << ":" << endl;

        for (int j = 0; j < puertos[i].cantidadBarcos; j++) {
            cout << "\nBarco " << j + 1 << ":" << endl;
            cout << "Nombre del barco: " << puertos[i].barcos[j].nombreBarco << endl;
            cout << "Ciudad de destino: " << puertos[i].barcos[j].ciudadDestino << endl;
            cout << "Tipo de carga: " << puertos[i].barcos[j].tipoCarga << endl;
            cout << "Numero de pasajeros: " << puertos[i].barcos[j].cantidadPersonas << endl;
        }
    }
}

void registrarNuevoPuerto(Puerto*& puertos, int& cantidad){

    char opcion;

    do
    {
        cout << "\n¿Deseas añadir un nuevo puerto? ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S')
        {
            int puertosTotales = cantidad;

            Puerto* nuevoArray = new Puerto[puertosTotales + 1];

            for (int i = 0; i < puertosTotales; i++){

                nuevoArray[i] = puertos[i];
            }

            cout << "\nIntroduce el nombre del puerto: ";
            getline(cin, nuevoArray[puertosTotales].nombrePuerto);

            cout << "Ciudad del puerto: ";
            getline(cin, nuevoArray[puertosTotales].ciudadPuerto);

            cout << "¿Cuantos barcos deseas introducir? ";
            cin >> nuevoArray[puertosTotales].cantidadBarcos;
            cin.ignore();

            nuevoArray[puertosTotales].barcos = new Barco[nuevoArray[puertosTotales].cantidadBarcos];

            for (int j = 0; j < nuevoArray[puertosTotales].cantidadBarcos; j++){

                cout << "\nBarco " << j + 1 << ": " << endl;

                cout << "Nombre del barco: ";
                getline(cin, nuevoArray[puertosTotales].barcos[j].nombreBarco);

                cout << "Tipo de barco: ";
                getline(cin, nuevoArray[puertosTotales].barcos[j].tipoCarga);

                cout << "Ciudad destino: ";
                getline(cin, nuevoArray[puertosTotales].barcos[j].ciudadDestino);

                cout << "Pasajeros: ";
                cin >> nuevoArray[puertosTotales].barcos[j].cantidadPersonas;
                cin.ignore();
            }

            delete[] puertos;

            puertos = nuevoArray;
            cantidad++;
            
        }
        
    } while (opcion == 's' || opcion == 'S');
    

}

void buscarBarcoPorDestino(Puerto* puertos, int cantidad){

    string buscarCiudad;
    cin.ignore();

    cout << "\nIntroduce la ciudad que desea encontrar como destino del barco: ";
    getline(cin, buscarCiudad);

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++){
        for (int j = 0 ; j < puertos[i].cantidadBarcos; j++){

            if (buscarCiudad == puertos[i].barcos[j].ciudadDestino){
                encontrado = true;

                cout << "\nPuerto " << i + 1 << ":" << endl;
                cout << "Nombre del puerto: " << puertos[i].nombrePuerto << endl;
                cout << "Tipo de carga: " << puertos[i].barcos[j].tipoCarga << endl;
                cout << "Ciudad de destino: " << puertos[i].barcos[j].ciudadDestino << endl;
                cout << "Pasajeros: " << puertos[i].barcos[j].cantidadPersonas << endl;
            }

        }
    }
    if(!encontrado){

        cout << "\nEl destino " << buscarCiudad << " no se encuentra en el registro. " << endl;
    }
}

void liberarMemoria(Puerto*& puertos, int& cantidad){

    for (int i = 0; i < cantidad; i++){

        delete[] puertos[i].barcos;

    }

    delete[] puertos;
    puerto = nullptr;
    cantidad = 0;

}

int main() {
    Puerto* puertos = nullptr;
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n===== MENÚ DE GESTIÓN DE PUERTOS =====" << endl;
        cout << "1. Registrar puertos iniciales" << endl;
        cout << "2. Añadir un nuevo puerto" << endl;
        cout << "3. Mostrar todos los puertos y barcos" << endl;
        cout << "4. Buscar barcos por ciudad de destino" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarPuertos(puertos, cantidad);
                break;

            case 2:
                registrarNuevoPuerto(puertos, cantidad);
                break;

            case 3:
                mostrarPuertos(puertos, cantidad);
                break;

            case 4:
                buscarBarcoPorDestino(puertos, cantidad);
                break;

            case 0:
                liberarMemoria(puertos, cantidad);
                cout << "\nMemoria liberada correctamente. ¡Hasta pronto!\n";
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}


