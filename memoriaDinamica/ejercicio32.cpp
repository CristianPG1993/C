/*

📘 ENUNCIADO: GESTIÓN DE ZOOLÓGICOS Y ANIMALES

Crea un programa en C++ que permita gestionar múltiples zoológicos. 
Cada zoológico puede tener una cantidad variable de animales, 
y el usuario podrá añadir nuevos zoológicos durante la ejecución.

✅ Cada zoológico debe tener:
- Nombre
- Ciudad
- Lista dinámica de animales

✅ Cada animal debe tener:
- Nombre
- Especie
- Edad

🔁 El programa debe permitir:
1. Registrar varios zoológicos y sus respectivos animales.
2. Preguntar al usuario si desea añadir otro zoológico.
3. Mostrar toda la información registrada de los zoológicos y sus animales.
4. Liberar la memoria dinámica al finalizar.

*/


#include <iostream>
#include <string>
using namespace std;

struct Animal
{
    string nombre;
    string especie;
    int edad;

};

struct Zoologico
{
    string nombre;
    string ciudad;

    Animal* animales;
    int cantidadAnimales;

};

int main(){

    int cantidad;

    cout << "Bienvenido al registro de los zoologicos. " << endl;

    cout << "\n¿Cuantos zoologicos deseas añadir?" << endl;
    cin >> cantidad;

    int zoologicosTotales = cantidad;

    Zoologico* zoologicos = new Zoologico[cantidad];
    cin.ignore();

    for (int i  = 0; i < cantidad; i++){

        cout << "\nZoologico " << i + 1 << ": " << endl;

        cout << "Nombre del zoologico: ";
        getline(cin, zoologicos[i].nombre);

        cout << "Ciudad: ";
        getline(cin, zoologicos[i].ciudad);

        cout << "¿Cuantas especies deseas introducir? ";
        cin >> zoologicos[i].cantidadAnimales;

        cin.ignore();

        zoologicos[i].animales = new Animal[zoologicos[i].cantidadAnimales];

        for (int j = 0; j < zoologicos[i].cantidadAnimales; j++){

            cout << "\nEspecie " << j + 1 << ": " << endl;

            cout << "Nombre del animal: ";
            getline(cin, zoologicos[i].animales[j].nombre);

            cout << "Especie: ";
            getline(cin, zoologicos[i].animales[j].especie);

            cout << "Edad: ";
            cin >> zoologicos[i].animales[j].edad;

            cin.ignore();

        }
    }

    char opcion;

    do
    {
        
        cout << "¿Deseas introducir un nuevo zoologico? (s/n): ";
        cin >> opcion;


        if (opcion == 's' || opcion == 'S'){

            Zoologico* nuevoArray = new Zoologico[zoologicosTotales + 1];

            for (int i = 0; i < zoologicosTotales; i++){

                nuevoArray[i] = zoologicos[i];

            }

            cin.ignore();

            cout << "\nZoologico " << zoologicosTotales + 1 << ": " << endl;

            cout << "Nombre: ";
            getline(cin, nuevoArray[zoologicosTotales].nombre);

            cout << "Ciudad: ";
            getline(cin, nuevoArray[zoologicosTotales].ciudad);

            cout << "¿Cuantos especies deseas introducir? ";
            cin >> nuevoArray[zoologicosTotales].cantidadAnimales;

            cin.ignore();

            nuevoArray[zoologicosTotales].animales = new Animal[nuevoArray[zoologicosTotales].cantidadAnimales];

            for (int j = 0; j < nuevoArray[zoologicosTotales].cantidadAnimales; j++){

                cout << "\nAnimal " << j + 1 << ": " << endl;

                cout << "Nombre: ";
                getline(cin, nuevoArray[zoologicosTotales].animales[j].nombre);

                cout << "Especie: ";
                getline(cin, nuevoArray[zoologicosTotales].animales[j].especie);

                cout  << "Edad: ";
                cin >> nuevoArray[zoologicosTotales].animales[j].edad;

                cin.ignore();

                

            }

            delete [] zoologicos;

                zoologicos = nuevoArray;

                zoologicosTotales++;

        }
    } while (opcion == 's' || opcion == 'S');
    

    for (int i = 0; i < zoologicosTotales; i++){

        cout << "\nZoologico " << i + 1 << ": " << endl;

        cout << "Nombre : " << zoologicos[i].nombre << endl;
        cout << "Ciudad: " << zoologicos[i].ciudad << endl;

        cout << "El zoologico " << zoologicos[i].nombre << " tiene los siguientes animales: " << endl;

        for (int j = 0; j < zoologicos[i].cantidadAnimales ; j++){

            cout << "\nEspecie " << j + 1 << ": " << endl;

            cout << "Nombre: " << zoologicos[i].animales[j].nombre << endl;
            cout << "Especie: " << zoologicos[i].animales[j].especie << endl;
            cout << "Edad: " << zoologicos[i].animales[j].edad << endl;

        }
    }

    for (int i = 0; i < zoologicosTotales; i++){

        delete [] zoologicos[i].animales;
    }

    delete [] zoologicos;

    return 0;

}

