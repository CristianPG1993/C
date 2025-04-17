/*
==============================================
🍽️ ENUNCIADO - GESTIÓN DE RESTAURANTES Y MENÚS
==============================================

Crea un programa en C++ que permita gestionar restaurantes y los platos de su menú.

Cada restaurante debe tener:
- Nombre del restaurante (string)
- Ciudad (string)
- Cantidad de platos (int)
- Un array dinámico de platos

Cada plato debe tener:
- Nombre del plato (string)
- Precio (float)

El programa debe permitir:

1. Registrar una lista inicial de restaurantes y sus platos.
2. Preguntar al usuario si desea añadir otro restaurante.
3. Si la respuesta es sí, redimensionar dinámicamente el array de restaurantes y permitir añadir el nuevo restaurante y sus platos.
4. Al finalizar, mostrar un informe de todos los restaurantes registrados y los datos de sus platos.

Objetivo: reforzar el uso de arrays dinámicos, estructuras anidadas y redimensionamiento manual de memoria en C++.
*/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Plato
{
    string nombre;
    float precio;

};


struct Restaurante
{
    string nombre;
    string ciudad;

    Plato* platos;
    int cantidadPlatos;


};

int main(){

    int cantidad;

    cout << "\n¿Cuantos restaurantes deseas añadir?" << endl;
    cin >> cantidad;

    int restaurantesTotales = cantidad;

    Restaurante* restaurantes = new Restaurante[cantidad];
    cin.ignore();

    for (int i = 0; i < cantidad; i++){

        cout << "\nRestaurante " << i + 1 << ": " << endl;

        cout << "Introduce el nombre del restaurante: ";
        getline(cin, restaurantes[i].nombre);

        cout << "Introduce la ciudad: ";
        getline(cin, restaurantes[i].ciudad);

        cout << "¿Cuantos platos desea introducir?: ";
        cin >> restaurantes[i].cantidadPlatos;

        cin.ignore();

        restaurantes[i].platos = new Plato[restaurantes[i].cantidadPlatos];

        for (int j = 0; j < restaurantes[i].cantidadPlatos; j++){

            cout << "\nPlato " << j + 1 << ": " << endl;

            cout << "Introduce el nombre del plato: ";
            getline(cin, restaurantes[i].platos[j].nombre);

            cout << "Introduce su precio: ";
            cin >> restaurantes[i].platos[j].precio;

            cin.ignore();

        }
    }

    char opcion;

    do
    {

        cout << "\nDesea introducir un nuevo restaurante? (s/n): " << endl;
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S'){

            Restaurante* nuevoArray = new Restaurante[restaurantesTotales + 1];

            for (int i = 0; i < restaurantesTotales; i++){

                nuevoArray[i] = restaurantes[i];

            }

            cout <<"\nIntroduce el nombre del nuevo restaurante: ";
            getline(cin, nuevoArray[restaurantesTotales].nombre);

            cout << "Introduce la ciudad: ";
            getline(cin, nuevoArray[restaurantesTotales].ciudad);

            cout << "¿Cuantos platos deseas introducir?: ";
            cin >> nuevoArray[restaurantesTotales].cantidadPlatos;

            cin.ignore();

            nuevoArray[restaurantesTotales].platos = new Plato[nuevoArray[restaurantesTotales].cantidadPlatos];
            
            

            for (int j = 0; j < nuevoArray[restaurantesTotales].cantidadPlatos; j++){

                cout << "\nPlato " << j + 1 << ": " << endl;
                cout << "Nombre del plato: ";
                getline(cin, nuevoArray[restaurantesTotales].platos[j].nombre);

                cout << "Precio: ";
                cin >> nuevoArray[restaurantesTotales].platos[j].precio;
                cin.ignore();

            }

            delete [] restaurantes;

            restaurantes = nuevoArray;

            restaurantesTotales++;

        }
        
        
    } while (opcion == 's' || opcion == 'S');


    for (int i = 0; i < restaurantesTotales; i++){

        cout << "\nRestaurante " << i + 1 << ": " << endl;

        cout << "Nombre: " << restaurantes[i].nombre << endl;
        cout << "Ciudad:" << restaurantes[i].ciudad << endl;

        cout << "Los platos del restaurante " << restaurantes[i].nombre << " son: " << endl;

        for (int j = 0; j < restaurantes[i].cantidadPlatos; j++){

            cout << "\nPlato " << j + 1 << ": " << endl;
            
            cout << "Nombre: " << restaurantes[i].platos[j].nombre << endl;
            cout << "Precio: " << restaurantes[i].platos[j].precio << endl;

        }
    }

    for (int i = 0; i < restaurantesTotales; i++){

        delete [] restaurantes[i].platos;

    }

    delete [] restaurantes;

    return 0;

    
}
